#include <iostream>
#include <algorithm>
#include "edmondskarp.h"
#include "data-structures/graph.h"

typedef long long ll;
using namespace std;

int main() {
    // Optimizations
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, m;
    
    // Read input
    // First nodes and edges, then each edge
    cin >> n >> m;
    Graph g(n, m);
    
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g.connect(a,b,c);
    }
    EdmondsKarp ek(g);
    cout << ek.max() << endl;
    
   
}