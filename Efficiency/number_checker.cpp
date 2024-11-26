#include <iostream>

// least efficient - more operations & iterations
bool check_even1(int n) {
    while(n > 1) {
        n -= 2;
    }

    return n == 0;
}

// more efficient - single operation
bool check_even2(int n) {
    return n % 2 == 0;
}

// most efficient - binary operation
bool check_even3(int n) {
    return (n & 1) == 0;
}

// least efficient
bool check_eight1(int n) {
    while(n > 1) {
        n -= 8;
    }

    return n == 0;
}

// more efficient
bool check_eight2(int n) {
    return n % 8 == 0;
}

// most efficient
bool check_eight3(int n) {
    return (n & 7) == 0;
}