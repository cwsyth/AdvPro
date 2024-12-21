#include <iostream>

template<int N, typename T>
struct Init {
	static void result(T* v, T x) {
		v[N-1] = x;
		Init<(N - 1), T>::result(v, x);
	}
};

template<typename T>
struct Init<1, typename T> {
	static void result(T* v, T x) {
		v[0] = x;
	}
};

template<int N, typename T>
void inicializa(T* v, T x) {
	return Init<N, T>::result(v, x);
}

int main() {
	const int TAM = 4;
	int v[TAM];

	inicializa<TAM>(v, 3);

	for (int el : v) {
		std::cout << el << " ";
	}

	return 0;
}