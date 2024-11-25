#include <iostream>
#include <vector>
#include <string>

template<typename Container, typename Lambda>
std::string format(const Container& c, Lambda l) {
	std::string res = "";

	for (auto el : c) {
		res += l(el);
		res += ", ";
	}

	return res;
}

int main() {
	struct Point {
		float x, y;
	};
	std::vector<Point> v = { {1.1, 2.2}, {3.3, 4.4}, {5.5, 6.6} };

	std::cout << format(v, [](Point value) {
            return "(" + std::to_string(value.x) + "," + std::to_string(value.y) + ")"; 
        }
    );

	return 0;
}