// CopyRight 2024 Harishwar Reddy Erri

#include <iostream>
#include <SFML/Graphics.hpp>
#include "penta.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0]
        << " <base_length> <recursion_levels>" << std::endl;
        return EXIT_FAILURE;
    }

    double baseSize = std::stod(argv[1]);
    int recursionLevels = std::stoi(argv[2]);

    sf::RenderWindow fractalWindow(sf::VideoMode(500, 500),
    "Pentaflake Generator");
    PentaflakeDrawer fractal(baseSize, recursionLevels);
    fractal.create(fractalWindow.getSize().x / 2.0,
    fractalWindow.getSize().y / 2.0);
    fractal.loadMusic();  // Load music files

    sf::Clock clock;

    while (fractalWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event userEvent;
        while (fractalWindow.pollEvent(userEvent)) {
            if (userEvent.type == sf::Event::Closed) {
                fractalWindow.close();
            }
            if (userEvent.type == sf::Event::KeyPressed) {
                switch (userEvent.key.code) {
    case sf::Keyboard::R:
        fractal.toggleRotation(true);
        break;
    case sf::Keyboard::L:
        fractal.toggleRotation(false);
        break;
    case sf::Keyboard::O:
        fractal.reset();
        break;
    case sf::Keyboard::X:
        fractal.toggleXRotation();
        break;
    case sf::Keyboard::Y:
        fractal.toggleYRotation();
        break;
    case sf::Keyboard::Q:
        fractal.zoomIn();
        break;
    case sf::Keyboard::W:
        fractal.zoomOut();
        break;
    default:
        // Do nothing for other keys
        break;
}
            }
        }

        fractal.update(deltaTime.asSeconds());
        fractal.updateAudio();

        fractalWindow.clear(sf::Color::Black);
        fractalWindow.draw(fractal);
        fractalWindow.display();
    }

    return EXIT_SUCCESS;
}
