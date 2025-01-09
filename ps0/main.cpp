// Copyright 2024 <Harishwar Reddy Erri>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 750), "MICKEY MOUSE IN SFML!");
    sf::SoundBuffer buffer;
    buffer.loadFromFile("sound.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Shape
    sf::CircleShape circle(40.f);
    circle.setFillColor(sf::Color(201, 104, 104));
    circle.setPosition(30, 30);

    // Background
    sf::Texture bg;
    if (!bg.loadFromFile("bg.jpg")) {
        return -1;
    }
    sf::Sprite background;
    background.setTexture(bg);
    sf::Vector2u textureSize = bg.getSize();
    sf::Vector2u windowSize = window.getSize();
    background.setScale(static_cast<float>(windowSize.x) / textureSize.x,
                        static_cast<float>(windowSize.y) / textureSize.y);

    // Font
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        return -1;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("MICKEY MOUSE");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color(10, 104, 71));
    text.setPosition(40, 100);
    // Sprite
    sf::Texture tec;
    if (!tec.loadFromFile("sprite.png")) {
        std::cout << "Sorry for the error" << std::endl;
    }
    window.setFramerateLimit(60);
    sf::Sprite sprite;
    sprite.setTexture(tec);
    sprite.setScale(0.32f, 0.32f);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(130, 598);
    bool facingLeft = false;
    int sprite_x = 0, sprite_y = 0;
    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2f position = sprite.getPosition();
        std::cout << "Sprite Position: x = " << position.x << ", y = " << position.y << std::endl;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (position.x >= 130) {
                    sprite.move(sprite_x - 3, 0);
                }
                if (!facingLeft) {
                    sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
                    facingLeft = true;
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (position.x <= 676) {
                    sprite.move(sprite_x + 3, 0);
                }
                if (facingLeft) {
                    sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
                    facingLeft = false;
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (position.y >= 350) {
                    sprite.move(0, sprite_y - 2);
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (position.y <= 598) {
                    sprite.move(0, sprite_y + 2);
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                sprite.setPosition(130, 598);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                sound.play();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                sound.stop();
            }
            window.draw(background);
            window.draw(text);
            window.draw(circle);
            window.draw(sprite);
            window.display();
        }
    }
    return 0;
}
