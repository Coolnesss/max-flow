#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "../data-structures/vector.h"
#include "../data-structures/graph.h"
#include <string>
#include <iostream>
#include <fstream>
// Returns the weights and graph as separate vectors. 
// One is an adjacency list and the other is matrix of weights
static Graph readInput(const std::string fileName) {
    // Use file as input stream
    
    std::ifstream stream(fileName);
    ll n, m;
    // Read input
    stream >> n >> m;
    Graph g(n, m);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        stream >> a >> b >> c;
        g.connect(a, b, c);
    }
    return g;
}

static Graph getGraph(const std::string fileName) {
    return readInput(fileName);
}

// Initialize graph required for algorithm
static Graph createGraph(ll input[]) {
    ll n = input[0];
    ll m = input[1];
    Graph g(n, m);
    
    // Same logic as when input is read from cin
    for(int i = 4; i < m*3+2; i += 3) {
        g.connect(input[i-2], input[i-1], input[i]);
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

// Build a complete graph (where every vertice is connected to every vertice) with random weights
inline Graph generateCompleteGraph(ll n) {
    Graph g(n, 0);

    // Connect every node except source and sink
    for(int i = 2; i < n; i++) {
        for(int j = 2; j < n; j++) {
            // Random weight in range 1..2^24
            g.connect(i, j, rand() % (1 << 24) + 1);
        }
    }

    // Connect source to all except sink, connect all to sink except source
    for(int i = 2; i < n; i++) {
        g.connect(1, i, rand() % (1 << 24) + 1);
    }

    for(int i = 2; i < n; i++) {
        g.connect(i, n, rand() % (1 << 24) + 1);
    }

    return g;
}

#endif