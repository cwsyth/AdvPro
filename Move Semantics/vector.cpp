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
