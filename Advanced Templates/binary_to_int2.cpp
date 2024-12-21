#include <iostream>

constexpr int BinaryToInt(int N, int Base = 1) {
    return (N > 0) ? ((N % 10) * Base) + BinaryToInt((N / 10), (Base * 2)) : 0;
};

int main() {
    int result = BinaryToInt(1101);
    std::cout << result;

    return 0;
}