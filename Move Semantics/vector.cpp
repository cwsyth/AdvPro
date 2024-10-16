#include <iostream>

#define MAX 10

class Vector2 {
    int * v[MAX];
    unsigned size;

    public:
        Vector2(unsigned t) {
            size = t;
            for(unsigned i = 0; i < MAX; i++)
                v[i] = new int[size];
        }

        // Copy Constructor
        Vector2(Vector2& o) {
            size = o.size;

            for(int i = 0; i < MAX; i++) {
                v[i] = new int[size];

                for(int j = 0; j < size; j++) {
                    v[i][j] = o.v[i][j];
                }
            }

            std::cout << "Copy constructor called" << std::endl;
        }

        // Move Constructor
        Vector2(Vector2&& o) {
            size = o.size;

            for(int i = 0; i < MAX; i++) {
                v[i] = o.v[i];
                o.v[i] = nullptr;
            }

            o.size = 0;

            std::cout << "Move constructor called" << std::endl;
        }

        // Copy Assignment
        Vector2& operator=(Vector2& o) {
            if(this != &o) {
                for(int i = 0; i < MAX; i++) {
                    delete[] v[i];
                }

                size = o.size;

                for(int i = 0; i < MAX; i++) {
                    v[i] = new int[size];

                    for(int j = 0; j < size; j++) {
                        v[i][j] = o.v[i][j];
                    }
                }
            }
            std::cout << "Copy assignment called" << std::endl;

            return *this;
        }

        // Move Assignment
        Vector2& operator=(Vector2&& o) {
            if(this != &o) {
                for(int i = 0; i < MAX; i++) {
                    delete[] v[i];
                }

                size = o.size;

                for(int i = 0; i < MAX; i++) {
                    v[i] = o.v[i];
                    o.v[i] = nullptr;
                }

                o.size = 0;
            }
            std::cout << "Move assignment called" << std::endl;

            return *this;
        }

        ~Vector2() {
            for(int i = 0; i < MAX; i++) {
                delete[] v[i];
            }
            std::cout << "Destructor called" << std::endl;
        }
};

/*
int main() {
    Vector2 v1(3);
    Vector2 v2(v1);
    std::cout << v1.size << std::endl;
    std::cout << v2.size << std::endl;

    Vector2 v3(4);
    std::cout << v3.size << std::endl;
    Vector2 v4(std::move(v3));
    std::cout << v4.size << std::endl;
    std::cout << v3.size << std::endl;

    Vector2 v5(5);
    std::cout << v5.size << std::endl;
    v5 = v1;
    std::cout << v5.size << std::endl;

    Vector2 v6(6);
    std::cout << v6.size << std::endl;
    v6 = std::move(v1);
    std::cout << v6.size << std::endl;
    std::cout << v1.size << std::endl;

    return 0;
} */