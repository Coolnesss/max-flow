#include <chrono>
#include "../../edmondskarp.h"
#include "../../ford_fulkerson.h"
#include "../../scaling_flow.h"
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

void trickyTest() {
    cout << "Starting tricky test" << endl;
    Graph graph = getGraph("test/inputs/tricky.in");

    FordFulkerson ff(graph);
    double duration = average([&] {
        return ff.max();
    }, 10);
    std::cout << "It took " << duration << std::endl;
}

void veryBigTest() {
    cout << "Starting very big test" << endl;

    Graph graph = getGraph("test/inputs/verybig.in");
    
    double duration = average([&] {
        FordFulkerson ff(graph);
        return ff.max();
    }, 10);

    cout << "Ford Fulkerson took " << duration << endl;

    duration = average([&] {
        EdmondsKarp ek(graph);
        return ek.max();
    }, 10);

    cout << "Edmonds Karp took " << duration << endl;

    duration = average([&] {
        ScalingFlow sf(graph);
        return sf.max();
    }, 10);

    cout << "Scaling flow took " << duration << endl;
}

void hugeTest() {
    cout << "Starting huge test" << endl;

    Graph graph = getGraph("test/inputs/huge.in");

    double duration = average([&] {
        FordFulkerson ff(graph);
        return ff.max();
    }, 10);

    cout << "Ford Fulkerson took " << duration << endl;

    duration = average([&] {
        EdmondsKarp ek(graph);
        return ek.max();
    }, 10);

    cout << "Edmonds Karp took " << duration << endl;

    duration = average([&] {
        ScalingFlow sf(graph);
        return sf.max();
    }, 10);

    cout << "Scaling flow took " << duration << endl;
}

void completeGraphTest() {
    cout << "Starting complete graph test" << endl;

    Graph graph = generateCompleteGraph(300);

    cout << "Graph done" << endl;
/*
    double duration = average([&] {
        FordFulkerson ff(graph);
        return ff.max();
    }, 10);

    cout << "Ford Fulkerson took " << duration << endl;
*/
    double duration = average([&] {
        EdmondsKarp ek(graph);
        return ek.max();
    }, 10);

    cout << "Edmonds Karp took " << duration << endl;

    duration = average([&] {
        ScalingFlow sf(graph);
        return sf.max();
    }, 10);

    cout << "Scaling flow took " << duration << endl;

}

// Test performance of algorithms
// Output time in seconds

int main() {
    //trickyTest();
    //veryBigTest();
    //hugeTest();
    completeGraphTest();
}

