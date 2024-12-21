#include <iostream>
#include <vector>

template<int N, typename T>
struct Product {
    static T result(T* v) {
        return v[N-1] * Product<(N - 1), T>::result(v);
    }
};

template<typename T>
struct Product<1, T> {
    static T result(T* v) {
        return v[0];
    }
};

// convenience function
template<int N, typename T>
T product(T* v) {
    return Product<N, T>::result(v);
}

int main() {
    int v[] = { 1, 2, 3 };
    int result = product<3>(v);

    std::cout << result;

    return 0;
}