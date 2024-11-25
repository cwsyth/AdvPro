#include <random>
#include <vector>
#include <iostream>
#include <list>

template<template <typename, typename ...> typename Container>
Container<int> generateContainer(int begin, int end, int size) {
	Container<int> v;
	
	std::mt19937 engine(time(nullptr));
	std::uniform_int_distribution<int> dist(begin, end);
	
	for (int i = 0; i < size; i++) {
		v.insert(v.end(), dist(engine));
	}

	return v;
}

int main() {
	std::vector<int> v = generateContainer<std::vector>(5, 15, 10);

	for (int el : v) {
		std::cout << el << " ";
	}
	std::cout << std::endl;



	std::list<int> l = generateContainer<std::list>(0, 20, 10);

	for (int el : l) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	return 0;
}