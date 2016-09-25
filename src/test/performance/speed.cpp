#include <chrono>
#include "../../edmondskarp.h"
#include <functional>
#include "../test_helpers.h"
#include <iostream>

using namespace std;
using namespace std::chrono;
typedef long long ll;

// Test the speed of a max-flow algorithm, return time it took in seconds
// Takes the name of the file that is to be tested, located in the inputs folder
double testSpeed(std::function<ll()> fn) {
    auto start = std::chrono::system_clock::now();
    fn();
    auto stop = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = stop-start;
    return diff.count();
}

// Do multiple and take average
double average(std::function<ll()> fn, int iterations) {
    double sum = 0;
    for (int i = 0; i < iterations; i++) sum += testSpeed(fn);
    return sum / iterations;
}

// Test performance of algorithms
// Output time in seconds
int main() {
    auto graph = getGraph("test/inputs/big.in");
    ll n = graph.second.first;
    ll m = graph.second.second;

    EdmondsKarp ek(n,m,graph.first);
    double duration = average([&] {
        return ek.max();
    }, 10);
    std::cout << "It took " << duration << std::endl;
}
