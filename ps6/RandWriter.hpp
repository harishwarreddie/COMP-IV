// CopyRight 2024 Harishwar Reddy Erri

#ifndef RANDWRITER_HPP
#define RANDWRITER_HPP

#include <string>
#include <map>
#include <vector>
#include <random>
#include <stdexcept>

class RandWriter {
 public:
    RandWriter(const std::string& text, size_t k);
    size_t orderK() const;
    int freq(const std::string& kgram) const;
    int freq(const std::string& kgram, char c) const;
    char kRand(const std::string& kgram);
    std::string generate(const std::string& kgram, size_t L);
    std::string validKgram;
 private:
    size_t k;
    std::map<std::string, std::map<char, int>> freqTable;
    std::mt19937 rng;
    std::string inputText;
    std::string trimToLength(const std::string& text, size_t L) const {
        if (text.length() <= L) return text;
        return text.substr(0, L);
    }
};

#endif  // RANDWRITER_HPP
