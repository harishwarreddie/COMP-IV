// Copyright 2024 Harishwar Reddy Erri

#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CelestialBody.hpp"

namespace NB {

class Universe {
 private:
    struct Simulation {
        std::vector<std::unique_ptr<CelestialBody>> entities;
        double boundary;
    } m_sim;
    struct Environment {
        sf::Texture backdrop;
        sf::Sprite scene;
        std::unique_ptr<sf::Sound> ambience;
        std::unique_ptr<sf::SoundBuffer> ambienceBuffer;
    } m_env;

 public:
    Universe();
    explicit Universe(const std::string& config);
    ~Universe();

    size_t entityCount() const;
    double simulationBoundary() const;

    CelestialBody& accessEntity(size_t index);
    const CelestialBody& accessEntity(size_t index) const;

    void evolve(double timeStep);
    bool setupScene(const std::string& imagePath);
    bool setupAmbience(const std::string& audioPath);
    void toggleAmbience();
    void render(sf::RenderTarget& display) const;

    friend std::istream& operator>>(std::istream& stream, Universe& cosmos);
    friend std::ostream& operator<<(std::ostream& stream, const Universe& cosmos);
};

std::istream& operator>>(std::istream& stream, Universe& cosmos);
std::ostream& operator<<(std::ostream& stream, const Universe& cosmos);

}  // namespace NB
