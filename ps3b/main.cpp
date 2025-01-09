// CopyRight 2024 Harishwar Reddy

#include <iostream>
#include <chrono>
#include "Universe.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " T dt" << std::endl;
        return 1;
    }

    double T = std::stod(argv[1]);
    double dt = std::stod(argv[2]);

    NB::Universe universe;
    std::cin >> universe;

    sf::RenderWindow window(sf::VideoMode(600, 600), "N-Body Simulation");

    // Optional: Disable vertical sync if you're seeing warnings
    window.setVerticalSyncEnabled(false);

    // Load background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("image.png")) {
        std::cerr << "Failed to load background image" << std::endl;
        return 1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height);

    // Load music
    sf::Music music;
    if (!music.openFromFile("music.wav")) {
        std::cerr << "Failed to load music" << std::endl;
        return 1;
    }
    bool musicPlaying = false;
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return 1;
    }

    // Set up text object for elapsed time display
    sf::Text elapsedTimeText;
    elapsedTimeText.setFont(font);
    elapsedTimeText.setCharacterSize(24);  // in pixels
    elapsedTimeText.setFillColor(sf::Color::White);
    elapsedTimeText.setPosition(10, 10);  // Top-left corner

    // Start tracking elapsed time
    auto start_time = std::chrono::high_resolution_clock::now();

    double t = 0.0;
    while (window.isOpen() && t < T) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M) {
                if (musicPlaying) {
                    music.pause();
                    musicPlaying = false;
                } else {
                    music.play();
                    musicPlaying = true;
                }
            }
        }

        universe.step(dt);
        t += dt;

        // Measure elapsed time and update the text
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = current_time - start_time;
        double elapsed_time = time_span.count();

        // Update the displayed text with the elapsed time
        elapsedTimeText.setString("Elapsed Time: " + std::to_string(elapsed_time) + " seconds");

        window.clear();
        window.draw(backgroundSprite);
        universe.draw(window);  // Draw celestial bodies
        window.draw(elapsedTimeText);  // Draw elapsed time text
        window.display();
    }

    // After the simulation finishes, print the final universe state
    std::cout << universe;

    return 0;
}
