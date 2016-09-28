#define CATCH_CONFIG_MAIN 
typedef long long ll;
#include "catch.hpp"
#include "../edmondskarp.h"
#include "../data-structures/vector.h"
#include "test_helpers.h"
#include <iostream>

TEST_CASE( "Edmonds Karp works on trivial example", "[edmondskarp]" ) {
    Graph g = createGraph(tinyInput);
    EdmondsKarp ek(g);
    

    REQUIRE(ek.max() == 2);
}

TEST_CASE( "Edmonds Karp works on small example", "[edmondskarp]" ) {
    EdmondsKarp ek(createGraph(smallInput));
    REQUIRE(ek.max() == 4);
}

TEST_CASE( "Edmonds Karp works on tricky example", "[edmondskarp]" ) {
    Graph g = getGraph("test/inputs/tricky.in");

    EdmondsKarp ek(g);  
    REQUIRE(ek.max() == 2000000000ll);
}

TEST_CASE( "Edmonds Karp works on big example", "[edmondskarp]" ) {
    Graph g = getGraph("test/inputs/big.in");
    
    EdmondsKarp ek(g);  
    REQUIRE(ek.max() == 2202243530ll);
}

TEST_CASE( "Edmonds Karp works on very big example", "[edmondskarp]" ) {
    Graph g = getGraph("test/inputs/verybig.in");

    EdmondsKarp ek(g);  
    REQUIRE(ek.max() == 168764294ll);
}