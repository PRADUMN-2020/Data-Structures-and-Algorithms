#include<bits/stdc++.h>
using namespace std;



class Solution
{
	public:
         // Prims algorithm gives the min cost spanning tree's cost and the tree edges for a connected graph.

         // Disadvantage: Prim's algorithm fails for a disconnected graph.
	
	// Main Idea: It is a greedy approach. The main idea of the algorithm is the start from any vertex and the find the min cost vertex in its sourrounding and select that then take the min cost vertex from all the vertices which are  adjacent to the selected till now and repeat this process until all n-1 edges are taken.

        

    // Time:O(Elog(E)) or O(Elog(V))
    // Space:O(E)
	
    int spanningTree(int V, vector<vector<int>> adj[])//Function to find sum of weights of edges and also the edges of the Minimum Spanning Tree.
    {
        // in pq first element is the wt of the current edge, second ka first is the ending node (or the node we are going to) and second ka second is the parent of the node.
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // Here the min heap is taken to give the min wt edges across all the edges currenly in the pq.
        int n=V;
        vector<pair<int,int>>mst;// vector to store all the edges of the mst.
        vector<int>visited(n);// to store the visited status of the vertices.
        pq.push({0,{0,-1}}); // we can start with any vertex so we start with 0 its parent is -1 and wt is 0.
        int cost=0; // var to store the sum of weights of all the edges of mst.
        
        
        // somewhat like bfs
        while(pq.size())
        {
            auto it=pq.top(); // select the min wt edge from the pq.
            pq.pop(); // pop it from pq.
            int wt=it.first;  
            int node=it.second.first;
            int parent=it.second.second;
            if(visited[node]==0) // if the node is not part of mst yet then add it and explore its adjacent nodes and push them to pq so that min can be chosen from them. 
            { 
               
                visited[node]=1;  // add node to mst
                if(parent>=0) // push selected edge to mst.
                {
                    mst.push_back({node, parent});
                }
                cost+=wt; // add the wt of the  selected edge to the total cost of mst.
                // iterate on all the adjacent nodes of the current node and push them in the pq. So that we can select the min wt edge from them.
                for(auto itr: adj[node])
                {
                    int adjNode=itr[0];
                    int adjWt=itr[1];
                    if(visited[adjNode]==0)
                    {
                        pq.push({adjWt,{adjNode, node}});
                    }
                }
                
            }
        }
        // to print the mst edges.
        // for (auto itr1: mst){ cout<<itr1.first<<"-"<<itr1.second<<", "}; 
        return cost;
        
    }
};


