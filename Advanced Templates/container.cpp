#include <iostream>
#include <random>
#include <vector>
#include <list>

template<typename Container>
Container generateContainer(int min_value, int max_value, int size) {
	using ContainerT = typename Container::value_type;
	static_assert(std::is_integral<ContainerT>::value, "ContainerT must be an integer type");

	Container v;

	std::mt19937 engine(time(nullptr));
	std::uniform_int_distribution<int> dist(min_value, max_value);

	for (int i = 0; i < size; i++) {
		v.insert(v.end(), dist(engine));
	}

	return v;
}

int main() {
	std::vector<int> v = generateContainer<std::vector<int>>(5, 15, 10);

	for (int el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;



	std::list<int> l = generateContainer<std::list<int>>(0, 20, 10);

	for (int el : l) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	return 0;
}