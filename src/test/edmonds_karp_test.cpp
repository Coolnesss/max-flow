
#define CATCH_CONFIG_MAIN 
typedef long long ll;
#include "catch.hpp"
#include "../edmondskarp.h"
#include "../data-structures/vector.h"

// Initialize graph required for algorithm
vector<vector<ll>> createGraph(ll input[]) {
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

TEST_CASE( "Edmonds Karp works on trivial example", "[edmondskarp]" ) {
    ll n = 2;
    ll m = 1;
    ll smallInput[] = {2, 1, 1, 2, 2};
    
    EdmondsKarp ek(n, m, createGraph(smallInput));
    REQUIRE(ek.max() == 2);
}

TEST_CASE( "Edmonds Karp works on small example", "[edmondskarp]" ) {
    ll n = 4;
    ll m = 5;
    
    ll smallInput[] = {
        4, 5,
        1, 2, 2,
        1, 3, 5,
        2, 4, 3,
        3, 2, 2,
        3, 4, 1
    };
    
    EdmondsKarp ek(n, m, createGraph(smallInput));
    REQUIRE(ek.max() == 4);
}
