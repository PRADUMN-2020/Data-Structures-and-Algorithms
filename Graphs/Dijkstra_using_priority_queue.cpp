#include<bits/stdc++.h>
using namespace std;


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Time:O(e*log(v)) where e is no of edges and v is no of vertices.
        // A negative wt cycle is a cycle in a graph having path sum as -ve.
        // Limitations: Dont work for negative edge weights and also gives TLE for negative wt cycle or loop as it gets into an infinite loop. Then we use Bellman Ford Algorithm as it works for -ve weights and also helps to detect negative cycle.

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node])
            {
                if(dis+it[1]<dist[it[0]])
                {
                    dist[it[0]]=dis+it[1];
                    pq.push({dist[it[0]],it[0]});
                }
            }
        }
        return dist;
        
        
    }
