#include <iostream>
#include <random>
#include <vector>
#include <list>

template<typename Container>
Container generateContainer(int min_value, int max_value, int size) {
	using ContainerT = typename Container::value_type;

	Container v;
	std::mt19937 engine(time(nullptr));

	if constexpr (std::is_integral<ContainerT>::value) {
		std::uniform_int_distribution<ContainerT> dist(min_value, max_value);
		for (int i = 0; i < size; i++) {
			v.insert(v.end(), dist(engine));
		}
	}
	else {
		std::uniform_real_distribution<ContainerT> dist(min_value, max_value);
		for (int i = 0; i < size; i++) {
			v.insert(v.end(), dist(engine));
		}
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