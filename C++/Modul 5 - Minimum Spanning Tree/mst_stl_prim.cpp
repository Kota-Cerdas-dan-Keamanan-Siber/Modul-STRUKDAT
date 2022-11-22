// Source code : https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
// STL implementation of Prim's algorithm for MST
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int>> adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void primMST(vector<pair<int, int>> adj[], int V)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    int src = 0; // Mulai dari node 0

    vector<int> key(V, INF);

    // Menyimpan MST
    vector<int> parent(V, -1);

    // Untuk tanda node termasuk dalam MST atau tidak
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u] == true)
        {
            continue;
        }

        inMST[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (inMST[v] == false && key[v] > weight)
            {
                // Update nilai key dari v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    printf("edge \t weight\n");
    for (int i = 1; i < V; ++i)
        printf("%d - %d \t %d\n", parent[i], i, key[i]);
}

int main()
{
    int V = 9;
    vector<iPair> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    primMST(adj, V);

    return 0;
}