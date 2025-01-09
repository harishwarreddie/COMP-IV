// Copyright 2024 Harishwar Reddy Erri

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Universe.hpp"

int main() {
    NB::Universe cosmos;
    std::cin >> cosmos;

    const int displaySize = 600;
    sf::RenderWindow display(sf::VideoMode(displaySize, displaySize), "NBody Simulation");

    cosmos.setupScene("image.png");
    cosmos.setupAmbience("music.wav");

    float scaleFactor = displaySize / (2 * cosmos.simulationBoundary());

    sf::View view(sf::FloatRect(0, 0, displaySize, displaySize));
    display.setView(view);

    while (display.isOpen()) {
        sf::Event event;
        while (display.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                display.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::M)
                    cosmos.toggleAmbience();
                else if (event.key.code == sf::Keyboard::Escape)
                    display.close();
            }
        }

        display.clear(sf::Color::Black);

        for (size_t i = 0; i < cosmos.entityCount(); ++i) {
            auto& entity = cosmos.accessEntity(i);
            sf::Vector2f position = entity.getState().location;
            sf::Vector2f screenPosition(
                (position.x + cosmos.simulationBoundary()) * scaleFactor,
                (cosmos.simulationBoundary() - position.y) * scaleFactor);
            entity.updateScreenPosition(screenPosition);
        }

        cosmos.render(display);
        display.display();
    }

    return 0;
}
