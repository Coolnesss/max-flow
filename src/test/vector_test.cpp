typedef long long ll;
#include "catch.hpp"
#include "../data-structures/vector.h"


TEST_CASE( "Vector allocates zeros for size n", "[vector]" ) {
    int n = 10;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) {
        REQUIRE(v[i] == 0);
    }
    
}

TEST_CASE( "Vector retains elements", "[vector]" ) {
    int n = 10;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) {
        v[i] = i;
    }
    
    for(int i = 0; i < n; i++) {
        REQUIRE(v[i] == i);
    }
}

TEST_CASE("Vector of vectors retains elements", "[vector]" ) {
    int n = 2;
    vector<vector<int>> v(n);
    
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           v[i][j] = i;
       }       
    }
    
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           REQUIRE(v[i][j] == i);
       }       
    }
}