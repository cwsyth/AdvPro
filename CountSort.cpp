// CountSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    int key;
    string name;
};
const int domainSize = 10;

vector<Person> countSort(vector<Person> v1);

int main() {

    vector<Person> persons {
        {3, "Steven"},
        {1, "Bob"},
        {2, "Alice"},
        {5, "Christian"},
        {3, "Sebastian"},
        {10, "Edward"}
    };

    vector<Person> sortedPersons = countSort(persons);

    cout << "Sorted Persons by Key:\n";
    for (Person person : sortedPersons) {
        cout << "Key: " << person.key << ", Name: " << person.name << '\n';
    }

    return 0;
}

vector<Person> countSort(vector<Person> v1) {
    vector<int> c(domainSize);
    vector<Person> v2(v1.size());

    // count keys
    for (Person person : v1) {
        c[person.key - 1] = c[person.key - 1] + 1;
    }

    // comulative sum
    for (int i = 1; i < domainSize; i++) {
        c[i] = c[i] + c[i - 1];
    }

    // place in correct order
    for (int i = v1.size() - 1; i >= 0; i--) {
        int cIndex = v1[i].key - 1;
        v2[c[cIndex] - 1] = v1[i];
        c[cIndex] = c[cIndex] - 1;
    }

    return v2;
}