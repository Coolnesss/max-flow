typedef long long ll;
#include "catch.hpp"
#include "../scaling_flow.h"
#include "../data-structures/vector.h"
#include "test_helpers.h"

TEST_CASE( "Scaling flow works on trivial example", "[scalingflow]" ) {
    ll n = 2;
    ll m = 1;
    
    
    ScalingFlow sf(n, m, createGraph(tinyInput));
    REQUIRE(sf.max() == 2);
}

TEST_CASE( "Scaling flow works on small example", "[scalingflow]") {
    ll n = 4;
    ll m = 5;

    ScalingFlow sf(n, m, createGraph(smallInput));
    REQUIRE(sf.max() == 4);
}


TEST_CASE( "Scaling Flow works on tricky example", "[scalingflow]" ) {
    auto graph = getGraph("test/inputs/tricky.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    ScalingFlow sf(n, m, graph.first);  
    REQUIRE(sf.max() == 2000000000ll);
}

TEST_CASE( "Scaling Flow works on big example", "[scalingflow]" ) {
    auto graph = getGraph("test/inputs/big.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    ScalingFlow sf(n, m, graph.first);  
    REQUIRE(sf.max() == 2202243530ll);
}

TEST_CASE( "Scaling Flow works on very big example", "[scalingflow]" ) {
    auto graph = getGraph("test/inputs/verybig.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    ScalingFlow sf(n, m, graph.first);  
    REQUIRE(sf.max() == 168764294ll);
}