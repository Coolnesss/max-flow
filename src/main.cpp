#include <iostream>
#include <vector>
#include <algorithm>
#include "edmondskarp.h"
typedef long long ll;
using namespace std;

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
        ll a,b,c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    
    EdmondsKarp edmondsKarp(n, m, g);
    cout << edmondsKarp.max() << endl;
}