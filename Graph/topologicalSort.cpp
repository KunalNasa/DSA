#include<iostream>
#include <unordered_map>
#include <list>
#include<stack>
using namespace std;

void topsort(int node, vector<bool> &visited, stack<int> &st,
 unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            topsort(neighbour, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(int i =0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v,0);
    stack<int> st;
    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            topsort(i, visited, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    
}
int main()
{
    
}