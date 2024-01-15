#include<iostream>
#include<list>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);


    // Algorithm starts
    key[1] = 0;
    
    for(int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        
        // Finding u (which is minimum in key vector)
        for(int v = 1; v <= n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adjacent nodes
        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main()
{
    
}