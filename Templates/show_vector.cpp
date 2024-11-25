#include <iostream>
#include <vector>

template<typename T>
void print(std::vector<T>& v) {
	for (T el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> int_v(10, 1);
	std::vector<float> float_v(10, 2.1);

	print(int_v);
	print(float_v);

	return 0;
}