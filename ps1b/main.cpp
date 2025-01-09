//  CopyRight 2024 Harishwar Reddy Erri

#include <iostream>
#include <bitset>
#include "PhotoMagic.hpp"
#include "FibLFSR.hpp"
#include <SFML/Graphics.hpp>

// A new feature that transforms an alphanumeric seed into a binary string
std::string alphanumericToBinary(const std::string& seed1) {
    std::string BSeed;
    for (char c : seed1) {
        if (std::isalnum(c)) {
            std::bitset<8> bits(c);
            BSeed += bits.to_string();
        }
    }
    return BSeed;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input-file> <output-file> <alphanumeric-seed>\n";
        return 1;
    }
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string ANSeed = argv[3];
    std::string BSeed = alphanumericToBinary(ANSeed);
    while (BSeed.length() < 16) {
        BSeed += BSeed;
    }
    BSeed = BSeed.substr(0, 16);
    sf::Image image;
    if (!image.loadFromFile(inputFile)) {
        std::cerr << "Error: Could not load input file: " << inputFile << "\n";
        return 1;
    }
    sf::RenderWindow window1(sf::VideoMode(image.getSize().x, image.getSize().y), "Original Image");
    sf::Texture T1;
    T1.loadFromImage(image);
    sf::Sprite sprite1(T1);
    PhotoMagic::FibLFSR lfsr(BSeed);
    PhotoMagic::transform(image, &lfsr);
    if (!image.saveToFile(outputFile)) {
        std::cerr << "Error: Could not save output file: " << outputFile << "\n";
        return 1;
    }
    sf::RenderWindow window2(sf::VideoMode(image.getSize().x,
    image.getSize().y), "Encrypted Image");
    sf::Texture T2;
    T2.loadFromImage(image);
    sf::Sprite sprite2(T2);
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event E;
        while (window1.pollEvent(E)) {
            if (E.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(E)) {
            if (E.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }
    return 0;
}
