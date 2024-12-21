#include <iostream>

template<int N, int Base = 1>
struct BinaryToInt {
    static const int result = ((N % 10) * Base) + BinaryToInt<(N / 10), (Base * 2)>::result;
};

template<int Base>
struct BinaryToInt<0, Base> {
    static const int result = 0;
};

int main() {
    int result = BinaryToInt<1101>::result;
    std::cout << result;

    return 0;
}