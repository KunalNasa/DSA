#include<iostream>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    // push all elements with indegree 0
    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    // do bfs
    vector<int> ans;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        // neighbour indegree update
        for(auto neighbour:adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;

}
int main()
{
    
}