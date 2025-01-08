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
                if(max_size != s.max_size) {
                    delete[] v;
                    max_size = s.max_size;
                    top = s.top;
                    v = new int[max_size];
                }

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

/*
int main() { 
    Stack s1(3);
    std::cout << s1.max_size << std::endl;
    
    Stack s2(s1);
    std::cout << s2.max_size << std::endl;

    Stack s3(std::move(s1));
    std::cout << s3.max_size << std::endl;
    std::cout << s1.max_size << std::endl;

    Stack s4(5);
    std::cout << s4.max_size << std::endl;

    Stack s5(6);
    std::cout << s5.max_size << std::endl;

    s5 = s4;
    std::cout << s5.max_size << std::endl;

    Stack s6(7);
    std::cout << s6.max_size << std::endl;
    s6 = std::move(s4);
    std::cout << s6.max_size << std::endl;
    std::cout << s4.max_size << std::endl; 

    return 0;
} */