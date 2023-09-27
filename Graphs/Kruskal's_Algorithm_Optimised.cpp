
#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:

	// Kruskals algorithm gives the min cost spanning tree's total cost and the tree edges for a connected or a disconnected graph this algo is robust to handle both (this is best to find a mst and I prefer this).

         // Advantage: Unlike Prim's algorithm which fails for a disconnected graph it also works for a disconnected graph and in case of a disconnected graph it gives the mst's for each of the components and a sum of all the mst costs.
	
	// Main Idea: The idea of Kruskal's algorithm is to first sort all the edges according to their edge weights ascending order and then iterate on them and see if for a perticular edge make by u and v is there a connection between u and v vertices (using find function of disjoint set to check if the both have same parents then they have a connection), if there is a connection we cant add this edge in mst because if we do so the there will be cycle formed so we leave it else if they have no connection we simply add it to the mst.
	
     // Time: O(eloge)
     // Space: O(E+N)
   


	// Class for Disjoint Set Data Structure

	class DisjointSet
	{
	  vector<int>set;
	  
	  public: 
	  
	  DisjointSet(int n)
	  {
	  set.resize(n+1,-1);
	  }
	  
	  void _union(int u, int v) // Time: log(n)
	  {
	      int uParent=find(u);
	      int vParent=find(v);
	      if(set[uParent]<set[vParent])
	      {
	          set[uParent]+=set[vParent];
	          set[vParent]=uParent;
	      }
	      else
	      {
	          set[vParent]+=set[uParent];
	          set[uParent]=vParent;
	      }
	  }
	  
	  int find(int u) // Time: log(n)
	  {
	      int x=u;
	      while(set[x]>0)
	      {
	          x=set[x];
	      }
	      return x;
	  }
	};
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int cost=0;
        vector<pair<int,pair<int,int>>>edges;
        vector<pair<int,int>>mst;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjNode=it[0];
                int wt=it[1];
                edges.push_back({wt,{i,adjNode}});
            }
        }
 
        sort(edges.begin(),edges.end());
        
        DisjointSet dsu(V); // Declaring Disjoint set Data Structure
        
    
        for(int i=0;i<edges.size();i++)
        {
            int wt=edges[i].first;
            int u=edges[i].second.first+1;
            int v=edges[i].second.second+1;
            if(dsu.find(u)!=dsu.find(v))
            {
                cost+=wt;
                mst.push_back({u,v});
                dsu._union(u,v);
            }
        }
        
        return cost;
        
    }
};

