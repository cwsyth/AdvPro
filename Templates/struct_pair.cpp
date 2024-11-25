#include <iostream>

template<typename T1, typename T2>
struct Pair {
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
void print(const Pair<T1, T2>& p) {
	std::cout << p.first << "-" << p.second << std::endl;
}

int main() {
	Pair<int, int> int_pair = { 1, 2 };
	Pair<int, float> mixed_pair = { 1, 1.1 };

	print(int_pair);
	print(mixed_pair);

	return 0;
}