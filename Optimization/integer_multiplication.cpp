#include <iostream>

// x*5  = x * x * x * x * x = x*2 + x*2 + x = x << 2 + x
int multiply_by_five(unsigned int x) {
    return (x << 2) + x;
}

int main() {
    std::cout << multiply_by_five(3);

    return 0;
}