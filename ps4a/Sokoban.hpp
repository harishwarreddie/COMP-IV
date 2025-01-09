// CopyRight 2024 Harishwar Reddy Erri

#ifndef _MNT_F_UML_COMP_4_PS4A_SOKOBAN_HPP_
#define _MNT_F_UML_COMP_4_PS4A_SOKOBAN_HPP_

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

namespace SB {

enum class Direction { Up, Down, Left, Right };

class Sokoban : public sf::Drawable {
 public:
    Sokoban();
    int width() const;
    int height() const;
    sf::Vector2i playerLoc() const;
    void movePlayer(Direction dir);
    bool isWon() const;
    void reset();  // Add this line

    friend std::istream& operator>>(std::istream& is, Sokoban& sokoban);
    friend std::ostream& operator<<(std::ostream& os, const Sokoban& sokoban);

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    int m_width;
    int m_height;
    sf::Vector2i m_playerLoc;
    std::vector<char> m_grid;
    sf::Texture m_textures[5];
    sf::Sprite m_sprites[5];

    void loadTextures();
};

}  // namespace SB

#endif  // _MNT_F_UML_COMP_4_PS4A_SOKOBAN_HPP_
