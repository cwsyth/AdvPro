#include <iostream>
#include <vector>
#include <cmath>

int getChar(int place, std::string str) {
    /*if (place >= str.length()) {
        return ' ';
    }*/ // fixed size 20 chars
    return static_cast<int> (str[place]);
}

void radixSort(std::vector<std::string>& v) {
    int numberOfChars = 20; // fixed size

    for(int i = numberOfChars - 1; i >= 0; i--) {
        std::cout << "Current char (digit) " << 20 - i << "\n";

        std::vector<std::vector<std::string>> bucket(256);

        for(int j = 0; j < v.size(); j++) {
            int digit = getChar(i, v[j]);
            bucket[digit].push_back(v[j]);
        }

        // print auxiliary list
        for(int j = 0; j < bucket.size(); j++) {
            if (!bucket[j].empty()) {
                std::cout << "Bucket " << j << ": ";
                std::cout << "Bucket " << j << " (ASCII " << char(j) << "): ";
                for (int k = 0; k < bucket[j].size(); k++) {
                    std::cout << bucket[j][k] << ", ";
                }
                std::cout << '\n';
            }
        }

        // concat
        int overrideIndex = 0;
        for(int j = 0; j < bucket.size(); j++) {
            for (int k = 0; k < bucket[j].size(); k++) {
                v[overrideIndex++] = bucket[j][k];
            }
        }

        std::cout << "current result: ";
        for(std::string str : v) {
            std::cout << str << ", ";
        }
        std::cout << std::endl << std::endl;
    }
}

int main() {
    std::vector<std::string> v = {
        "radixsortexample000",
        "example00002example",
        "sort0003radix000003",
        "sortexample00000000",
        "stringsortingexampl",
        "000example00000000x",
    };

    radixSort(v);
}