#include<iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st,
 unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for(auto nbr : adj[node])
    {
        if(!visited[nbr])
        {
            dfs(nbr, visited, st, adj);
        }
    }
    st.push(node);
}
void revDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transAdj)
{
    visited[node] = true;
    for(auto nbr : transAdj[node])
    {
        if(!visited[nbr])
        {
            revDfs(nbr, visited, transAdj);
        }
    }

}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    // step 1 : topo sort
    stack<int> st;
    unordered_map<int, bool> visited;

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    unordered_map<int, list<int> > transAdj;
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
        for(auto nbr : adj[i])
        {
            transAdj[nbr].push_back(i);
        }
    }

    // dfs call using above ordering
    int count = 0;
    while(!st.empty())
    {
        int top = st.top();
        st.pop();
        if(!visited[top])
        {
            count++;
        }
        revDfs(top, visited, transAdj);
    }
    return count;
}
int main()
{
    
}