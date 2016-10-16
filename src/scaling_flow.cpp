#include "scaling_flow.h"
#include "data-structures/vector.h"
#include "data-structures/queue.h"
#include <algorithm>

ScalingFlow::ScalingFlow(Graph g) :n(g.n()), m(g.m()), g(g), lastPath(n+1) {}

// Start by finding as big flows as possible, gradually decrease
ll ScalingFlow::max() {
    ll d = g.maxCapacity();
    ll answer = 0;

    // Increase d when paths with capacity d cannot be found anymore
    while(d >= 1) {
        while((bfs(d))) {
            // The minimum capacity on the current route
            ll pathMin = 9999999999999ll;
            
            // Go back on path found by BFS from node n to node 1 and find minimum capacity  
            for (ll current = n; current != 1; current = lastPath[current]) {
                ll next = lastPath[current];
                
                // Check capacity of edge from next to current, set pathmin to it if smaller
                pathMin = std::min(g.weights(next)[current], pathMin);
            }
            
            // Traverse path again and mutate the graph by decreasing capacities by the minimum previous capacity
            for (ll current = n; current != 1; current = lastPath[current]) {
                ll next = lastPath[current];
                
                g.weights(next)[current] -= pathMin;
                g.weights(current)[next] += pathMin;
            }
            // Add the flow that was just discovered to the answer, i.e increase the maximum flow
            answer += pathMin;
        }
        d /= 2;
    }
    return answer;
}

// Only look for paths that have capacity of at least d
bool ScalingFlow::bfs(ll d) {
    queue<ll> q;
    vector<bool> visited(n+1);
    
    for(int i = 0; i <= n; i++) lastPath[i] = -1;    
    
    // Start with node 1
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        ll current = q.pop();
        
        visited[current] = true;
        
        for(int i = 0; i < g[current].size(); i++) {
            ll next = g[current][i];            
            // Visit only nodes where path exists and capacity is at least d
            if (!visited[next] && g.weights(current)[next] >= d) {             
                q.push(next);
                lastPath[next] = current;
            }            
        }
    }
    
    // Return true if the node n was reached
    return (visited[n]);
    
}