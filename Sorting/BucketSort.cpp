#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<float> &v) {
    std::vector<std::vector<float>> bucket(v.size());

    for(int i = 0; i < v.size(); i++) {
        int bucketIndex = static_cast<int> (v.size() * (v[i] + 1000) / 2000); // shift + divide + convert;
        bucket[bucketIndex].push_back(v[i]);
    }

    v.clear();
    for(int i = 0; i < bucket.size(); ++i) {
       std::sort(bucket[i].begin(), bucket[i].end());
        
        v.insert(v.end(), bucket[i].begin(), bucket[i].end());
    }
}


int main() {
    std::vector<float> vec = { 900.5, -200.3, 0.0, 500.4, -999.9, 250.1, -100.2 };
    
    bucketSort(vec);
    
    for (float f : vec) {
        std::cout << f << ", ";
    }

    return 0;
}