#include <bits/stdc++.h>
#include "edmondskarp.h"
typedef long long ll;
using namespace std;

int main() {
    ll n, m;
    vector<vector<ll>> g;
    
    // Read input
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i < n; i++) {
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