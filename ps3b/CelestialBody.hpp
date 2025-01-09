// CopyRight 2024 Harishwar Reddy

#pragma once
#include <iostream>
#include <string>
#include <SFML/System/Vector2.hpp>

namespace NB {

class CelestialBody {
 private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    double mass;
    std::string filename;

 public:
    CelestialBody(sf::Vector2f pos, sf::Vector2f vel, double m, const std::string& file);
    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;
    double getMass() const;
    std::string getFilename() const;
    void updatePosition(double dt);
    void updateVelocity(sf::Vector2f force, double dt);
    sf::Vector2f calculateForceFrom(const CelestialBody& other) const;

    friend std::istream& operator>>(std::istream& is, CelestialBody& body);
    friend std::ostream& operator<<(std::ostream& os, const CelestialBody& body);
};

}  //  namespace NB
