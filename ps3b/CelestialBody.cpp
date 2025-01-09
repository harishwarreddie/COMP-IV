// CopyRight 2024 Harishwar Reddy

#include "CelestialBody.hpp"
#include <cmath>

namespace NB {
const double G = 6.67e-11;
CelestialBody::CelestialBody(sf::Vector2f pos, sf::Vector2f vel, double m, const std::string& file)
: position(pos), velocity(vel), mass(m), filename(file) {}
sf::Vector2f CelestialBody::getPosition() const {
return position;
}
sf::Vector2f CelestialBody::getVelocity() const {
return velocity;
}
double CelestialBody::getMass() const {
return mass;
}
std::string CelestialBody::getFilename() const {
return filename;
}
void CelestialBody::updatePosition(double dt) {
position += velocity * static_cast<float>(dt);
}
void CelestialBody::updateVelocity(sf::Vector2f force, double dt) {
velocity += (force / static_cast<float>(mass)) * static_cast<float>(dt);
}
sf::Vector2f CelestialBody::calculateForceFrom(const CelestialBody& other) const {
sf::Vector2f delta = other.position - position;
double distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
double force = G * mass * other.mass / (distance * distance);
return delta / static_cast<float>(distance) * static_cast<float>(force);
}
std::istream& operator>>(std::istream& is, CelestialBody& body) {
return is >> body.position.x >> body.position.y
>> body.velocity.x >> body.velocity.y
>> body.mass >> body.filename;
}
std::ostream& operator<<(std::ostream& os, const CelestialBody& body) {
return os << body.position.x << " " << body.position.y << " "
<< body.velocity.x << " " << body.velocity.y << " "
<< body.mass << " " << body.filename;
}
}  // namespace NB
