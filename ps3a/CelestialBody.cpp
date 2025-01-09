// Copyright 2024 Harishwar Reddy Erri

#include <iostream>
#include "CelestialBody.hpp"

namespace NB {

CelestialBody::CelestialBody() : m_inertia(0) {}

CelestialBody::StateVector CelestialBody::getState() const { return m_state; }
double CelestialBody::getInertia() const { return m_inertia; }
std::string CelestialBody::getAssetId() const { return m_assetId; }

void CelestialBody::setState(const StateVector& state) { m_state = state; }
void CelestialBody::setInertia(double inertia) { m_inertia = inertia; }
void CelestialBody::setAssetId(const std::string& id) { m_assetId = id; }

bool CelestialBody::initializeAsset() {
    if (!m_asset.loadFromFile(m_assetId)) {
        std::cerr << "Asset loading failed: " << m_assetId << std::endl;
        return false;
    }
    std::cout << "Asset loaded: " << m_assetId << std::endl;
    return true;
}

void CelestialBody::refreshRepresentation() {
    m_representation.setTexture(m_asset);
    m_representation.setPosition(m_state.location);
    float minDimension = 20.0f;
    sf::Vector2u assetSize = m_asset.getSize();
    float scaleX = minDimension / assetSize.x;
    float scaleY = minDimension / assetSize.y;
    m_representation.setScale(scaleX, scaleY);
    sf::FloatRect bounds = m_representation.getLocalBounds();
    m_representation.setOrigin(bounds.width / 2, bounds.height / 2);
}

void CelestialBody::updateScreenPosition(const sf::Vector2f& pos) {
    m_representation.setPosition(pos);
}

void CelestialBody::project(sf::RenderTarget& canvas) const {
    canvas.draw(m_representation);
}

std::istream& operator>>(std::istream& stream, CelestialBody& entity) {
    CelestialBody::StateVector state;
    double inertia;
    std::string assetId;

    stream >> state.location.x >> state.location.y
           >> state.momentum.x >> state.momentum.y
           >> inertia >> assetId;
    entity.setState(state);
    entity.setInertia(inertia);
    entity.setAssetId(assetId);
    if (!entity.initializeAsset()) {
        std::cerr << "Asset initialization failed: " << assetId << std::endl;
    }
    entity.refreshRepresentation();
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const CelestialBody& entity) {
    auto state = entity.getState();
    stream << state.location.x << " " << state.location.y << " "
           << state.momentum.x << " " << state.momentum.y << " "
           << entity.getInertia() << " " << entity.getAssetId();
    return stream;
}
}  // namespace NB
