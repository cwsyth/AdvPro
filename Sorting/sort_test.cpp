#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <list>

struct Value {
    int key;
    char other[100];
};

/**
 * Generates a vector of random values
 * @param v - vector to be filled
 * @param lower_limit - lower limit of the key values
 * @param upper_limit - upper limit of the key values
 * @param engine - random number generator
 * @param size - size of the vector
 */
void generateVector(std::vector<Value>& v, int lower_limit, int upper_limit, std::mt19937& engine, unsigned int size) {
    std::uniform_int_distribution<int> dist(lower_limit, upper_limit);

    for(unsigned int i = 0; i < size; i++) {
        Value tmp;
        tmp.key = dist(engine);
        memset(tmp.other, 'x', sizeof(tmp.other));

        v.push_back(tmp);
    }
}

/**
 * Sort vector using CountSort
 * @param v1 - vector to be sorted
 * @param domain_size - size of the domain
 */
void countSort(std::vector<Value>& v1, int domain_size) {
    std::vector<int> c(domain_size + 1);
    std::vector<Value> v2(v1.size());

    // count keys
    for(Value el : v1) {
        c[el.key] = c[el.key] + 1;
    }

    // cumulative sum
    for(int i = 1; i <= domain_size; i++) {
        c[i] = c[i] + c[i - 1];
    }

    // place in correct order
    for(int i = v1.size() - 1; i >= 0; i--) {
        int cIndex = v1[i].key;
        v2[c[cIndex] - 1] = v1[i];
        c[cIndex] = c[cIndex] - 1;
    }

    for(unsigned int i = 0; i < v1.size(); i++) {
        v1[i] = v2[i];
    }
}

/**
 * Helper function for extracting digits from a number for RadixSort
 * @param place - place of the digit, starting with 0
 * @param num - number to extract the digit from
 */
int getDigit(int place, int num) {
    int digit = num;

    for(int i = 0; i < place; i++) {
        digit = digit / 10;
    }

    return digit % 10;
}

/**
 * Sort vector using RadixSort
 * @param v - vector to be sorted
 */
void radixSort(std::vector<Value> &v) {
    std::vector<int> keys;

    for(Value el : v) {
        keys.push_back(el.key);
    }

    int maxValue = *std::max_element(keys.begin(), keys.end());
    int numberOfDigits = log10(maxValue) + 1;
    
    for(int i = 0; i < numberOfDigits; i++) {
        std::vector<std::vector<Value>> bucket(10); // digits 0 to 9

        for(unsigned int j = 0; j < v.size(); j++) {
            int digit = getDigit(i, v[j].key);
            bucket[digit].push_back(v[j]);
        }

        // concat
        int overrideIndex = 0;
        for(unsigned int j = 0; j < bucket.size(); j++) {
            for(unsigned int k = 0; k < bucket[j].size(); k++) {
                v[overrideIndex++] = bucket[j][k];
            }
        }
    }
}

/**
 * Sort list using RadixSort
 * @param l - list to be sorted
*/
void radixSortList(std::list<Value> &l) {
    std::vector<int> keys;

    for(Value el : l) {
        keys.push_back(el.key);
    }

    int maxValue = *std::max_element(keys.begin(), keys.end());
    int numberOfDigits = log10(maxValue) + 1;
    
    for(int i = 0; i < numberOfDigits; i++) {
        std::vector<std::vector<Value>> bucket(10); // digits 0 to 9

        for(auto it = l.begin(); it != l.end(); it++) {
            int digit = getDigit(i, it->key);
            bucket[digit].push_back(*it);
        }

        // concat
        auto it = l.begin();
        for(unsigned int j = 0; j < bucket.size(); j++) {
            for(unsigned int k = 0; k < bucket[j].size(); k++) {
                *it++ = bucket[j][k];
            }
        }
    }
}

/**
 * Print vector
 * @param v - vector to be printed
 */
void printVector(std::vector<Value> v) {
    for(Value el : v) {
        std::cout << el.key << " ";
    }
    std::cout << std::endl;
}

/**
 * Print list
 * @param v - list to be printed
 */
void printList(std::list<Value> v) {
    for(Value el : v) {
        std::cout << el.key << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::mt19937 engine(time(nullptr));

    /* 2. count sort */
    // 20 elements with key values in the range [0..255]
    std::vector<Value> v1;
    int v1_domain_size = 255;

    generateVector(v1, 0, v1_domain_size, engine, 20);

    std::cout << "CountSort - Keys original vector: ";
    printVector(v1);

    countSort(v1, v1_domain_size);
    
    std::cout << "CountSort - Keys sorted vector: ";
    printVector(v1);
    std::cout << std::endl;

    // 20 elements with key values in the range [0..65535]
    std::vector<Value> v2;
    int v2_domain_size = 65535;

    generateVector(v2, 0, v2_domain_size, engine, 20);

    std::cout << "CountSort - Keys original vector: ";
    printVector(v2);

    countSort(v2, v2_domain_size);
    
    std::cout << "CountSort - Keys sorted vector: ";
    printVector(v2);
    std::cout << std::endl;



    /* 3. radix sort vector */
    // 20 elements with key values in the range [0..255]
    std::vector<Value> v3;
    generateVector(v3, 0, 255, engine, 20);

    std::cout << "RadixSort - Keys original vector: ";
    printVector(v3);

    radixSort(v3);

    std::cout << "RadixSort - Keys sorted vector: ";
    printVector(v3);
    std::cout << std::endl;

    // 20 elements with key values in the range [0..65535]
    std::vector<Value> v4;
    generateVector(v4, 0, 65535, engine, 20);

    std::cout << "RadixSort - Keys original vector: ";
    printVector(v4);

    radixSort(v4);

    std::cout << "RadixSort - Keys sorted vector: ";
    printVector(v4);
    std::cout << std::endl;



    /* 4. radix sort list */
    // 20 elements with key values in the range [0..255]
    std::vector<Value> v5;
    generateVector(v5, 0, 255, engine, 20);
    
    std::list<Value> l1;
    for(Value el : v5) {
        l1.push_back(el);
    }

    std::cout << "RadixSort - Keys original list: ";
    printList(l1);

    radixSortList(l1);

    std::cout << "RadixSort - Keys sorted list: ";
    printList(l1);
    std::cout << std::endl;

    // 20 elements with key values in the range [0..65535]
    std::vector<Value> v6;
    generateVector(v6, 0, 65535, engine, 20);
    
    std::list<Value> l2;
    for(Value el : v6) {
        l2.push_back(el);
    }

    std::cout << "RadixSort - Keys original list: ";
    printList(l2);

    radixSortList(l2);

    std::cout << "RadixSort - Keys sorted list: ";
    printList(l2);
    std::cout << std::endl;

    return 0;
}
