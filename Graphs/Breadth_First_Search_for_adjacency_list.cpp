#include<iostream>
#include<queue>
using namespace std;
void BFS(vector<int>al[],int i,int n)         //Funtion to print bfs traversal of a given graph in the form of adjacency list.
{                                             // Time:O(n+e) where n is no of vertices and e is no of edges.
                                              // Space:O(n) for queue, O(n) for Visited array.
    int visited[n+1]={0};
    queue<int>q;
    cout<<i<<" ";
    visited[i]=1;
    q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<al[u].size();i++)
        {
            if(visited[al[u][i]]==0)
            {
                cout<<al[u][i]<<" ";
                visited[al[u][i]]=1;
                q.push(al[u][i]);
            }
        }
    }
}
int main()
{
    vector<int> al[8];     // Adjacency list initialization.
    al[1].push_back(2);
    al[1].push_back(3);
    al[1].push_back(4);
    al[2].push_back(1);
    al[2].push_back(3);
    al[3].push_back(1);
    al[3].push_back(2);
    al[3].push_back(4);
    al[3].push_back(5);
    al[4].push_back(1);
    al[4].push_back(3);
    al[4].push_back(5);
    al[5].push_back(3);
    al[5].push_back(4);
    al[5].push_back(6);
    al[5].push_back(7);
    al[6].push_back(5);
    al[7].push_back(5);

    BFS(al,4,7);         // Calling bfs on the adjacency list.


    return 0;
}
