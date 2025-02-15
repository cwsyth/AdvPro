#include "graph.h"
#include <iostream>
#include <vector>

/**
 * Floyd's algorithm to find the minimum distance and path between all nodes
 * @param g Graph to find the minimum distance and path
 * @return Pair of Graph with the minimum distance and predecessor matrix
 */
template<typename T, int N>
std::pair<Graph<T, N>, std::vector<std::vector<int>>> floyd(Graph<T, N> g) {
    Graph<T, N> min_dist;
    std::vector<std::vector<int>> intermediate(N, std::vector<int>(N, -1));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            min_dist.addEdge(i, j, g.getEdge(i, j));

            if (g.getEdge(i, j) != g.limit) {
                intermediate[i][j] = i;
            }
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(g.getEdge(i, k) != g.limit && g.getEdge(k, j) != g.limit) {
                    if(min_dist.getEdge(i, j) > (g.getEdge(i, k) + g.getEdge(k, j))) {
                        min_dist.addEdge(i, j, g.getEdge(i, k) + g.getEdge(k, j));
                        intermediate[i][j] = intermediate[k][j];
                    }
                }
            }
        }
    }

    return {min_dist, intermediate};
}

/**
 * Print the path between two nodes
 * @param intermediate Predecessor matrix
 * @param i Start node
 * @param j End node
 */
void printPath(std::vector<std::vector<int>> intermediate, int i, int j) {
    if(i != j) {
        printPath(intermediate, i, intermediate[i][j]);
        std::cout <<  " -> " << j;
    }
    else if (i == j) {
        std::cout << i;
    }
    else {
        std::cout << "No path";
    }
}

int main() {
    // Generate a random graph
    Graph<float, 8> g = generateRandomGraph<float, 8>(0.5, 5);

    // Multiply approximately half of the edges by 5
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < i; j++) {
            if((i + j) % 2 == 0) {
                g.addEdge(i, j, g.getEdge(i, j) * 5);
                g.addEdge(j, i, g.getEdge(j, i) * 5);
            }
        }
    }

    std::cout << "Adjacency Matrix:" << std::endl;
    g.printGraph();


    // Floyd's algorithm
    auto floyd_result = floyd(g);
    Graph<float, 8> min_dist = floyd_result.first;
    std::vector<std::vector<int>> intermediate = floyd_result.second;

    std::cout << "Floyd Algorithm:" << std::endl;
    min_dist.printGraph();

    std::cout << "Floyd Algorithm Path:" << std::endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 8; j++) {
            printPath(intermediate, i, j);
            std::cout << std::endl;
        }
    }

    return 0;
}