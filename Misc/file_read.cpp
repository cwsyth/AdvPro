#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <chrono>

/**
 * Read text from a file
 * @param filename - name of the file
 */
std::vector<std::wstring> readText(std::string filename) {
    std::wifstream file(filename);
    file.imbue(std::locale());

    if (!file.is_open()) {
        std::cerr << "Error: cannot open " << filename << std::endl;
        return {};
    }

    std::vector<std::wstring> words;
    std::wstring line;

    while (std::getline(file, line)) {
        for (wchar_t& ch : line) {
            ch = std::tolower(ch, std::locale());
        }

        std::wstringstream cleaned_line;
        for (wchar_t ch : line) {
            if (std::isalpha(ch, std::locale()) || ch == ' ') {
                cleaned_line << ch;
            }
        }

        std::wstring word;
        while (cleaned_line >> word) {
            words.push_back(word);
        }
    }

    file.close();
    return words;
}

/**
 * Count words using a map
 * @param words - vector of words
 */
std::map<std::wstring, int> countWords(std::vector<std::wstring> words) {
    std::map<std::wstring, int> map;

    for (std::wstring word : words) {
        map[word] += 1;
    }

    return map;
}

/**
 * Count words using an unordered map
 * @param words - vector of words
 */
std::unordered_map<std::wstring, int> countWordsUn(std::vector<std::wstring> words) {
    std::unordered_map<std::wstring, int> map;

    for (std::wstring word : words) {
        map[word] += 1;
    }

    return map;
}

/**
 * Print the top 30 words
 * @param map - map of words
 */
template<typename T>
void printTopWords(T map) {
    std::vector<std::pair<std::wstring, int>> v(map.begin(), map.end());
    std::sort(v.begin(), v.end(), [](std::pair<std::wstring, int> a, std::pair<std::wstring, int > b) -> bool {
        return a.second > b.second;
        });

    if (typeid(map) == typeid(std::map<std::wstring, int>)) {
        std::cout << "Ordered map: " << std::endl;
    }
    else {
        std::cout << "Unordered map: " << std::endl;
    }

    for (unsigned int i = 0; i < v.size(); i++) {
        if (i == 30) break;
        std::wcout << v[i].second << " " << v[i].first << std::endl;
    }
}

int main() {
    std::locale::global(std::locale("es_ES.utf8"));
    std::wcout.imbue(std::locale());

    std::vector<std::wstring> words = readText("texto2.txt");

    int repetitions = 50;

    // Measure time for countWords
    std::map<std::wstring, int> map = countWords(words);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < repetitions; ++i) {
        map = countWords(words);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
    std::wcout << "Execution time for countWords: " << elapsed_time.count() << " seconds" << std::endl;

    printTopWords(map);
    std::cout << std::endl << std::endl;

    // Measure time for countWordsUn
    std::unordered_map<std::wstring, int> unordered_map = countWordsUn(words);
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < repetitions; ++i) {
        unordered_map = countWordsUn(words);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    std::wcout << "Execution time for countWordsUn: " << elapsed_time.count() << " seconds" << std::endl;

    printTopWords(unordered_map);

    return 0;
}
