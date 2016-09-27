#include <iostream>
#include <algorithm>
#include "edmondskarp.h"
#include "data-structures/queue.h"
#include "data-structures/vector.h"

typedef long long ll;

EdmondsKarp::EdmondsKarp(ll n, ll m, vector<vector<ll>> g) :n(n), m(m), g(g), lastPath(n+1) {}

// Find the maximum flow in the graph
ll EdmondsKarp::max() {
    ll answer = 0;
    
    while(bfs()) {
        // The minimum capacity on the current route
        ll pathMin = 999999999;
        
        // Go back on path found by BFS from node n to node 1 and find minimum capacity  
        for (ll current = n; current != 1; current = lastPath[current]) {
            ll next = lastPath[current];
            
            // Check capacity of edge from next to current, set pathmin to it if smaller
            pathMin = std::min(g[next][current], pathMin);
        }
        
        // Traverse path again and mutate the graph by decreasing capacities by the minimum previous capacity
        for (ll current = n; current != 1; current = lastPath[current]) {
            ll next = lastPath[current];
            
            g[next][current] -= pathMin;
            g[current][next] += pathMin;
        }
        // Add the flow that was just discovered to the answer, i.e increase the maximum flow
        answer += pathMin;
    }
    
    return answer;
}

bool EdmondsKarp::bfs() {
    queue<ll> q;
    vector<bool> visited(n+1);
    
    for(int i = 0; i <= n; i++) lastPath[i] = -1;    
    
    // Start with node 1
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        ll current = q.pop();
        
        visited[current] = true;
        
        for(int i = 1; i < g[current].size(); i++) {            
            // Visit only nodes where path exists
            if (!visited[i] && g[current][i] > 0) {             
                q.push(i);
                lastPath[i] = current;
            }            
        }
    }
    
    // Return true if the node n was reached
    return (visited[n]);
    
}