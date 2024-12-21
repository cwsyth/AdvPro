#include <iostream>
#include <random>
#include <vector>
#include <list>

template<typename Container>
typename std::enable_if<std::is_floating_point<typename Container::value_type>::value, Container>::type
generateContainer(double min_value, double max_value, int size) {
	Container v;

	std::mt19937 engine(time(nullptr));
	std::uniform_real_distribution<double> dist(min_value, max_value);

	for (int i = 0; i < size; i++) {
		v.insert(v.end(), dist(engine));
	}

	return v;
}

template<typename Container>
typename std::enable_if<std::is_integral<typename Container::value_type>::value, Container>::type
generateContainer(int min_value, int max_value, int size) {
	Container v;

	std::mt19937 engine(time(nullptr));
	std::uniform_int_distribution<int> dist(min_value, max_value);

	for (int i = 0; i < size; i++) {
		v.insert(v.end(), dist(engine));
	}

	return v;
}

int main() {
	std::vector<int> intVec = generateContainer<std::vector<int>>(5, 15, 10);
	for (int el : intVec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::list<int> intList = generateContainer<std::list<int>>(0, 20, 10);
	for (int el : intList) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::vector<double> doubleVec = generateContainer<std::vector<double>>(1.0, 5.0, 10);
	for (double el : doubleVec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	return 0;
}