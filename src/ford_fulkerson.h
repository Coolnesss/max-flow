#ifndef fordfulkerson_h
#define fordfulkerson_h

#include "data-structures/vector.h"
typedef long long ll;

class FordFulkerson {

    public:
        FordFulkerson(ll n, ll m, vector<vector<ll>> g);
        
        // Returns the maximum flow in the graph from node 1 to node n
        ll max();
    
    private:
        // Amount of vertices, edges
        ll n,m;
        // Graph
        vector<vector<ll>> g;
        // Depth-first search that finds a path from node node to node n
        bool dfs(ll node, vector<bool> visited);
        // Last path found by the dfs 
        vector<ll> lastPath;
        // Maximum flow so far
        ll maxFlow;
};

#endif