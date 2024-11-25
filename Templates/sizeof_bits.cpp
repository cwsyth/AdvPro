#include <iostream>

template<typename T>
size_t sizeof_bits(T& el) {
    return sizeof(el) * 8;
}

int main() {
    int a = 4;
    std::cout << "Size in bits: " << sizeof_bits(a) << " bits" << std::endl;

    return 0;
}