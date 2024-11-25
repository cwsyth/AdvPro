#include <vector>
#include <iostream>
#include <ctime>

// Return the position of the element.
// Out of bound if the element doesn’t exist.
unsigned search(std::vector<int>& v, int x) {
    unsigned pos = 0;
    int size = v.size(); // determine size once
    v.push_back(x); // use sentinel

    while (v[pos] != x) {
        pos++;
    }

    v.pop_back();

    return (pos < size) ? pos : size;
}

int main() {
    std::vector<int> v(1000, 0);
    int x = 42;
    v[500] = x;

    std::clock_t start = std::clock();

    for (int i = 0; i < 3000000; ++i) {
        unsigned pos = search(v, x);
    }

    std::clock_t end = std::clock();
    std::cout << "Execution time: " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;

    return 0;
}