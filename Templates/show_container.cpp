#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename Iterator>
void print(Iterator begin, Iterator end) {
	for (Iterator i = begin; i != end; i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> v(10, 1);
	std::list<int> l = { 1, 2, 3 };

	print(v.begin(), v.end());
	print(l.begin(), l.end());

	return 0;
}