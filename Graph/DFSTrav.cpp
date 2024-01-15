#include<iostream>
#include<queue>
using namespace std;
#include<list>
void prepareList(vector<vector<int>> &edges, unordered_map<int, list<int> > &adjList)
{
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void dfs(int node, unordered_map<int, bool> &isVisited,
 unordered_map<int, list<int> > &adjList, vector<int> &component)
 {
     component.push_back(node);
     isVisited[node] = true;

     for(auto i:adjList[node])
     {
         if(!isVisited[i])
         {
            dfs(i, isVisited, adjList, component);
         }
     }
 }
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int> > ans;
    unordered_map<int, bool> isVisited;
    unordered_map<int, list<int> > adjList;

    prepareList(edges, adjList);

    for(int i = 0; i < V; i++)
    {
        if(!isVisited[i])
        {
            vector<int> component;
            dfs(i, isVisited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;

}
int main()
{
    
}