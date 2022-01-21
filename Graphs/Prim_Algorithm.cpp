#include<bits/stdc++.h>
using namespace std;
const int I=INT_MAX;
void min_cost_spanning_tree(int cost[][8],int n)   // Function to print the edges of the min cost spanning tree of the given graph.
{                                                  // Time: O(n^2) here n is the no of vertices of the graph.
    int near[n+1];
    for(int i=0;i<=n;i++)
    {
        near[i]=I;
    }
    int mcst[2][n-1];
    int u,v;
    int min=I;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    mcst[0][0]=u;
    mcst[1][0]=v;
    near[u]=0;
    near[v]=0;
    for(int i=1;i<=n;i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][u]<cost[i][v])
            {
                near[i]=u;
            }
            else
            {
                near[i]=v;
            }
        }
    }
    int k=0;
    for(int i=1;i<n-1;i++)
    {
        min=I;
        for(int j=1;j<=n;j++)
        {
            if(near[j]!=0)
            {
               if(cost[j][near[j]]<min)
               {
                   min=cost[j][near[j]];
                   k=j;
               }
            }
        }
        mcst[0][i]=k;
        mcst[1][i]=near[k];
        near[k]=0;
        for(int j=1;j<=n;j++)
        {
            if(near[j]!=0)
            {
                if(cost[j][k]<cost[j][near[j]])
                {
                    near[j]=k;
                }
            }
        }
    }
    cout<<"Minimum Cost Spanning Tree's edges are - "<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<mcst[0][i]<<"-"<<mcst[1][i]<<endl;
    }
}
int main()
{
    int cost[8][8]={{I,I,I,I,I,I,I,I},       //Initialization of the cost adjacency matrix.
                    {I,I,25,I,I,I,5,I},
                    {I,25,I,12,I,I,I,10},
                    {I,I,12,I,8,I,I,I},
                    {I,I,I,8,I,16,I,14},
                    {I,I,I,I,16,I,20,18},
                    {I,5,I,I,I,20,I,I},
                    {I,I,10,I,14,18,I,I}
                    };
    min_cost_spanning_tree(cost,7);           // Calling min cost spanning tree function.
    return 0;
}