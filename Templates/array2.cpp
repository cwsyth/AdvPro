#include <iostream>
#include <stdexcept>

template<typename T, int SIZE>
class Array2 {
	T data[SIZE];

public:
	T& operator[](int index);

	constexpr size_t size() const {
		return SIZE;
	}

	T sum();
};

template<typename T, int SIZE>
T& Array2<T, SIZE>::operator[](int index) {
	if (index >= SIZE) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

template<typename T, int SIZE>
T Array2<T, SIZE>::sum() {
	T sum = T();

	for (T el : data) {
		sum += el;
	}

	return sum;
}

int main() {
	Array2<int, 2> arr;
	arr[0] = 1;
	arr[1] = 2;

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << arr.sum();

	return 0;
}