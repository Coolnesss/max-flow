#ifndef edmondskarp_h
#define edmondskarp_h

#include "data-structures/vector.h"
#include "data-structures/graph.h"
typedef long long ll;

class EdmondsKarp {

    public:
        // Constructor with graph g
        EdmondsKarp(Graph g);
        // Returns the maximum flow in the graph from node 1 to node n
        ll max();
    
    private:
        ll n, m;
        // Graph
        Graph g;
        // Breath-first search that finds a path from node 1 to node n
        bool bfs();
        // Last path found by the bfs 
        vector<ll> lastPath;
        // Maximum flow so far
        ll maxFlow;
};

#endif