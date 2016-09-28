#include "ford_fulkerson.h"
#include <algorithm>
typedef long long ll;

FordFulkerson::FordFulkerson(Graph g) :n(g.n()), m(g.m()), g(g) {
    lastPath = vector<ll>(n+1);
}

// Maximum flow in the graph
// Almost same as Edmonds Karp except DFS is used instead of BFS
ll FordFulkerson::max() {
    ll answer = 0;
    
    while(true) {
        vector<bool> visited(n+1);
        for(int i = 0; i <= n; i++) lastPath[i] = -1;
        dfs(1, visited);
        
        if (!visited[n]) break;

        // The minimum capacity on the current route
        ll pathMin = 9999999999999ll;
        
        // Go back on path found by DFS from node n to node 1 and find minimum capacity  
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

        // Clean up for next round
        visited.clear();
        for(int i = 0; i <= n; i++) lastPath[i] = -1;    
    }
    
    return answer;
}

// Depth-first search from node 1 to N
void FordFulkerson::dfs(ll node, vector<bool> &visited) {
    if (visited[node] || visited[n]) return;    
    visited[node] = true;

    for(int i = 0; i < g[node].size(); i++) {
        ll next = g[node][i];
        if (!visited[next] && g.weights(node)[next] > 0) {
            lastPath[next] = node;
            dfs(next, visited);
        }
    }
}