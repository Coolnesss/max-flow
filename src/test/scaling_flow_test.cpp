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