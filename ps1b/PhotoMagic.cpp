//  CopyRight 2024 Harishwar Reddy Erri

#include <SFML/Graphics.hpp>
#include "PhotoMagic.hpp"

namespace PhotoMagic {
    void transform(sf::Image& image, FibLFSR* lfsr) {
        sf::Vector2u size = image.getSize();
        for (unsigned int x = 0; x < size.x; ++x) {
            for (unsigned int y = 0; y < size.y; ++y) {
                // Get pixel color
                sf::Color pixel = image.getPixel(x, y);

                // XOR the red, green, and blue channels with LFSR
                pixel.r ^= lfsr->generate(8);
                pixel.g ^= lfsr->generate(8);
                pixel.b ^= lfsr->generate(8);

                // Set transformed pixel back into the image
                image.setPixel(x, y, pixel);
            }
        }
    }
}  // namespace PhotoMagic
