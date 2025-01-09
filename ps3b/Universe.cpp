// CopyRight 2024 Harishwar Reddy

#include <cmath>
#include <iostream>
#include "Universe.hpp"

namespace NB {
const double G = 6.67e-11;
Universe::Universe() : radius(0) {}
void Universe::readFromFile(std::istream& input) {
input >> *this;
}
void Universe::step(double dt) {
std::vector<sf::Vector2f> forces(bodies.size(), sf::Vector2f(0, 0));
// Calculate forces
for (size_t i = 0; i < bodies.size(); ++i) {
for (size_t j = i + 1; j < bodies.size(); ++j) {
sf::Vector2f force = calculateForce(*bodies[i], *bodies[j]);
forces[i] += force;
forces[j] -= force;  // Newton's third law
}
}
// Update velocities and positions
for (size_t i = 0; i < bodies.size(); ++i) {
bodies[i]->updateVelocity(forces[i], dt);
bodies[i]->updatePosition(dt);
}
}
sf::Vector2f Universe::calculateForce(const CelestialBody& body1,
const CelestialBody& body2) const {
sf::Vector2f delta = body2.getPosition() - body1.getPosition();
double distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
double force = G * body1.getMass() * body2.getMass() / (distance * distance);
return delta / static_cast<float>(distance) * static_cast<float>(force);
}
void Universe::draw(sf::RenderWindow& window) {
for (const auto& body : bodies) {
sf::Texture texture;
if (!texture.loadFromFile(body->getFilename())) {
std::cerr << "Failed to load texture: " << body->getFilename() << std::endl;
continue;
}
sf::Sprite sprite(texture);
sf::Vector2f pos = body->getPosition();
float windowX = (pos.x / (2 * radius) + 0.5f) * window.getSize().x;
float windowY = (-pos.y / (2 * radius) + 0.5f) * window.getSize().y;
// Center the sprite
sf::FloatRect bounds = sprite.getLocalBounds();
sprite.setOrigin(bounds.width / 2, bounds.height / 2);
sprite.setPosition(windowX, windowY);
// Increase the scale factor to make planets larger
float scale = 1.5f;
// Adjust scale based on the mass of the body (optional)
if (body->getMass() > 1e28) {
scale = 1.5f;
} else if (body->getMass() < 1e24) {
scale = 1.5f;
}
sprite.setScale(scale, scale);
window.draw(sprite);
}
}
void Universe::writeToFile(std::ostream& output) const {
output << *this;
}
std::istream& operator>>(std::istream& is, Universe& universe) {
int numBodies;
is >> numBodies >> universe.radius;
universe.bodies.clear();
for (int i = 0; i < numBodies; ++i) {
CelestialBody body({0, 0}, {0, 0}, 0, "");
is >> body;
universe.bodies.push_back(std::make_unique<CelestialBody>(body));
}
return is;
}
std::ostream& operator<<(std::ostream& os, const Universe& universe) {
os << universe.bodies.size() << "\n";
os << universe.radius << "\n";
for (const auto& body : universe.bodies) {
os << *body << "\n";
}
return os;
}
}  //  namespace NB
