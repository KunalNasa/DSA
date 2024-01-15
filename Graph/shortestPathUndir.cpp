#include<iostream>
#include<unordered_map>
#include <queue>
#include <list>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, list<int> > adj;
	for(int i = 0; i < m; i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(s);
	unordered_map<int, bool> visited;
	visited[s] = true;
	unordered_map<int, int> parent;
	parent[s] = -1;

	while(!q.empty())
	{
		int front = q.front();
		q.pop();

		for(auto i : adj[front])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i] = true;
				parent[i] = front;
			}
		}
	}
	
	vector<int> ans;
	ans.push_back(t);
	int curr = t;
	while(parent[curr] != s)
	{
		curr = parent[curr];
		ans.push_back(curr);
	}
	ans.push_back(s);
	reverse(ans.begin(), ans.end());
	return ans;
	
}

int main()
{
    
}