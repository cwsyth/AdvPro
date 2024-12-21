#include <iostream>
#include <type_traits>

class Complejo {
    float real, im;
};

template<typename T>
struct My_is_arithmetic {
    static constexpr bool value = std::is_arithmetic<T>::value;
};

template<>
struct My_is_arithmetic<class Complejo> {
    static constexpr bool value = true;
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "My_is_arithmetic<Complejo>::value -> " << My_is_arithmetic<class Complejo>::value << "\n";

    std::cout << "My_is_arithmetic<int>::value -> " << My_is_arithmetic<int>::value << "\n";

    std::cout << "My_is_arithmetic<float*>::value -> " << My_is_arithmetic<float*>::value << "\n";

	return 0;
}