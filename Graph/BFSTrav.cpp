#include<iostream>
#include<queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    int node = 0;
    vector<int> ans;
    vector<bool> visited(n, 0);

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i:adj[front])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}
int main()
{
    
}