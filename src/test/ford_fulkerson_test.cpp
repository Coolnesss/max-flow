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