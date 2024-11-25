#include <iostream>

int count_bits(unsigned int x) {
    int res = 0;

    while(x != 0) {
        res += (x & 1);
        x >>= 1;
    }

    return res;
}

int main() {
    std::cout << count_bits(7);

    return 0;
}