#include <iostream>
#include <cassert>
#include <limits>
#include <random>

template <typename T, int N>
class Graph {
private:
    T matrix[N][N];

public:
    // Limit for the weight of the edges
    T limit = std::numeric_limits<T>::max();

    /**
     * Constructor of the graph
     */
    Graph() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = (i == j) ? 0 : limit;
            }
        }
    }

    /**
     * Add an edge to the graph
     * @param r row
     * @param c column
     * @param weight Weight of the edge
     */
    void addEdge(int r, int c, T weight) {
        assert(r >= 0 && r < N && c >= 0 && c < N);
        matrix[r][c] = weight;
    }

    /**
     * Get the weight of an edge
     * @param r row
     * @param c column
     * @return Weight of the edge
     */
    T getEdge(int r, int c) const {
        assert(r >= 0 && r < N && c >= 0 && c < N);
        return matrix[r][c];
    }

    /**
     * Print the graph
     */
    void printGraph() const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == limit) {
                    std::cout << "INF ";
                } else {
                    std::cout << matrix[i][j] << "   ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};


/**
 * Generate a random graph with random real weights
 * @param min Minimum weight
 * @param max Maximum weight
 * @return Random graph
 */
template<typename T, int N>
typename std::enable_if<std::is_floating_point<T>::value, Graph<T, N>>::type
generateRandomGraph(T min, T max) {
    Graph<T, N> g;

    std::mt19937 engine(time(nullptr));
    std::uniform_real_distribution<T> dist(min, max);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            T weight = dist(engine);
            g.addEdge(i, j, weight);
            g.addEdge(j, i, weight);
        }
    }

    return g;
}

/**
 * Generate a random graph with random integral weights
 * @param min Minimum weight
 * @param max Maximum weight
 * @return Random graph
 */
template<typename T, int N>
typename std::enable_if<std::is_integral<T>::value, Graph<T, N>>::type
generateRandomGraph(T min, T max) {
    Graph<T, N> g;

    std::mt19937 engine(time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            int weight = dist(engine);
            g.addEdge(i, j, weight);
            g.addEdge(j, i, weight);
        }
    }

    return g;
}