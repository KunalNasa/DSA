#include <iostream>
#include <list>
#include <unordered_map> 
#include <queue>
using namespace std;

bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited,
                unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycleDFS(i, -1, visited, adj);
            // bool ans = isCycleBFS(i, visited, adj);

            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
}