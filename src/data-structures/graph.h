#ifndef graph_h
#define graph_h
#include "vector.h"
#include <algorithm>

// Wrapper class for a directed graph, includes the graph represented as adjacency lists
// And a separate weight matrix

class Graph {
    private:
        ll _n;
        ll _m;
        ll _max_capacity = -1;
        vector<vector<ll>> _graph;
        vector<vector<ll>> _weights;

    public:
        // Reserve space for n nodes
        Graph(ll n, ll m) :_n(n), _m(m) {
            _graph = vector<vector<ll>>(n+1);
            _weights = vector<vector<ll>>(n+1, vector<ll>(n+1)); 
        };

        // Connect a to b with weight w
        // Also adds opposite edge
        void connect(ll a, ll b, ll w) {
            _max_capacity = std::max(_max_capacity, w);

            _graph[a].push_back(b);
            _graph[b].push_back(a);

            _weights[a][b] = w;
            _weights[b][a] = 0;
        }

        // Adjacency list of node a
        vector<ll>& operator[](ll a) {
            return _graph[a]; 
        }

        // Weight array for node a
        vector<ll>& weights(ll a) {
            return _weights[a];
        }

        // Return maximum capacity
        ll maxCapacity() {
            return _max_capacity;
        }

        ll n() {
            return _n;
        }

        ll m() {
            return _m;
        }
};
#endif