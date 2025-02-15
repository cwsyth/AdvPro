#include <iostream>
#include <string>
#include <vector>

struct Person {
    int key;
    std::string name;
};
const int domain_size= 10;

std::vector<Person> countSortStable(std::vector<Person> v1) {
    std::vector<int> c(domain_size);
    std::vector<Person> v2(v1.size());

    // count keys
    for (Person p : v1) {
        c[p.key - 1]++;
    }

    // cumulative sum
    for (int i = 1; i < domain_size; i++) {
        c[i] = c[i] + c[i - 1];
    }

    // place in correct order
    for (int i = v1.size() - 1; i >= 0; i--) {
        int cIndex = v1[i].key - 1;
        v2[c[cIndex] - 1] = v1[i];
        c[cIndex]--;
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

    std::vector<Person> sortedPersons = countSortStable(persons);

    std::cout << "Sorted Persons by Key:\n";
    for (Person person : sortedPersons) {
        std::cout << "Key: " << person.key << ", Name: " << person.name << '\n';
    }

    return 0;
}