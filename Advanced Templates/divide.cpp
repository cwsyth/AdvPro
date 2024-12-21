#include <iostream>
#include <tuple>

std::tuple<int, int> dividir(int x, int y) {
    if (y == 0) {
        throw std::invalid_argument("division by zero");
    }

    int quo = x / y;
    int rem = x % y;

    return std::tuple<int, int>(quo, rem);
}

int main() {
    std::tuple<int, int> t = dividir(10, 3);

    int quo = std::get<0>(t);
    int rem = std::get<1>(t);

    std::cout << "Quotient: " << quo << "\n";
    std::cout << "Remainder: " << rem << "\n";

    return 0;
}