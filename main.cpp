#include <iostream>
#include "bnb.hpp"
#include "graph.hpp"
#include "bounds.hpp"
#include <mpi.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    const std::string input_filepath  = argv[1];
    const std::string output_filepath = argv[2];

    // TODO: MPI_Init and obtain rank / size
    // int rank, num_processes;
    // MPI_Init(&argc, &argv);
    // MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // MPI_Comm_size(MPI_COMM_WORLD, &num_processes);

    // TODO: Only rank 0 reads input, then broadcasts the graph to all ranks.
    Graph graph = parseInput(input_filepath);

    BnBResult result;

    // TODO: Replace with parallel MPI solver.
    //       Design your work-distribution strategy here.
    //       Each rank should explore a disjoint subset of the search tree,
    //       and ranks must synchronize to share the global best (P_max) for pruning.
    result = solveSequential(graph);

    // TODO: Gather results from all ranks to rank 0 and pick the global best.

    // TODO: Only rank 0 should write the output.
    writeOutput(output_filepath, result.max_profit, result.best_clique);

    // TODO: MPI_Finalize();

    return 0;
}
