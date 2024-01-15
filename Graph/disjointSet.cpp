#include<iostream>

using namespace std;
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
  for(int i = 0; i < n; i++)
  {
    parent[i] = i;
    rank[i] = 0;
  }
}

int findParent(vector<int> &parent, int node)
{
  if(parent[node] == node)
  {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v])
  {
    parent[u] = v;
  }
  else if(rank[u] > rank[v])
  {
    parent[v] = u;
  }
  else
  {
    parent[v] = u;
    rank[u]++;
    
  }


}
void minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

}

int main()
{
    
}