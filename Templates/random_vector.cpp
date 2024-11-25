#include <random>
#include <vector>
#include <iostream>

template<typename T>
std::vector<T> generateVector(T begin, T end, int size) {
	static_assert(std::numeric_limits<T>::is_integer, "Type must be integer");
	std::vector<T> v;
	
	std::mt19937 engine(time(nullptr));
	std::uniform_int_distribution<int> dist(begin, end);
	
	for (int i = 0; i < size; i++) {
		v.push_back(dist(engine));
	}

	return v;
}

int main() {
	std::vector<int> v = generateVector(5, 15, 10);

	for (int el : v) {
		std::cout << el << " ";
	}

	return 0;
}