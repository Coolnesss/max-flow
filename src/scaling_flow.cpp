#include "scaling_flow.h"
#include "data-structures/vector.h"
#include <algorithm>

// Start by finding as big flows as possible, gradually decrease
ll ScalingFlow::max() {
    ll d = maxCapacity();

    
}

ll ScalingFlow::maxCapacity() {

    ll max = -1;
    for(auto a : g) {
        for(auto b : a) {
            max = std::max(b, max);
        }
    }
    return max;
}

ll ScalingFlow::bfs(ll d) {

}