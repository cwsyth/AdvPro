#include <iostream>
#include <type_traits>

class Complex {
    float real, im;
};

template<typename T>
struct My_is_arithmetic {
    static constexpr bool value = std::true_type::value;
};

template<>
struct My_is_arithmetic<float*> {
    static constexpr bool value = std::false_type::value;
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "My_is_arithmetic<Complex>::value -> " << My_is_arithmetic<class Complex>::value << "\n";

    std::cout << "My_is_arithmetic<int>::value -> " << My_is_arithmetic<int>::value << "\n";

    std::cout << "My_is_arithmetic<float*>::value -> " << My_is_arithmetic<float*>::value << "\n";

	return 0;
}