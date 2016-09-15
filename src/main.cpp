#include <iostream>
#include <vector>
#include <algorithm>
#include "edmondskarp.h"
#include <chrono>

typedef long long ll;
using namespace std;
using namespace std::chrono;

milliseconds time() {
    return duration_cast< milliseconds >(
        system_clock::now().time_since_epoch()  
    );
}

int main() {
    // Optimizations
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, m;
    vector<vector<ll>> g;
    
    // Read input
    cin >> n >> m;
    g.resize(n+1);
    
    for(int i = 1; i <= n; i++) {
        g[i].resize(n+1);
    }
    
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        // Add reverse zero-capacity edges
        g[b][a] = 0;
    }
    
   
}