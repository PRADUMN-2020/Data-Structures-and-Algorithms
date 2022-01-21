#include<iostream>
using namespace std;
// int visited[8]={0};
void DFS(int Graph[][8],int u,int n)                   // Function to print dfs traversal of the given graph.
{                                                      // Time:O(n^2)
   static int visited[8]={0};
    if(visited[u]==0)
    {
        cout<<u<<" ";
        visited[u]=1;
        for(int i=1;i<=n;i++)
        {
            if(Graph[u][i]==1&&visited[i]==0)
            {
               DFS(Graph,i,n);
            }
        }
    }
}
int main()
{
    int Graph[8][8]={{0,0,0,0,0,0,0,0},      //Initialization of the graph.
               {0,0,1,1,1,0,0,0},
               {0,1,0,1,0,0,0,0},
               {0,1,1,0,1,1,0,0},
               {0,1,0,1,0,1,0,0},
               {0,0,0,1,1,0,1,1},
               {0,0,0,0,0,1,0,0},
               {0,0,0,0,0,1,0,0}
                 };
    DFS(Graph,1,7);                        //Call to dfs funtion.
    return 0;
}