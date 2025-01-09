// CopyRight 2024 Harishwar Reddy Erri

#ifndef PENTA_HPP
#define PENTA_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class PentaflakeDrawer : public sf::Drawable {
 private:
      double baseSize;
      int recursionCount;
      double centerX, centerY;
      double pentaflakeTop, pentaflakeBottom;
      std::vector<sf::ConvexShape> fractalElements;
      double totalRotation;
      bool isRotatingClockwise;
      bool isRotatingCounterclockwise;
      double rotationSpeed;
      double xRotationAngle, yRotationAngle;
      bool isXRotating, isYRotating;
      double xRotationSpeed, yRotationSpeed;
      double zoomFactor;

      sf::Music normalMusic;
      sf::Music rightRotationMusic;
      sf::Music leftRotationMusic;

      void drawFractal(double x, double y, double edge,
      int depth, double rotationAngle);
      sf::ConvexShape createPolygon(double x, double y,
      double length, double rotationAngle) const;
      sf::Color determineColor(double y) const;
      sf::Color lerpColor(const sf::Color& c1,
      const sf::Color& c2, double t) const;

 public:
      PentaflakeDrawer(double size, int levels);
      void create(double centerX, double centerY);
      void draw(sf::RenderTarget& target,
      sf::RenderStates states) const override;
      void rotate(double angle);
      void update(float deltaTime);
      void toggleRotation(bool clockwise);
      void toggleXRotation();
      void toggleYRotation();
      void loadMusic();
      void updateAudio();
      void reset();
      void zoomIn();
      void zoomOut();
};
#endif  //  PENTA_HPP
