typedef long long ll;
#include "catch.hpp"
#include "../ford_fulkerson.h"
#include "../data-structures/vector.h"
#include "../data-structures/graph.h"
#include "test_helpers.h"

TEST_CASE( "Ford Fulkerson works on trivial example", "[fordfulkerson]" ) {
    FordFulkerson ff(createGraph(tinyInput));
    REQUIRE(ff.max() == 2);
}

TEST_CASE( "Ford Fulkerson works on small example", "[fordfulkerson]") {
    FordFulkerson ff(createGraph(smallInput));
    REQUIRE(ff.max() == 4);
}


TEST_CASE( "Ford Fulkerson works on tricky example", "[fordfulkerson]" ) {
    Graph g = getGraph("test/inputs/tricky.in");

    FordFulkerson ff(g);  
    REQUIRE(ff.max() == 2000000000ll);
}


TEST_CASE( "Ford Fulkerson works on big example", "[fordfulkerson]" ) {
    Graph g = getGraph("test/inputs/big.in");
    
    FordFulkerson ff(g);  
    REQUIRE(ff.max() == 2202243530ll);
}

TEST_CASE( "Ford Fulkerson works on very big example", "[fordfulkerson]" ) {
    Graph g = getGraph("test/inputs/verybig.in");
    
    FordFulkerson ff(g);  
    REQUIRE(ff.max() == 168764294ll);
}
