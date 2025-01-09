// CopyRight 2024 Harishwar Reddy Erri

#include <fstream>
#include <iostream>
#include <algorithm>
#include "Sokoban.hpp"

namespace SB {

Sokoban::Sokoban() : m_width(0), m_height(0) {
    // Default constructor implementation
    loadTextures();
    loadPlayerTextures();
}

Sokoban::Sokoban(const std::string& filename) : m_width(0), m_height(0) {
    loadTextures();
    loadPlayerTextures();
    std::ifstream file(filename);
    if (file) {
        file >> *this;
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

int Sokoban::width() const {
    return m_width;
}

int Sokoban::height() const {
    return m_height;
}

sf::Vector2i Sokoban::playerLoc() const {
    return m_playerLoc;
}

void Sokoban::movePlayer(Direction dir) {
    saveState();

    int dx = 0, dy = 0;
    switch (dir) {
        case Direction::Up: dy = -1; break;
        case Direction::Down: dy = 1; break;
        case Direction::Left: dx = -1; break;
        case Direction::Right: dx = 1; break;
    }

    int newX = m_playerLoc.x + dx;
    int newY = m_playerLoc.y + dy;
    if (newX >= 0 && newX < m_width && newY >= 0 && newY < m_height) {
        char& newCell = m_grid[newY * m_width + newX];
        char& playerCell = m_grid[m_playerLoc.y * m_width + m_playerLoc.x];
        if (newCell == '.' || newCell == 'a') {
            // Moving to an empty space or target
            if (playerCell == '@') playerCell = '.';
            else if (playerCell == '+') playerCell = 'a';
            if (newCell == '.') newCell = '@';
            else if (newCell == 'a') newCell = '+';
            m_playerLoc = sf::Vector2i(newX, newY);
            updatePlayerSprite(dir);
        } else if (newCell == 'A' || newCell == '1') {
            // Pushing a box
            int boxNewX = newX + dx;
            int boxNewY = newY + dy;
            if (boxNewX >= 0 && boxNewX < m_width && boxNewY >= 0 && boxNewY < m_height) {
                char& boxNewCell = m_grid[boxNewY * m_width + boxNewX];
                if (boxNewCell == '.' || boxNewCell == 'a') {
                    // Move box to the new cell
                    boxNewCell = (boxNewCell == '.') ? 'A' : '1';
                    // Move player to the box's old position
                    if (playerCell == '@') playerCell = '.';
                    else if (playerCell == '+') playerCell = 'a';
                    newCell = (newCell == 'A') ? '@' : '+';
                    m_playerLoc = sf::Vector2i(newX, newY);
                    updatePlayerSprite(dir);
                }
            }
        }
    }
}

bool Sokoban::isWon() const {
    int boxCount = 0;
    int targetCount = 0;
    int boxesOnTarget = 0;
    bool hasEmptyTarget = false;
    bool hasBoxOffTarget = false;

    auto checkCell = [&](char c) {
        switch (c) {
            case 'A':
                boxCount++;
                hasBoxOffTarget = true;
                break;
            case 'a':
                targetCount++;
                hasEmptyTarget = true;
                break;
            case '1':
                boxCount++;
                targetCount++;
                boxesOnTarget++;
                break;
            case '+':
                targetCount++;  // Player on target
                break;
        }
    };

    std::for_each(m_grid.begin(), m_grid.end(), checkCell);

    // Handle special cases
    if (boxCount == 0 && targetCount == 0) {
        return true;  // No boxes and no targets, consider it a win (e.g., empty level)
    }

    if (boxCount == 0 || targetCount == 0) {
        return false;  // Boxes but no targets, or targets but no boxes
    }

    // Normal win condition
    return (boxCount == targetCount) &&
           (boxesOnTarget == boxCount) &&
           !hasEmptyTarget &&
           !hasBoxOffTarget;
}

void Sokoban::reset() {
    m_grid = m_initialGrid;
    auto it = std::find_if(m_grid.begin(), m_grid.end(),
    [](char c) { return c == '@' || c == '+'; });
    if (it != m_grid.end()) {
        int index = std::distance(m_grid.begin(), it);
        m_playerLoc.x = index % m_width;
        m_playerLoc.y = index / m_width;
    }
    updatePlayerSprite(Direction::Down);
    m_undoStates.clear();
}

void Sokoban::loadTextures() {
    if (!m_textures[0].loadFromFile("empty.png") ||
        !m_textures[1].loadFromFile("wall.png") ||
        !m_textures[2].loadFromFile("box.png") ||
        !m_textures[3].loadFromFile("target.png") ||
        !m_textures[4].loadFromFile("down.png")) {
        std::cerr << "Failed to load textures" << std::endl;
    }

    for (int i = 0; i < 5; ++i) {
        m_sprites[i].setTexture(m_textures[i]);
    }
}

void Sokoban::loadPlayerTextures() {
    if (!playerTextureUp.loadFromFile("up.png") ||
        !playerTextureDown.loadFromFile("down.png") ||
        !playerTextureLeft.loadFromFile("left.png") ||
        !playerTextureRight.loadFromFile("right.png")) {
        std::cerr << "Failed to load player textures" << std::endl;
    }
    playerSprite.setTexture(playerTextureDown);
}

void Sokoban::setPlayerTexture(const sf::Texture& texture) {
    playerSprite.setTexture(texture);
}

void Sokoban::updatePlayerSprite(Direction dir) {
    switch (dir) {
        case Direction::Up:
            playerSprite.setTexture(playerTextureUp);
            break;
        case Direction::Down:
            playerSprite.setTexture(playerTextureDown);
            break;
        case Direction::Left:
            playerSprite.setTexture(playerTextureLeft);
            break;
        case Direction::Right:
            playerSprite.setTexture(playerTextureRight);
            break;
    }
    playerSprite.setPosition(m_playerLoc.x * 64.f, m_playerLoc.y * 64.f);
}

void Sokoban::undo() {
    if (m_undoStates.empty()) return;

    GameState prevState = m_undoStates.back();
    m_undoStates.pop_back();

    m_grid = prevState.grid;
    m_playerLoc = prevState.playerLoc;
    playerSprite.setPosition(m_playerLoc.x * 64.f, m_playerLoc.y * 64.f);
}

void Sokoban::saveState() {
    if (m_undoStates.size() >= 2) {
        m_undoStates.pop_front();
    }
    m_undoStates.push_back({m_grid, m_playerLoc});
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
                case '1':
                    sprite = m_sprites[3];
                    sprite = m_sprites[2];
                    break;
                default:
                    continue;
            }

            sprite.setPosition(x * 64.f, y * 64.f);
            target.draw(sprite, states);
        }
    }
    // Draw the player sprite
    target.draw(playerSprite, states);
}

}  // namespace SB

std::istream& SB::operator>>(std::istream& is, SB::Sokoban& sokoban) {
    is >> sokoban.m_height >> sokoban.m_width;
    sokoban.m_grid.resize(sokoban.m_width * sokoban.m_height);
    std::string line;
    std::getline(is, line);
    for (int y = 0; y < sokoban.m_height; ++y) {
        std::getline(is, line);
        for (int x = 0; x < sokoban.m_width; ++x) {
            sokoban.m_grid[y * sokoban.m_width + x] = line[x];
            if (line[x] == '@') {
                sokoban.m_playerLoc = sf::Vector2i(x, y);
                sokoban.playerSprite.setPosition(x * 64.f, y * 64.f);
            }
        }
    }
    sokoban.m_initialGrid = sokoban.m_grid;
    return is;
}
