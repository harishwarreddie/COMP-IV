// CopyRight 2024 Harishwar Reddy Erri

#include <ostream>
#include <iostream>
#include "RandWriter.hpp"

RandWriter::RandWriter(const std::string& text, size_t k) : k(k), rng(std::random_device {}()) {
    if (text.length() < k) {
        throw std::invalid_argument("Text length must be at least k.");
    }
    size_t textLength = text.length();
    std::string extendedText = text + text.substr(0, k);
    for (size_t i = 0; i < textLength; ++i) {
        std::string kgram = extendedText.substr(i, k);
        char nextChar = extendedText[i + k];
        freqTable[kgram][nextChar]++;
    }
}
size_t RandWriter::orderK() const {
    return k;
}

int RandWriter::freq(const std::string& kgram) const {
    if (kgram.length() != k) {
        throw std::invalid_argument("kgram must be of length k.");
    }
    auto it = freqTable.find(kgram);
    if (it == freqTable.end()) {
        return 0;
    }
    int total = 0;
    for (const auto& pair : it->second) {
        total += pair.second;
    }
    return total;
}

int RandWriter::freq(const std::string& kgram, char c) const {
    if (kgram.length() != k) {
        throw std::invalid_argument("kgram must be of length k.");
    }
    if (freqTable.find(kgram) == freqTable.end()) {
        return 0;
    }
    return freqTable.at(kgram).count(c) ? freqTable.at(kgram).at(c) : 0;
}

char RandWriter::kRand(const std::string& kgram) {
    if (kgram.length() != k) {
        throw std::invalid_argument("kgram must be of length k.");
    }
    auto it = freqTable.find(kgram);
    if (it == freqTable.end()) {
        throw std::invalid_argument("kgram not found in frequency table.");
    }
    int total = 0;
    for (const auto& pair : it->second) {
        total += pair.second;
    }
    if (total == 0) {
        throw std::runtime_error("Total frequency is zero, cannot select random character.");
    }
    std::uniform_int_distribution<> dist(1, total);
    int r = dist(rng);
    for (const auto& pair : it->second) {
        r -= pair.second;
        if (r <= 0) {
            return pair.first;
        }
    }
    throw std::runtime_error("Unexpected error in kRand.");
}

std::string RandWriter::generate(const std::string& kgram, size_t L) {
    if (k == 0) {
        throw std::invalid_argument("Cannot generate text with k = 0");
    }
    if (kgram.size() != k) {
        throw std::invalid_argument("kgram must be of length k");
    }
    if (L < k) {
        throw std::invalid_argument("L must be at least k");
    }

    std::string result = kgram;
    while (result.length() < L) {
        std::string currentKGram = result.substr(result.size() - k, k);
        char next_char;

        try {
            next_char = kRand(currentKGram);
        } catch (const std::exception& e) {
            std::cerr << "Warning: " << e.what()
                      << ". Using fallback strategy for kgram: " << currentKGram << std::endl;
            next_char = inputText[rng() % inputText.size()];
        }
        result += next_char;
    }

    return result.substr(0, L);
}
