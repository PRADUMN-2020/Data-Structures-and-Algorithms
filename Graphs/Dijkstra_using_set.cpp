#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    // Time:O(e*log(v)) using set saves some iterations as whenever it gets a shorter distance from source to a perticluar node it deletes the previous {dist,node} pair for that node from the set which will lead to useless iterations on the same node in the future.
       set<pair<int,int>>st;
       vector<int>dist(V,1e9);
       dist[S]=0;
       st.insert({0,S});
       while(!st.empty())
       {
          auto it= *(st.begin());
          int dis=it.first;
          int node=it.second;
          st.erase(it);
          for(auto it: adj[node])
          {
              int adjNode=it[0];
              int wt=it[1];
              if(dis+wt<dist[adjNode])
              {
                  if(dist[adjNode]!=1e9)
                  {
                      st.erase({dist[adjNode],adjNode});
                  }
                  dist[adjNode]=dis+wt;
                  st.insert({dist[adjNode],adjNode});
              }
          }
       }
       return dist;
    }
};
