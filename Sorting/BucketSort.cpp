#include <iostream>
#include <vector>
#include <algorithm>

std::vector<float> bucketSort(std::vector<float> v1) {
    std::vector<std::vector<float>> bucket(v1.size());
    std::vector<float> v2;

    for(int i = 0; i < v1.size(); i++) {
        int bucketIndex = static_cast<int> (v1.size() * (v1[i] + 1000) / 2000); // shift + divide + convert;
        bucket[bucketIndex].push_back(v1[i]);
    }

    // concat
    for(int i = 0; i < v1.size(); ++i) {
        sort(bucket[i].begin(), bucket[i].end());
        v2.insert(v2.end(), bucket[i].begin(), bucket[i].end());
    }

    return v2;
}

int main() {
    std::vector<float> vec = { 900.5, -200.3, 0.0, 500.4, -999.9, 250.1, -100.2 };
    
    std::vector<float> sortedVec = bucketSort(vec);
    
    for(float f : sortedVec) {
        std::cout << f << ", ";
    }

    return 0;
}