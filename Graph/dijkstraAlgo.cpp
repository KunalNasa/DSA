#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);
    for(int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    set<pair<int,int>> s;
    dist[source] = 0;
    s.insert(make_pair(0,0));

    while(!s.empty())
    {
        //fetch top record
        auto top = *(s.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        // remove top record now
        s.erase(s.begin());

        // traverse neighbours of top node
        for(auto neighbour : adj[topNode])
        {
            if(nodeDist + neighbour.second < dist[neighbour.first])
            {
                auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));
                // if record found then erase it
                if(record != s.end())
                {
                    s.erase(record);
                }

                // distance update
                dist[neighbour.first] = nodeDist + neighbour.second;

                // record push in set
                s.insert(make_pair(dist[neighbour.first],neighbour.first));

            }
        }

    }
    return dist;
}

int main()
{
    
}