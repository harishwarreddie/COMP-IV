// Copyright 2024 Harishwar Reddy Erri

#include <iostream>
#include <fstream>
#include "Universe.hpp"

namespace NB {

Universe::Universe() : m_sim{std::vector<std::unique_ptr<CelestialBody>>(), 0} {}

Universe::Universe(const std::string& config) : Universe() {
    std::ifstream file(config);
    if (file) {
        file >> *this;
    } else {
        std::cerr << "Configuration file error: " << config << std::endl;
    }
}

Universe::~Universe() = default;

size_t Universe::entityCount() const { return m_sim.entities.size(); }
double Universe::simulationBoundary() const { return m_sim.boundary; }

CelestialBody& Universe::accessEntity(size_t index) {
    if (index >= m_sim.entities.size()) {
        throw std::out_of_range("Entity index out of bounds");
    }
    return *m_sim.entities[index];
}

const CelestialBody& Universe::accessEntity(size_t index) const {
    if (index >= m_sim.entities.size()) {
        throw std::out_of_range("Entity index out of bounds");
    }
    return *m_sim.entities[index];
}

bool Universe::setupScene(const std::string& imagePath) {
    if (!m_env.backdrop.loadFromFile(imagePath)) {
        std::cerr << "Scene setup failed: " << imagePath << std::endl;
        return false;
    }
    m_env.scene.setTexture(m_env.backdrop);
    float scaleX = (2 * m_sim.boundary) / m_env.backdrop.getSize().x;
    float scaleY = (2 * m_sim.boundary) / m_env.backdrop.getSize().y;
    m_env.scene.setScale(scaleX, scaleY);
    m_env.scene.setPosition(-m_sim.boundary, -m_sim.boundary);
    return true;
}

void Universe::render(sf::RenderTarget& display) const {
    sf::View currentView = display.getView();
    sf::View sceneView(sf::FloatRect(-m_sim.boundary,
    -m_sim.boundary, 2 * m_sim.boundary, 2 * m_sim.boundary));
    display.setView(sceneView);
    display.draw(m_env.scene);
    display.setView(currentView);
    for (const auto& entity : m_sim.entities) {
        entity->project(display);
    }
}

bool Universe::setupAmbience(const std::string& audioPath) {
    m_env.ambienceBuffer = std::make_unique<sf::SoundBuffer>();
    if (!m_env.ambienceBuffer->loadFromFile(audioPath)) {
        std::cerr << "Ambience setup failed: " << audioPath << std::endl;
        return false;
    }
    m_env.ambience = std::make_unique<sf::Sound>();
    m_env.ambience->setBuffer(*m_env.ambienceBuffer);
    m_env.ambience->setLoop(true);
    m_env.ambience->play();
    return true;
}

void Universe::toggleAmbience() {
    if (m_env.ambience) {
        if (m_env.ambience->getStatus() == sf::Sound::Playing) {
            m_env.ambience->pause();
        } else {
            m_env.ambience->play();
        }
    }
}

std::istream& operator>>(std::istream& stream, Universe& cosmos) {
    size_t count;
    stream >> count >> cosmos.m_sim.boundary;
    cosmos.m_sim.entities.resize(count);
    for (auto& entity : cosmos.m_sim.entities) {
        entity = std::make_unique<CelestialBody>();
        stream >> *entity;
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Universe& cosmos) {
    stream << cosmos.m_sim.entities.size() << " " << cosmos.m_sim.boundary << "\n";
    for (const auto& entity : cosmos.m_sim.entities) {
        stream << *entity << "\n";
    }
    return stream;
}

}  // namespace NB
