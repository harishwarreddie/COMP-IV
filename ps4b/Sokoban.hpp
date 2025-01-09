// CopyRight 2024 Harishwar Reddy Erri

#ifndef SOKOBAN_HPP
#define SOKOBAN_HPP

#include <string>
#include <vector>
#include <deque>
#include <SFML/Graphics.hpp>

namespace SB {

enum class Direction { Up, Down, Left, Right };

struct GameState {
    std::vector<char> grid;
    sf::Vector2i playerLoc;
};

class Sokoban : public sf::Drawable {
 public:
    Sokoban();
    explicit Sokoban(const std::string& filename);
    int width() const;
    int height() const;
    sf::Vector2i playerLoc() const;
    void movePlayer(Direction dir);
    bool isWon() const;
    void reset();
    void setPlayerTexture(const sf::Texture& texture);
    void undo();

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    int m_width;
    int m_height;
    sf::Vector2i m_playerLoc;
    std::vector<char> m_grid;
    std::vector<char> m_initialGrid;
    sf::Texture m_textures[5];
    sf::Sprite m_sprites[5];
    sf::Sprite playerSprite;

    sf::Texture playerTextureUp;
    sf::Texture playerTextureDown;
    sf::Texture playerTextureLeft;
    sf::Texture playerTextureRight;

    std::deque<GameState> m_undoStates;

    void loadTextures();
    void loadPlayerTextures();
    void updatePlayerSprite(Direction dir);
    void saveState();

    friend std::istream& operator>>(std::istream& is, Sokoban& sokoban);
};

std::istream& operator>>(std::istream& is, Sokoban& sokoban);

}  // namespace SB

#endif  // SOKOBAN_HPP
