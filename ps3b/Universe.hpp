// CopyRight 2024 Harishwar Reddy

#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>

namespace NB {

class Universe {
 private:
    std::vector<std::unique_ptr<CelestialBody>> bodies;
    double radius;
    sf::Vector2f calculateForce(const CelestialBody& body1, const CelestialBody& body2) const;

 public:
    Universe();
    void readFromFile(std::istream& input);
    void step(double dt);
    void draw(sf::RenderWindow& window);
    void writeToFile(std::ostream& output) const;

    friend std::istream& operator>>(std::istream& is, Universe& universe);
    friend std::ostream& operator<<(std::ostream& os, const Universe& universe);
};

}  //  namespace NB
