#include <ctime>
#include <iostream>
#include <vector>

// compile command without vectorization: g++ add_vectors.cpp -o add_vectors
// compile command with vectorization: g++ add_vectors.cpp -o add_vectors -O3

void addVectors(std::vector<float>& a, std::vector<float>& b, std::vector<float>& res) {
    int size = a.size();

    for (int i = 0; i < size; ++i) {
        res[i] = a[i] + b[i];
    }
}

int main() {
    int size = 100000000;
    std::vector<float> a(size, 1.0f);
    std::vector<float> b(size, 2.0f);
    std::vector<float> res(size, 0.0f);

    std::clock_t start = std::clock();

    addVectors(a, b, res);

    std::clock_t end = std::clock();
    std::cout << "Execution time: " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;

    return 0;
}