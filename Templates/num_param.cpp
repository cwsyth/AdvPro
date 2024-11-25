#include <iostream>

int num_param() {
	return 0;
}

template<typename T, typename... Rest>
int num_param(T first, Rest... rest) {
	return 1 + num_param(rest...);
}

int main() {
	std::cout << num_param(1, 2, 3.5, "Hello", 'c');

	return 0;
}