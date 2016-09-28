typedef long long ll;
#include "catch.hpp"
#include "../scaling_flow.h"
#include "../data-structures/vector.h"
#include "test_helpers.h"

TEST_CASE( "Scaling flow works on trivial example", "[scalingflow]" ) {
    ScalingFlow sf(createGraph(tinyInput));
    REQUIRE(sf.max() == 2);
}

TEST_CASE( "Scaling flow works on small example", "[scalingflow]") {
    ScalingFlow sf(createGraph(smallInput));
    REQUIRE(sf.max() == 4);
}


TEST_CASE( "Scaling Flow works on tricky example", "[scalingflow]" ) {
    Graph g = getGraph("test/inputs/tricky.in");
    
    ScalingFlow sf(g);  
    REQUIRE(sf.max() == 2000000000ll);
}

TEST_CASE( "Scaling Flow works on big example", "[scalingflow]" ) {
    Graph g = getGraph("test/inputs/big.in");
    
    ScalingFlow sf(g);  
    REQUIRE(sf.max() == 2202243530ll);
}

TEST_CASE( "Scaling Flow works on very big example", "[scalingflow]" ) {
    Graph g = getGraph("test/inputs/verybig.in");
    
    ScalingFlow sf(g);  
    REQUIRE(sf.max() == 168764294ll);
}