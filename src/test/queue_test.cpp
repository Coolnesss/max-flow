#include "catch.hpp"
#include "../data-structures/queue.h"

TEST_CASE( "Queue supports adding and removing one element", "[queue]" ) {
    queue<int> q;
    
    int e = 77;
    q.push(e);
    REQUIRE(!q.empty());
    REQUIRE(q.front() == e);
    REQUIRE(q.pop() == e);
    REQUIRE(q.empty());
    
}

TEST_CASE( "Queue supports adding and removing multiple elements and acts like a queue", "[queue]" ) {
    queue<int> q;
    int n = 10;
    
    for(int i = 0; i < n; i++) {
        q.push(i);
    }
    REQUIRE(!q.empty());
    for(int i = 0; i < n; i++) {
        REQUIRE(q.pop() == i);
    }
    REQUIRE(q.empty());
}

TEST_CASE( "Alternating pop and push work", "[queue]" ) {
    queue<int> q;
    int n = 10;
    for(int i = 0; i < n; i++) {
        q.push(i);
        REQUIRE(q.pop() == i);
    }
    REQUIRE(q.empty());
}
