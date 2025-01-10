#include <iostream>
#include <vector>
#include <list>
#include <cmath>

class ArithmeticMeanPolicy {
public:
	template<typename T>
	static void sum(T& acc, T value) {
		acc += value;
	}

	template<typename T>
	static void div(T& total, int count) {
		total /= count;
	}
};

class GeometricMeanPolicy {
public:
	template<typename T>
	static void sum(T& acc, T value) {
		acc += std::log(value);
	}

	template<typename T>
	static void div(T& total, int count) {
		total = std::exp(total / count);
	}
};

class HarmonicMeanPolicy {
public:
	template<typename T>
	static void sum(T& acc, T value) {
		acc += (1 / value);
	}

	template<typename T>
	static void div(T& total, int count) {
		total = count / total;
	}
};

template<
    typename Policy = ArithmeticMeanPolicy,
    typename Iter
>
typename std::iterator_traits<Iter>::value_type mean(Iter beg, Iter end) {
	using SumT = typename std::iterator_traits<Iter>::value_type;

	SumT total = 0;
	int count = 0;

	while (beg != end) {
		Policy::sum(total, *beg);
		++count;
		++beg;
	}
	Policy::div(total, count);

	return total;
}

int main() {
	std::vector<double> vec = { 1, 2, 3, 4, 5 };
	std::cout << "Arithmetic mean of vector: " << mean(vec.begin(), vec.end()) << "\n";

	std::list<double> lst = { 1.1, 2.2, 3.3, 4.4 };
	std::cout << "Arithmetic mean of list : " << mean(lst.begin(), lst.end()) << "\n";

	std::cout << "Geometric mean of vector: " << mean<GeometricMeanPolicy>(vec.begin(), vec.end()) << "\n";
	std::cout << "Harmonic mean of vector: " << mean<GeometricMeanPolicy>(vec.begin(), vec.end()) << "\n";

	return 0;
}