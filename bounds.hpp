#pragma once
#include "graph.hpp"
#include <vector>

// --- Structural Bound (Greedy Graph Coloring) ---
// Partitions candidates into independent sets (color classes) greedily,
// sorted by descending profit. A clique can contain at most one vertex per
// color class, so the bound is the sum of the best profit in each class.
//
// Returns the maximum additional profit achievable from candidates.
int coloringBound(const Graph& graph, const std::vector<int>& candidates);

// --- Resource Bound (Fractional Knapsack) ---
// Treats candidates as knapsack items sorted by efficiency ratio profit/cost.
// Greedily fills the remaining budget, allowing a fractional last item.
//
// Returns the maximum additional profit achievable given remaining_budget.
double knapsackBound(const Graph& graph, const std::vector<int>& candidates,
                     int remaining_budget);
