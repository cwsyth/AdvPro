#include <iostream>
#include <string>
#include <vector>
#include <string>

const int domainSize = 10;

struct Person {
    int key;
    std::string name;
};

std::vector<Person> countSort(std::vector<Person> v1) {
    std::vector<int> c(domainSize);
    std::vector<Person> v2(v1.size());

    // count keys
    for(Person person : v1) {
        c[person.key - 1] = c[person.key - 1] + 1;
    }

    // comulative sum
    for(int i = 1; i < domainSize; i++) {
        c[i] = c[i] + c[i - 1];
    }

    // place in correct order
    for(int i = v1.size() - 1; i >= 0; i--) {
        int cIndex = v1[i].key - 1;
        v2[c[cIndex] - 1] = v1[i];
        c[cIndex] = c[cIndex] - 1;
    }

    return v2;
}

int main() {
    std::vector<Person> persons {
        {3, "Steven"},
        {1, "Bob"},
        {2, "Alice"},
        {5, "Christian"},
        {3, "Sebastian"},
        {10, "Edward"}
    };

    std::vector<Person> sortedPersons = countSort(persons);

    std::cout << "Sorted Persons by Key:\n";
    for(Person person : sortedPersons) {
        std::cout << "Key: " << person.key << ", Name: " << person.name << std::endl;
    }

    return 0;
}