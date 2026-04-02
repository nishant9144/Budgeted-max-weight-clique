#pragma once
#include <string>
#include <vector>

struct Vertex {
    int profit;
    int cost;
};

struct Graph {
    int num_vertices;
    int num_edges;
    int budget;
    std::vector<Vertex> vertices;

    // Adjacency matrix for O(1) neighbor lookup.
    // For very large sparse graphs, consider switching to adjacency lists.
    std::vector<std::vector<bool>> adj_matrix;

    bool areAdjacent(int u, int v) const { return adj_matrix[u][v]; }
};

// Parses input file into a Graph. Format:
//   Line 1     : N E B
//   Next N     : profit(v) cost(v)
//   Next E     : u v  (undirected edge)
Graph parseInput(const std::string& filepath);

// Writes result to output file. Format:
//   Line 1: max_profit
//   Line 2: space-separated vertex IDs in ascending order
void writeOutput(const std::string& filepath, int max_profit,
                 const std::vector<int>& clique_vertices);
