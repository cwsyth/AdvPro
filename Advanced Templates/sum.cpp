#include <iostream>
#include <vector>
#include <list>
#include <complex>

template<typename Iter>
typename std::iterator_traits<Iter>::value_type sum(Iter beg, Iter end) {
	using SumT = typename std::iterator_traits<Iter>::value_type;
	SumT sum = SumT();

	while (beg != end) {
		sum += *beg;
		++beg;
	}

	return sum;
}

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::cout << "Sum of vector: " << sum(vec.begin(), vec.end()) << "\n";

    std::list<double> lst = { 1.1, 2.2, 3.3, 4.4 };
    std::cout << "Sum of list: " << sum(lst.begin(), lst.end()) << "\n";

	std::vector<std::complex<double>> complex_vec = { {1, 2}, {3, 4}, {5, 6} };
	std::cout << "Sum of complex vector: " << sum(complex_vec.begin(), complex_vec.end()) << "\n";

	return 0;
}