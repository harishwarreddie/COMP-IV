// CopyRight 2024 Harishwar Reddy Erri

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include "Sokoban.hpp"

sf::Font font;
sf::Text timerText;
sf::Clock gameClock;

std::string formatTime(int seconds) {
    int minutes = seconds / 60;
    seconds %= 60;
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << seconds;
    return ss.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level_file>\n";
        return 1;
    }

    SB::Sokoban sokoban;
    std::ifstream levelFile(argv[1]);
    if (!levelFile) {
        std::cerr << "Unable to open file: " << argv[1] << "\n";
        return 1;
    }
    levelFile >> sokoban;

    sf::RenderWindow window(sf::VideoMode(sokoban.width() * 64,
                                          sokoban.height() * 64), "Sokoban");

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return 1;
    }

    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(10, 10);

    gameClock.restart();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::W:
                        sokoban.movePlayer(SB::Direction::Up);
                        break;
                    case sf::Keyboard::S:
                        sokoban.movePlayer(SB::Direction::Down);
                        break;
                    case sf::Keyboard::A:
                        sokoban.movePlayer(SB::Direction::Left);
                        break;
                    case sf::Keyboard::D:
                        sokoban.movePlayer(SB::Direction::Right);
                        break;
                    case sf::Keyboard::C:
                        window.close();
                        break;
                    default:
                        break;
                }
            }
        }

        window.clear();
        window.draw(sokoban);

        int elapsedSeconds = static_cast<int>
        (gameClock.getElapsedTime().asSeconds());
        timerText.setString(formatTime(elapsedSeconds));

        window.draw(timerText);
        window.display();

        if (sokoban.isWon()) {
            std::cout << "Congratulations! You won!\n";
            break;
        }
    }

    return 0;
}
