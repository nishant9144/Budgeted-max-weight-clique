#pragma once
#include "graph.hpp"
#include <atomic>
#include <vector>

struct BnBResult {
    int max_profit = 0;
    std::vector<int> best_clique;
};

// Recursive Branch and Bound (Algorithm 1 from the assignment).
//
// candidates  : vertices still eligible to extend the current clique
// curr_clique : vertices in the clique built so far
// curr_profit : sum of profits of curr_clique
// curr_cost   : sum of costs   of curr_clique
// result      : updated in-place whenever a better clique is found
void findClique(const Graph& graph,
                std::vector<int> candidates,
                std::vector<int>& curr_clique,
                int curr_profit,
                int curr_cost,
                BnBResult& result);

// Runs the sequential solver on the full graph and returns the best result.
BnBResult solveSequential(const Graph& graph);
