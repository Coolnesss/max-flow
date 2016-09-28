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

TEST_CASE( "Edmonds Karp works on tricky example", "[edmondskarp]" ) {
    auto graph = getGraph("test/inputs/tricky.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    EdmondsKarp ek(n, m, graph.first);  
    REQUIRE(ek.max() == 2000000000ll);
}

TEST_CASE( "Edmonds Karp works on big example", "[edmondskarp]" ) {
    auto graph = getGraph("test/inputs/big.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    EdmondsKarp ek(n, m, graph.first);  
    REQUIRE(ek.max() == 2202243530ll);
}

TEST_CASE( "Edmonds Karp works on very big example", "[edmondskarp]" ) {
    auto graph = getGraph("test/inputs/verybig.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    EdmondsKarp ek(n, m, graph.first);  
    REQUIRE(ek.max() == 168764294ll);
}