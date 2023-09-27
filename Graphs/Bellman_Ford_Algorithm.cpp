
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents all the edges of the graph. Each directed edge is represented as a vector of size 3 as follows: if u->v has a cost wt then 0th element is u 1st element is v and 2nd element is wt.
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    // Time:O(V*E), Space:O(V)
    
    // Very important Notes for Bellman Ford Algorithm.
    

    /* 
    *  Bellman Ford also work for -ve weights where dijkstra fails.
    *  If in a graph any cyclic path with path cost <0 then the graph is said to have a -ve cycle.
    *  -ve cycle=> A cyclic path with -ve total cost.
    *  Helps to detect -ve cycles where dijkstra fails and run into an infinite loop keep on reducing the distance again and again.
    *  Works only for Directed Graphs if not directed then make it.
    *  Edges given can be in any order.
    */
    
    // 2 V Imp. questions.
    
   /* 1) Why n-1 iterations of relaxations.
    
    There are n-1 relaxations because since in a graph of n nodes, in worst case, you will take n-1 edges at reach from the first to
    the last thereby we iterate for n-1 iterations. Try drawing a graph which takes more than n-1 edges for a path its not possible.
    
    2) How to detect -ve cycle?
    
    As we know we should get the min distances by max n-1 iterations and if we run 1 more iteration ie. Nth and if any distance updates
    it means graph has a -ve cycle.*/
    
    
    
    
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       
       vector<int>dis(V,1e8); // intialise distance array to store the min distances from source to every node. Initially we fill it with a big value.
       dis[S]=0;  // min dis from source to source will be 0.
       for(int i=0;i<V-1;i++) // we run V-1 iterations and in each iteration we iterate across all the edges and find the relaxation  for each edge (ie. if u is reachable (checked by dis[u]!=1e8 cond.) and if dis[u]+wt<dis[v] update the dist[v]).
       {
           for(auto it:edges)
           {
               int u=it[0];
               int v=it[1];
               int wt=it[2];
            //   this if is called relaxation.
               if(dis[u]!=1e8 and dis[u]+wt<dis[v])
               {
                   dis[v]=dis[u]+wt;
               }
           }
       }
       
       // Here if the graph does not contain any negavtie cycle in it the dis array now contains the min dist of every node from the source.
       
       // As we know we need at max V-1 iterations to get the min dis of each vertex from source and it wont be updated anymore if we run further iterations if the graph dont have any negative cycles but if it does update if we run the Nth iteration the it definitely contains a negative cycle and then we return an array fill with -1.
       
       for(auto it:edges)
           {
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               if(dis[u]!=1e8 and dis[u]+wt<dis[v])
               {
                  return {-1}; // returning array filled with -1's.
               }
           }
           
        return dis;
       
       
          
    }
};

