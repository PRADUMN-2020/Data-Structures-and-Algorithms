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
      for(int i=1;i<=n;i++)
      {
          if(visited[i]==0)
          {
            if(mn>dist[i])
            {
                mn=dist[i];
                k=i;
            }
          }
      }
      visited[k]=1;
      for(int i=0;i<cal[k].size();i++)
      {
          if(visited[cal[k][i].first]==0)
          {
              dist[cal[k][i].first]=min(dist[cal[k][i].first],mn+cal[k][i].second);
          }
      }
  }
}
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