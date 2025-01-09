//  CopyRight 2024 Harishwar Reddy Erri

#ifndef PHOTOMAGIC_HPP
#define PHOTOMAGIC_HPP

#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {
    void transform(sf::Image& image, FibLFSR* lfsr);
}

#endif
