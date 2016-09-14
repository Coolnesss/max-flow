#include <vector>
#include <queue>
#include <iostream>

#include "edmondskarp.h"
typedef long long ll;
using namespace std;

EdmondsKarp::EdmondsKarp(ll n, ll m, vector<vector<ll>> g) :n(n), m(m), g(g) {
    reverse.resize(n+1);
    
    for (auto &a : reverse) {
        a.resize(n+1);   
    }
}

ll EdmondsKarp::max() {
    return bfs();
}

bool EdmondsKarp::bfs() {
    
    queue<ll> q;
    vector<bool> visited;
    visited.resize(n+1);
    
    // Start with node 1
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        ll current = q.front(); 
        q.pop();
        visited[current] = true;
        
        for(int i = 1; i <= n; i++) {            
            // Visit only nodes where path exists            
            if (!visited.at(i) && g.at(current).at(i) > 0) {
                q.push(i);
                visited[i] = true;
            }            
        }
    }
    
    // Return true if the node n was reached
    return (visited[n]);
    
}