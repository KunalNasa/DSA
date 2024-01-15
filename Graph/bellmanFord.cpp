#include<iostream>
#include <unordered_map>
#include <list>
#include <math.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, (int) 1e8);
    dist[src] = 0;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e8 && (dist[u] + w) < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    // for negative cycle
    // for(int j = 0; j < m; j++)
    //     {
    //         int u = edges[j][0];
    //         int v = edges[j][1];
    //         int w = edges[j][2];

    //         if(dist[u] != pow(10,8) && dist[u] + w < dist[v])
    //         {
    //             return null vector;
    //         }
    //     }

    return dist;
    
}
int main()
{
    
}