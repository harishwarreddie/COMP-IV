// CopyRight 2024 Harishwar Reddy Erri

#include <fstream>
#include <iostream>

#include "Sokoban.hpp"

namespace SB {

Sokoban::Sokoban() : m_width(0), m_height(0) {
    loadTextures();
}

int Sokoban::width() const { return m_width; }
int Sokoban::height() const { return m_height; }
sf::Vector2i Sokoban::playerLoc() const { return m_playerLoc; }

void Sokoban::movePlayer(Direction dir) {
    // To be implemented in part B
    (void)dir;
}

bool Sokoban::isWon() const {
    // To be implemented in part B
    return false;
}

void Sokoban::reset() {
    // Reset the game state to its initial configuration
    m_width = 0;
    m_height = 0;
    m_playerLoc = sf::Vector2i(0, 0);
    m_grid.clear();
}

void Sokoban::loadTextures() {
    m_textures[0].loadFromFile("empty.png");
    m_textures[1].loadFromFile("wall.png");
    m_textures[2].loadFromFile("box.png");
    m_textures[3].loadFromFile("target.png");
    m_textures[4].loadFromFile("player_05.png");

    for (int i = 0; i < 5; ++i) {
        m_sprites[i].setTexture(m_textures[i]);
    }
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            char cell = m_grid[y * m_width + x];
            sf::Sprite sprite;

            // Always draw the empty space first
            sprite = m_sprites[0];  // Empty space sprite
            sprite.setPosition(x * 64.f, y * 64.f);
            target.draw(sprite, states);

            // Then draw other elements on top
            switch (cell) {
                case '#': sprite = m_sprites[1]; break;
                case 'A': sprite = m_sprites[2]; break;
                case 'a': sprite = m_sprites[3]; break;
                case '@': sprite = m_sprites[4]; break;
                case '1':
                    sprite = m_sprites[3];
                    target.draw(sprite, states);
                    sprite = m_sprites[2];
                    break;
                default:
                    continue;
            }

            sprite.setPosition(x * 64.f, y * 64.f);
            target.draw(sprite, states);
        }
    }
}
std::istream& operator>>(std::istream& is, Sokoban& sokoban) {
    is >> sokoban.m_height >> sokoban.m_width;
    sokoban.m_grid.resize(sokoban.m_width * sokoban.m_height);
    std::string line;
    std::getline(is, line);  // Consume newline
    for (int y = 0; y < sokoban.m_height; ++y) {
        std::getline(is, line);
        for (int x = 0; x < sokoban.m_width; ++x) {
            sokoban.m_grid[y * sokoban.m_width + x] = line[x];
            if (line[x] == '@') {
                sokoban.m_playerLoc = sf::Vector2i(x, y);
            }
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Sokoban& sokoban) {
    os << sokoban.m_height << " " << sokoban.m_width << "\n";
    for (int y = 0; y < sokoban.m_height; ++y) {
        for (int x = 0; x < sokoban.m_width; ++x) {
            os << sokoban.m_grid[y * sokoban.m_width + x];
        }
        os << "\n";
    }
    return os;
}

}  // namespace SB
