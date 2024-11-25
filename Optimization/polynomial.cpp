#include <vector>
#include <iostream>

float eval(const std::vector<float>& a, float x) {
    float y = 0;
    int size = a.size(); // determine size once

    // reverse loop + horner's method
    for (int i = 0; i < size; ++i) {
        y = y * x + a[i];
    }
    return y;
}

int main() {
    std::vector<float> v = { 4.0, 3.0, -2.0, 1.0 };  // 4x^3 + 3x^2 - 2x + 1
    float x = 2.0; // = 41

    std::clock_t start = std::clock();

    float result = 0.0;
    for (int i = 0; i < 100000000; ++i) {
        result = eval(v, x);
    }

    std::clock_t end = std::clock();
    std::cout << "Execution time: " << double(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;

    return 0;
}