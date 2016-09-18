#ifndef edmondskarp_h
#define edmondskarp_h

#include "data-structures/vector.h"
typedef long long ll;

class EdmondsKarp {

    public:
        EdmondsKarp(ll n, ll m, vector<vector<ll>> g);
        
        // Returns the maximum flow in the graph from node 1 to node n
        ll max();
    
    private:
        // Amount of vertices, edges
        ll n,m;
        // Graph
        vector<vector<ll>> g;
        // Breath-first search that finds a path from node 1 to node n
        bool bfs();
        // Last path found by the bfs 
        vector<ll> lastPath;
        // Maximum flow so far
        ll maxFlow;
};

#endif