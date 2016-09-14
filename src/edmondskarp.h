#ifndef edmondskarp_h
#define edmondskarp_h

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class EdmondsKarp {

    public:
        // Amount of vertices, edges
        ll n,m;
        // Graph
        vector<vector<ll>> g;
        
        EdmondsKarp(ll n, ll m, vector<vector<ll>> g);
        ll max();
        
};

#endif