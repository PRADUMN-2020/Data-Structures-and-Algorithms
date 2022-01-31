#include<bits/stdc++.h>
using namespace std;
#define inf 100000
void floyd(int graph[][5],int n)   // Time:O(n^3) where n is the no of vertices of the given.
{
  for(int k=1;k<=n;k++)
  {
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {   
              if(i!=j&&i!=k&&j!=k)
              graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
          }
      }
  }
}
int main()
{
    int graph[5][5]={{0,0,0,0,0},
                     {0,0,3,inf,7},
                     {0,8,0,2,inf},
                     {0,5,inf,0,1},
                     {0,2,inf,inf,0},
                       };
    floyd(graph,4);          // After calling floyd's algorithm the adjacency matrix will be updated with the min cost to reach from i to j at index i, j.
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}