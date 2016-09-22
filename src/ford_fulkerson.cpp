#include "ford_fulkerson.h"
#include <algorithm>
typedef long long ll;

FordFulkerson::FordFulkerson(ll n, ll m, vector<vector<ll>> g) :n(n), m(m), g(g), lastPath(n+1) {}

// Maximum flow in the graph
// Almost same as Edmonds Karp except DFS is used instead of BFS
ll FordFulkerson::max() {
    ll answer = 0;
    
    while(true) {
        vector<bool> visited(n+1);
        visited[1] = true;
        if (!dfs(1, visited)) break;
        
        // The minimum capacity on the current route
        ll pathMin = 999999999;
        
        // Go back on path found by DFS from node n to node 1 and find minimum capacity  
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

// Depth-first search from node 1 to N
bool FordFulkerson::dfs(ll node, vector<bool> visited) {
    if (node == n) return true;
    
    for(int i = 1; i < g[node].size(); i++) {
        if (!visited[i] && g[node][i] > 0) {
            lastPath[i] = node;
            visited[i] = true;
            return dfs(i, visited);
        }
    }
    return false;
}