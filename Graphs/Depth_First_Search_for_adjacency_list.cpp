#include<iostream>
#include<vector>
using namespace std;
// int visited[8]={0};
void DFS(vector<int>al[],int u,int n)           // Function to print dfs traversal of the given graph in the form of an adjacency list.
{                                               // Time:O(n+e) n: no of vertices e: no of edges. 
   static int visited[8]={0};                   // Space:O(n)
   if(visited[u]==0)
   {
       cout<<u<<" ";
       visited[u]=1;
       for(int i=0;i<al[u].size();i++)
       {
           if(visited[al[u][i]]==0)
           {
               DFS(al,al[u][i],n);
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

    DFS(al,1,7);                 // call to dfs function.
    return 0;
}