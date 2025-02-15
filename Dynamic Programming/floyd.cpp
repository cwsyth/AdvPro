#include "graph.h"
#include <iostream>

/**
 * Floyd's algorithm to find the minimum distance between all nodes
 * @param g Graph to find the minimum distance
 * @return Graph with the minimum distance between all nodes
 */
template<typename T, int N>
Graph<T, N> floyd(Graph<T, N> g) {
    Graph<T, N> min_dist;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            min_dist.addEdge(i, j, g.getEdge(i, j));
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(g.getEdge(i, k) != g.limit && g.getEdge(k, j) != g.limit) {
                    if(min_dist.getEdge(i, j) > (g.getEdge(i, k) + g.getEdge(k, j))) {
                        min_dist.addEdge(i, j, g.getEdge(i, k) + g.getEdge(k, j));
                    }
                }
            }
        }
    }

    return min_dist;
}

int main() {
    // Generate a random graph
    Graph<float, 6> g = generateRandomGraph<float, 6>(0.5, 5);

    // Multiply approximately half of the edges by 5
    for(int i = 0; i < 6; i++) {
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
    Graph<float, 6> min_dist = floyd(g);
    std::cout << "Floyd Algorithm:" << std::endl;
    min_dist.printGraph();

    return 0;
}