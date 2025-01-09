// CopyRight 2024 Harishwar Reddy

#define BOOST_TEST_MODULE NBodyTest
#include <sstream>
#include <cmath>
#include <boost/test/included/unit_test.hpp>
#include "CelestialBody.hpp"
#include "Universe.hpp"


// Gravitational constant (same as in your Universe.cpp)
const double G = 6.67e-11;

// Test Case 1: Test Position Update
BOOST_AUTO_TEST_CASE(TestPositionUpdate) {
    sf::Vector2f initialPosition(0.0f, 0.0f);
    sf::Vector2f velocity(10.0f, 0.0f);  // Velocity along x-axis
    double mass = 5.0;
    std::string filename = "planet.png";
    NB::CelestialBody body(initialPosition, velocity, mass, filename);
    body.updatePosition(2.0);  // dt = 2 seconds
    sf::Vector2f expectedPosition(20.0f, 0.0f);  // Position = velocity * dt
    BOOST_CHECK_CLOSE(body.getPosition().x, expectedPosition.x, 0.001);
    BOOST_CHECK_CLOSE(body.getPosition().y, expectedPosition.y, 0.001);
}

// Test Case 2: Test Velocity Update with Force
BOOST_AUTO_TEST_CASE(TestVelocityUpdate) {
    sf::Vector2f initialPosition(0.0f, 0.0f);
    sf::Vector2f initialVelocity(0.0f, 0.0f);
    double mass = 10.0;
    std::string filename = "planet.png";
    NB::CelestialBody body(initialPosition, initialVelocity, mass, filename);
    sf::Vector2f force(20.0f, 0.0f);  // Force along x-axis
    body.updateVelocity(force, 2.0);  // dt = 2 seconds
    sf::Vector2f expectedVelocity(4.0f, 0.0f);  // velocity = (force/mass) * dt
    BOOST_CHECK_CLOSE(body.getVelocity().x, expectedVelocity.x, 0.001);
    BOOST_CHECK_CLOSE(body.getVelocity().y, expectedVelocity.y, 0.001);
}

// Test Case 3: Test Force Calculation Between Two Bodies
BOOST_AUTO_TEST_CASE(TestForceCalculation) {
    sf::Vector2f pos1(0.0f, 0.0f);
    sf::Vector2f pos2(10.0f, 0.0f);
    sf::Vector2f vel(0.0f, 0.0f);
    double mass1 = 5.0e24;
    double mass2 = 5.0e24;
    std::string filename = "planet.png";
    NB::CelestialBody body1(pos1, vel, mass1, filename);
    NB::CelestialBody body2(pos2, vel, mass2, filename);
    sf::Vector2f force = body1.calculateForceFrom(body2);
    double expectedForceMagnitude = G * mass1 * mass2 / (10.0 * 10.0);  // F = G*m1*m2/r^2
    BOOST_CHECK_CLOSE(force.x, expectedForceMagnitude, 0.001);
    BOOST_CHECK_SMALL(static_cast<double>(force.y), 0.001);  // Convert force.y to double
}



// Test Case 5: Test Universe File I/O
BOOST_AUTO_TEST_CASE(TestUniverseFileIO) {
    std::istringstream input(
        "3\n"             // Number of bodies
        "1e12\n"          // Radius of the universe
        "0 0 0 0 6e24 planet1.png\n"
        "10 10 0 0 6e24 planet2.png\n"
        "-10 -10 0 0 6e24 planet3.png\n");
    NB::Universe universe;
    input >> universe;
    std::ostringstream output;
    universe.writeToFile(output);
    BOOST_CHECK_EQUAL(output.str(),
                        "3\n"
                        "1e+12\n"
                        "0 0 0 0 6e+24 planet1.png\n"
                        "10 10 0 0 6e+24 planet2.png\n"
                        "-10 -10 0 0 6e+24 planet3.png\n");
}
