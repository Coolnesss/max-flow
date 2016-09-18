#include <iostream>
#include <algorithm>
#include "edmondskarp.h"
#include "data-structures/vector.h"

typedef long long ll;
using namespace std;

int main() {
    // Optimizations
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, m;
    
    // Read input
    cin >> n >> m;
    vector<vector<ll>> g(n+1, vector<ll>(n+1));
    
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        // Add reverse zero-capacity edges
        g[b][a] = 0;
    }
    
   
}