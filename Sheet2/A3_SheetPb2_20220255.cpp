// File name: problem 2 Assignment 3 task1
// Purpose: Documnet similarity
// Author(s): Kermina Nashaat Shafeik
// ID(s): 20220255
// Section: s7,8
// Date:6/12/2023
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <valarray>

class StringSet {
public:
    StringSet(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::transform(line.begin(), line.end(), line.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            std::replace_if(line.begin(), line.end(),
                            [](unsigned char c) { return std::ispunct(c); }, ' ');
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                words.insert(word);
            }
        }
    }

    StringSet(const std::vector<std::string>& tokens) {
        for (const auto& token : tokens) {
            std::string word;
            for (const auto& c : token) {
                if (std::isalnum(c)) {
                    word += std::tolower(c);
                }
            }
            if (!word.empty()) {
                words.insert(word);
            }
        }
    }

    void add(const std::string& word) {
        std::string w;
        for (const auto& c : word) {
            if (std::isalnum(c)) {
                w += std::tolower(c);
            }
        }
        if (!w.empty()) {
            words.insert(w);
        }
    }

    void remove(const std::string& word) {
        std::string w;
        for (const auto& c : word) {
            if (std::isalnum(c)) {
                w += std::tolower(c);
            }
        }
        if (!w.empty()) {
            words.erase(w);
        }
    }

    void clear() {
        words.clear();
    }

    int size() const {
        return words.size();
    }

    void output() const {
        for (const auto& word : words) {
            std::cout << word << std::endl;
        }
    }

    StringSet operator+(const StringSet& other) const {
        StringSet result(*this);
        result.words.insert(other.words.begin(), other.words.end());
        return result;
    }

    StringSet() = default;

    StringSet operator*(const StringSet& other) const {
        StringSet result;  // This line is correct
        std::set_intersection(words.begin(), words.end(),
                              other.words.begin(), other.words.end(),
                              std::inserter(result.words, result.words.begin()));
        return result;
    }



    double similarity(const StringSet& other) const {
        std::set<std::string> intersection;
        std::set_intersection(words.begin(), words.end(),
                              other.words.begin(), other.words.end(),
                              std::inserter(intersection, intersection.begin()));
        double numerator = intersection.size();
        double denominator = std::sqrt(words.size() * other.words.size());
        return numerator / denominator;
    }

private:
    std::set<std::string> words;
};
int main() {
    // Create StringSet from a file
    StringSet setFromFile("C:\\Users\\Kermina\\Desktop\\OOP assignment 3\\Document1.txt");
    std::cout << "Set from file:" << std::endl;
    setFromFile.output();
    std::cout << "Size: " << setFromFile.size() << std::endl;

    // Create StringSet from a vector of strings
    std::vector<std::string> tokens = {"vanilla", "ice", "cream", "cookies"};
    StringSet setFromVector(tokens);
    std::cout << "\nSet from vector:" << std::endl;
    setFromVector.output();
    std::cout << "Size: " << setFromVector.size() << std::endl;

    // Add and remove strings
    setFromVector.add("brownie");
    setFromVector.remove("cookies");
    std::cout << "\nAfter adding 'brownie' and removing 'cookies':" << std::endl;
    setFromVector.output();
    std::cout << "Size: " << setFromVector.size() << std::endl;

    // Union and intersection of sets
    StringSet unionSet = setFromFile + setFromVector;
    StringSet intersectionSet = setFromFile * setFromVector;
    std::cout << "\nUnion Set:" << std::endl;
    unionSet.output();
    std::cout << "Size: " << unionSet.size() << std::endl;
    std::cout << "\nIntersection Set:" << std::endl;
    intersectionSet.output();
    std::cout << "Size: " << intersectionSet.size() << std::endl;

    // Similarity between sets
    double similarity = setFromFile.similarity(setFromVector);
    std::cout << "\nSimilarity between sets: " << similarity << std::endl;

    return 0;
}
