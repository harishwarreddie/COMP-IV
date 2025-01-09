// CopyRight 2024 Harishwar Reddy Erri

#include <iostream>
#include <string>
#include "RandWriter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./TextWriter <k> <L>" << std::endl;
        return 1;
    }

    size_t k = static_cast<size_t>(std::stoi(argv[1]));
    size_t L = static_cast<size_t>(std::stoi(argv[2]));
    std::string inputText;
    while (std::getline(std::cin, inputText)) {
        if (!inputText.empty()) break;
    }
    try {
        RandWriter rw(inputText, k);
        std::string initialKGram = inputText.substr(0, k);
        std::string generatedText = rw.generate(initialKGram, L);
        std::cout << generatedText << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
