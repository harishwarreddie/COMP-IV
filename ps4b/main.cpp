// CopyRight 2024 Harishwar Reddy Erri

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sokoban.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level_file>\n";
        return 1;
    }

    SB::Sokoban sokoban(argv[1]);

    sf::RenderWindow window(sf::VideoMode(sokoban.width() * 64, sokoban.height() * 64), "Sokoban");

    // Timer setup
    sf::Clock gameClock;
    sf::Text timerText;
    sf::Font font;

    // Load a font
    if (!font.loadFromFile("fontt.ttf")) {
        std::cerr << "Error loading font\n";
        return 1;
    }

    timerText.setFont(font);
    timerText.setCharacterSize(30);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(5, 3);

    // Load victory sound
    sf::SoundBuffer victoryBuffer;
    if (!victoryBuffer.loadFromFile("victory.wav")) {
        std::cerr << "Error loading victory sound\n";
        return 1;
    }
    sf::Sound victorySound(victoryBuffer);

    // Load movement sound
    sf::SoundBuffer moveBuffer;
    if (!moveBuffer.loadFromFile("move.wav")) {
        std::cerr << "Error loading movement sound\n";
        return 1;
    }
    sf::Sound moveSound(moveBuffer);

    bool isWon = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();  // Close the window on ESC key
                } else if (event.key.code == sf::Keyboard::R) {
                    sokoban.reset();
                    gameClock.restart();
                    isWon = false;  // Reset the game state
                } else if (!isWon) {
                    // Game controls only when not won
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            sokoban.movePlayer(SB::Direction::Up);
                            moveSound.play();  // Play movement sound
                            break;
                        case sf::Keyboard::Down:
                            sokoban.movePlayer(SB::Direction::Down);
                            moveSound.play();  // Play movement sound
                            break;
                        case sf::Keyboard::Left:
                            sokoban.movePlayer(SB::Direction::Left);
                            moveSound.play();  // Play movement sound
                            break;
                        case sf::Keyboard::Right:
                            sokoban.movePlayer(SB::Direction::Right);
                            moveSound.play();  // Play movement sound
                            break;
                        case sf::Keyboard::Z:
                            sokoban.undo();
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        if (sokoban.isWon() && !isWon) {
            isWon = true;  // Flag to indicate game is won
            victorySound.play();  // Play victory sound
            sf::Time finalTime = gameClock.getElapsedTime();

            // Prepare the victory message
            int totalSeconds = static_cast<int>(finalTime.asSeconds());
            int finalMinutes = totalSeconds / 60;
            int finalSeconds = totalSeconds % 60;
            std::string minutesStr = (finalMinutes < 10 ? "0" : "") + std::to_string(finalMinutes);
            std::string secondsStr = (finalSeconds < 10 ? "0" : "") + std::to_string(finalSeconds);
            std::string winMessage = "CONGRATULATIONS\nYOU WON\n\nTime: "
                                    + minutesStr + ":" + secondsStr;

            sf::Text winText;
            winText.setFont(font);
            winText.setString(winMessage);
            winText.setCharacterSize(35);
            winText.setFillColor(sf::Color::Black);
            winText.setPosition(60, 200);

            // Draw victory screen
            window.clear();
            window.draw(sokoban);
            window.draw(timerText);
            window.draw(winText);
            window.display();
        }

        // Update timer if game is not won
        if (!isWon) {
            sf::Time elapsed = gameClock.getElapsedTime();
            int seconds = static_cast<int>(elapsed.asSeconds());
            int minutes = seconds / 60;
            seconds %= 60;

            std::string timerString =
                (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
                (seconds < 10 ? "0" : "") + std::to_string(seconds);

            timerText.setString(timerString);

            // Clear and draw
            window.clear();
            window.draw(sokoban);
            window.draw(timerText);
            window.display();
        }
    }

    return 0;
}
