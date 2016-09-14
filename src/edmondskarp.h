#ifndef edmondskarp_h
#define edmondskarp_h

#include <vector>
typedef long long ll;
using namespace std;

class EdmondsKarp {

    public:
        // Amount of vertices, edges
        ll n,m;
        // Graph
        vector<vector<ll>> g;
        // Graph with reversed edges, initially zero capacities
        vector<vector<ll>> reverse;
        
        EdmondsKarp(ll n, ll m, vector<vector<ll>> g);
        
        // Returns the maximum flow in the graph from node 1 to node n
        ll max();
    
    private:
        // Breath-first search that finds a path from node 1 to node n
        bool bfs();
};

#endif