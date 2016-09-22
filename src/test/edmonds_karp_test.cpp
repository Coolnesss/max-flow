
#define CATCH_CONFIG_MAIN 
typedef long long ll;
#include "catch.hpp"
#include "../edmondskarp.h"
#include "../data-structures/vector.h"
#include "test_helpers.h"

TEST_CASE( "Edmonds Karp works on trivial example", "[edmondskarp]" ) {
    ll n = 2;
    ll m = 1;
        
    EdmondsKarp ek(n, m, createGraph(tinyInput));
    REQUIRE(ek.max() == 2);
}

TEST_CASE( "Edmonds Karp works on small example", "[edmondskarp]" ) {
    ll n = 4;
    ll m = 5;
    
    EdmondsKarp ek(n, m, createGraph(smallInput));
    REQUIRE(ek.max() == 4);
}
