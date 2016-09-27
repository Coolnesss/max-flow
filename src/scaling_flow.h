#ifndef scalingflow_h
#define scalingflow_h

#include "data-structures/vector.h"
typedef long long ll;

class ScalingFlow {

    public:
        ScalingFlow(ll n, ll m, vector<vector<ll>> g);
        // Returns the maximum flow in the graph from node 1 to node n
        ll max();
    
    private:
        // Amount of vertices, edges
        ll n,m;
        // Graph
        vector<vector<ll>> g;
        // Breath-first search that finds a flow that is atleast size 2^d
        bool bfs(ll d);
        // Last path found by the bfs
        vector<ll> lastPath;
        // Maximum flow so far
        ll maxFlow;
        // Find largest capacity in garph
        ll maxCapacity();
};

#endif