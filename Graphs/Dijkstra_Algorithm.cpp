#include<bits/stdc++.h>
using namespace std;
#define inf 100000
void dijkstra(vector<int>&visited,vector<int>&dist,vector<pair<int,int>>cal[],int s,int n)    // Time:O(n^2) here n is the no of vertices.
{
  visited[s]=1;
  dist[s]=0;
  for(int i=0;i<cal[s].size();i++)
  {
    dist[cal[s][i].first]=cal[s][i].second;
  }
  for(int i=0;i<n-2;i++)
  {
      int mn=INT_MAX;
      int k=-1;
      for(int j=1;j<=n;j++)
      {
          if(visited[j]==0)
          {
            if(mn>dist[j])
            {
                mn=dist[j];
                k=j;
            }
          }
      }
      visited[k]=1;
      for(int j=0;j<cal[k].size();j++)
      {
          if(visited[cal[k][j].first]==0)
          {
              dist[cal[k][j].first]=min(dist[cal[k][j].first],mn+cal[k][j].second);
          }
      }
  }
}
// for optimized dijkstra using set see leetcode 1514 solution. T=O(e*log(n))
/*
Code for dijkstra using set.

Link:https://leetcode.com/problems/path-with-maximum-probability/discuss/732293/Dijkstra's-algorithm-implementation-C%2B%2B


void setList(vector<vector<pair<int, int>>>& graph, int src) {
        // graph: each pair<int, int> is <node, weight>
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        set<pair<int, int>> unfinalized;  // <distance, node>
        for (int node = 0; node < n; node++)
            unfinalized.insert({node == src ? 0 : INT_MAX, node});

        while (!unfinalized.empty()) {
            pair<int, int> p = *(unfinalized.begin());
            unfinalized.erase(unfinalized.begin());
            int u = p.second;

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first, weight = graph[u][i].second;
                if (dist[u] + weight < dist[v]) {
                    // v cannot be finalized, so must be in finalized
                    unfinalized.erase(unfinalized.find({dist[v], v}));
                    dist[v] = dist[u] + weight;
                    unfinalized.insert({dist[v], v});
                }
            }
        }

        printSolution(dist);
    }
*/
int main()
{
    vector<pair<int,int>>cal[7];  // Initialising cost adjacency list. 
    cal[1].push_back({2,50});
    cal[1].push_back({3,45});
    cal[1].push_back({4,10});
    cal[2].push_back({3,10});
    cal[2].push_back({4,15});
    cal[3].push_back({3,35});
    cal[4].push_back({1,10});
    cal[4].push_back({5,15});
    cal[5].push_back({2,20});
    cal[5].push_back({3,35});
    cal[6].push_back({5,3});
    vector<int>visited(7,0);    // vector to mark the selected vertices.
    vector<int>shortest_dist(7,inf); // vector to store the shortest distance of all the vetices from the given source vetex.
    dijkstra(visited,shortest_dist,cal,1,6); // function call to dijkstra algorithm.
    for(int i=1;i<=6;i++)     // printing the updated shortest_distance vector.
    {
      cout<<shortest_dist[i]<<endl;
    }
    return 0;
}