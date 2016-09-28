typedef long long ll;
#include "catch.hpp"
#include "../ford_fulkerson.h"
#include "../data-structures/vector.h"
#include "test_helpers.h"

TEST_CASE( "Ford Fulkerson works on trivial example", "[fordfulkerson]" ) {
    ll n = 2;
    ll m = 1;
    
    
    FordFulkerson ff(n, m, createGraph(tinyInput));
    REQUIRE(ff.max() == 2);
}

TEST_CASE( "Ford Fulkerson works on small example", "[fordfulkerson]") {
    ll n = 4;
    ll m = 5;

    FordFulkerson ff(n, m, createGraph(smallInput));
    REQUIRE(ff.max() == 4);
}


TEST_CASE( "Ford Fulkerson works on tricky example", "[fordfulkerson]" ) {
    auto graph = getGraph("test/inputs/tricky.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    FordFulkerson ff(n, m, graph.first);  
    REQUIRE(ff.max() == 2000000000ll);
}

TEST_CASE( "Ford Fulkerson works on big example", "[fordfulkerson]" ) {
    auto graph = getGraph("test/inputs/big.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    FordFulkerson ff(n, m, graph.first);  
    REQUIRE(ff.max() == 2202243530ll);
}

TEST_CASE( "Ford Fulkerson works on very big example", "[fordfulkerson]" ) {
    auto graph = getGraph("test/inputs/verybig.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    FordFulkerson ff(n, m, graph.first);  
    REQUIRE(ff.max() == 168764294ll);
}