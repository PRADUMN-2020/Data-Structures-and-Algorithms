#include<bits/stdc++.h>
using namespace std;


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Time:O(e*log(v)) where e is no of edges and v is no of vertices.

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