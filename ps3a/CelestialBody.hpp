// Copyright 2024 Harishwar Reddy Erri

#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace NB {

class CelestialBody {
 private:
    struct StateVector {
        sf::Vector2f location;
        sf::Vector2f momentum;
    };
    StateVector m_state;
    double m_inertia;
    std::string m_assetId;
    sf::Texture m_asset;
    sf::Sprite m_representation;

 public:
    CelestialBody();
    StateVector getState() const;
    double getInertia() const;
    std::string getAssetId() const;
    void setState(const StateVector& state);
    void setInertia(double inertia);
    void setAssetId(const std::string& id);
    bool initializeAsset();
    void refreshRepresentation();
    void updateScreenPosition(const sf::Vector2f& pos);
    void project(sf::RenderTarget& canvas) const;
    friend std::istream& operator>>(std::istream& stream, CelestialBody& entity);
    friend std::ostream& operator<<(std::ostream& stream, const CelestialBody& entity);
};

std::istream& operator>>(std::istream& stream, CelestialBody& entity);
std::ostream& operator<<(std::ostream& stream, const CelestialBody& entity);

}  // namespace NB
