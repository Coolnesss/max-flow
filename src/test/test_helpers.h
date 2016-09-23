#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "../data-structures/vector.h"
#include <string>
#include <iostream>

static vector<vector<ll>> readInput(const std::string fileName) {
    // Use file as input stream
    
    std::freopen(fileName.c_str(), "r", stdin);

    // Optimizations
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    ll n, m;
    
    // Read input
    std::cin >> n >> m;
    vector<vector<ll>> g(n+1, vector<ll>(n+1));
    
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        std::cin >> a >> b >> c;
        g[a][b] = c;
        // Add reverse zero-capacity edges
        g[b][a] = 0;
    }
    fclose(stdin);
    return g;
}

static std::pair<vector<vector<ll>>, std::pair<ll,ll>> getGraph(const std::string fileName) {
    std::freopen(fileName.c_str(), "r", stdin);
    ll n = 0, m = 0;
    std::cin >> n >> m;
    
    fclose(stdin);
    return { readInput(fileName), { n,m }};
}

// Initialize graph required for algorithm
static vector<vector<ll>> createGraph(ll input[]) {
    ll n = input[0];
    ll m = input[1];
    vector<vector<ll>> g(n+1, vector<ll>(n+1));
    
    // Same logic as when input is read from cin
    for(int i = 4; i < m*3+2; i += 3) {
        g[input[i-2]][input[i-1]] = input[i];
        g[input[i-1]][input[i-2]] = 0;
    }
    
    return g;
}

// Sample inputs
static ll tinyInput[] = {2, 1, 1, 2, 2};

static ll smallInput[] = {
    4, 5,
    1, 2, 2,
    1, 3, 5,
    2, 4, 3,
    3, 2, 2,
    3, 4, 1
};

#endif