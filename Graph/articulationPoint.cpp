#include<iostream>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, vector<int> &low, vector<int> &disc, int parent, unordered_map<int, bool> &visited, 
unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for(auto nbr : adj[node])
    {
        if(nbr == parent)
        {
            continue;
        }
        if(!visited[nbr])
        {
            dfs(nbr, low, disc, node, visited, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            // node already visited and is not a parent 
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}
int main()
{
    vector<pair<int, int> > edges;
    unordered_map<int, list<int> > adj;
    
    int n = 5;
    int e = 5;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(3,4));

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> visited;
    vector<int> ap(n, 0);

    for(int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, low, disc, -1, visited, adj, ap, timer);
        }
    }
    // print ap
    cout << "articulation points are : " << endl;
    for(int i = 0; i < n; i++)
    {
        if(ap[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

}