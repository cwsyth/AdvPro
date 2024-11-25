#include <iostream>
#include <limits>

int main() {
	std::cout << "max int: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "max long: " << std::numeric_limits<long>::max() << std::endl;
	std::cout << "max long long:" << std::numeric_limits<long long>::max() << std::endl;

	return 0;
}