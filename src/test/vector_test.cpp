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
    vector<vector<int>> v(n, vector<int>(n));
    
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

TEST_CASE("Vector clear sets all values to blank", "[vector]" ) {
    vector<ll> v(10);

    for(int i = 0; i < 10; i++) {
        v[i] = 18*i;
    }
    v.clear();

    for(auto a : v) {
        REQUIRE(a == 0);
    }
}

TEST_CASE("push_back allocates space dynamically and retains elements", "[vector]" ) {
    vector<int> v;
    int n = 20;
    
    for(int i = 0; i < n; i++) {
        v.push_back(i);
    }

    REQUIRE(v.size() == 20);
    for(int i = 0; i < n; i++) {
        REQUIRE(v[i] == i);
    }

}