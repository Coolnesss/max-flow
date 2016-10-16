#ifndef generate_h
#define generate_h
#include "../../data-structures/graph.h"
typedef long long ll;
using namespace std;




// Generate graphs that form the worst case for Ford-Fulkerson algorithm.
void build_bad_graph(ll n, Graph g, ll solmu_numero) {
    if (n == 1) {
        
    }
    
    ll source = solmu_numero++;
    ll yla = solmu_numero++;
    ll ala = solmu_numero++;
    ll sink = solmu_numero++;
    return;

    // Initial graph
/*
    g.connect(2,3,1);
    g.connect(2,4,1);
    g.connect(3,6,1);
    g.connect(4,6,1);
    g.connect(3,4,1);
*/    

}
#endif