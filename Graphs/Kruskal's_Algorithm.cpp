#include<bits/stdc++.h>
using namespace std;
void _union(int set[],int u,int v)        // funtion to do union of set u and set v.
{
   if(set[u]<set[v])
   {
       set[u]+=set[v];
       set[v]=u;
   }
   else
   {
       set[v]+=set[u];
       set[u]=v;
   }
}
int find(int set[],int u)     // funtion to find the parent of the given element.
{
    int x=u;
    while(set[x]>0)
    {
        x=set[x];
    }
    return x;
}
void min_cost_spanning_tree(int edges[][9],int n,int e)      // funtion to print the edges of the minimum cost spanning tree for the given graph int the form of edges.
{
   int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};                     // array to implement set operations.
   int included[e]={0};                                      // array to mark a visited edge.
   int mcst[2][n-1];                                         // array to store the edges of minimum cost spanning tree.
   int i=0;
   while(i<n-1)
   {
       int k;
       int u,v;
       int min=INT_MAX;
      for(int j=0;j<e;j++)
      {
        if(included[j]==0)
        {
            if(edges[2][j]<min)
            {
                min=edges[2][j];
                 k=j;
                 u=edges[0][j];
                 v=edges[1][j];
            }
        }
      }
      included[k]=1;
      if(find(set,u)!=find(set,v))
      {
          mcst[0][i]=u;
          mcst[1][i]=v;
          _union(set,find(set,u),find(set,v));
          i++;
      }
   }
   for(int i=0;i<n-1;i++)
   {
       cout<<mcst[0][i]<<"-"<<mcst[1][i]<<endl;
   }
}
int main()
{
    int edges[3][9]={{1,1,2,2,3,4,4,5},        // initialization of the array edges which stores the edges of the graph.
                     {6,2,3,7,4,5,7,6},
                     {5,25,12,10,8,16,14,20,18}
                     };
    min_cost_spanning_tree(edges,7,9);        // funtion call to min_cost_spanning_tree function.
    return 0;
}