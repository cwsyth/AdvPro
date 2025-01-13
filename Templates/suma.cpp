#include <iostream>

template<typename T>
T suma() {
	return T(); // default value of type T with default constructor
}

template<typename T, typename First, typename... Rest>
T suma(First first, Rest... rest) {
	return first + suma<T>(rest...); // suma<T> because we cannot deduce T from the function arguments
}

int main() {
	std::cout << suma<int>(1, 2, 3, 4, 5) << std::endl;
	std::cout << suma<double>(1.1, 2.2, 3.3) << std::endl;

	return 0;
}