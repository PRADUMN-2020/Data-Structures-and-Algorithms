#include<iostream>
#include<queue>
using namespace std;
void BFS(int Graph[][8],int i,int n) // Function to print bfs of the given graph. 
{   int visited[n+1]={0};            // Time :O(n^2) where n is the number of vertices in the Graph.
    queue<int>q;                     // This algorithm uses adjacency matrix.
    cout<<i<<" ";
    visited[i]=1;
    q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=7;v++)
        {
            if(Graph[u][v]==1&&visited[v]==0)
            {
                cout<<v<<" ";
                visited[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int Graph[8][8]={{0,0,0,0,0,0,0,0},        // Graph initialisation.
                     {0,0,1,1,1,0,0,0},
                     {0,1,0,1,0,0,0,0},
                     {0,1,1,0,1,1,0,0},
                     {0,1,0,1,0,1,0,0},
                     {0,0,0,1,1,0,1,1},
                     {0,0,0,0,0,1,0,0},
                     {0,0,0,0,0,1,0,0}};
    BFS(Graph,4,7);                      // BFS is called.

    return 0;
}