#include <iostream>

class Stack {
    int * v;
    int top;
    unsigned max_size;

    public:
        Stack(unsigned size) {
            v = new int[size];
            max_size = size;
            top = -1;
        }

        Stack(std::initializer_list<int> list) {
            max_size = list.size();
            v = new int[max_size];
            top = -1;

            for(int num : list) {
                top++;
                v[top] = num;
            }
        }

        // Copy Constructor
        Stack(const Stack& s) {
            max_size = s.max_size;
            top = s.top;
            
            v = new int[max_size];
            for(int i = 0; i < max_size; i++) {
                v[i] = s.v[i];
            }

            std::cout << "Copy constructor called" << std::endl;
        }

        // Move Constructor
        Stack(Stack&& s) {
            v = s.v;
            max_size = s.max_size;
            top = s.top;
            
            s.v = nullptr;
            s.max_size = 0;
            s.top = -1;

            std::cout << "Move constructor called" << std::endl;
        }

        // Copy Assignment
        Stack& operator=(const Stack& s) {
            if(this != &s) {
                delete[] v;

                max_size = s.max_size;
                top = s.top;

                v = new int[max_size];
                for(int i = 0; i < max_size; i++) {
                    v[i] = s.v[i];
                }
            }
            std::cout << "Copy assignment called" << std::endl;

            return *this;
        }

        // Move Assignment
        Stack& operator=(Stack&& s) {
            if(this != &s) {
                delete[] v;

                v = s.v;
                max_size = s.max_size;
                top = s.top;
                
                s.v = nullptr;
                s.max_size = 0;
                s.top = -1;
            }
            std::cout << "Move assignment called" << std::endl;

            return *this;
        }

        Stack(const Stack& s) = delete;
        Stack& operator=(const Stack& s) = delete;

        ~Stack() {
            delete[] v;
            std::cout << "Destructor called" << std::endl;
        }
};

int main() {
    Stack p({2,3,4,5});
}
