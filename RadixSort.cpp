// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void radixSort(vector<int> &v);
int getDigit(int place, int num);

int main() {
    vector<int> v = { 403, 16, 239, 821, 9, 342, 910, 524, 373, 145 };

    radixSort(v);
}

int getDigit(int place, int num) {
    int digit = num;

    for (int i = 0; i < place; i++) {
        digit = digit / 10;
    }

    return digit % 10;
}

void radixSort(vector<int> &v) {
    int maxValue = *std::max_element(v.begin(), v.end());
    int numberOfDigits = log10(maxValue) + 1;
    
    for (int i = 0; i < numberOfDigits; i++) {
        std::cout << "Current digit " << i+1 << "\n";

        vector<vector<int>> bucket(10); // digits 0 to 9

        for (int j = 0; j < v.size(); j++) {
            int digit = getDigit(i, v[j]);
            bucket[digit].push_back(v[j]);
        }

        // print auxiliary list
        for (int j = 0; j < bucket.size(); j++) {
            std::cout << "Bucket " << j << ": ";
            for (int k = 0; k < bucket[j].size(); k++) {
                std::cout << bucket[j][k] << ", ";
            }
            cout << '\n';
        }

        // concat
        int overrideIndex = 0;
        for (int j = 0; j < bucket.size(); j++) {
            for (int k = 0; k < bucket[j].size(); k++) {
                v[overrideIndex++] = bucket[j][k];
            }
        }

        cout << "current result: ";
        for (int num : v) {
            cout << num << ", ";
        }
        cout << '\n' << '\n';
    }
}