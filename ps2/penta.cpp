// CopyRight 2024 Harishwar Reddy Erri

#include <cmath>
#include <algorithm>
#include <tuple>
#include "penta.hpp"

PentaflakeDrawer::PentaflakeDrawer(double size, int levels)
    : baseSize(size), recursionCount(levels), totalRotation(0.0),
      isRotatingClockwise(false), isRotatingCounterclockwise(false), rotationSpeed(M_PI / 2),
      xRotationAngle(0.0), yRotationAngle(0.0), isXRotating(false), isYRotating(false),
      xRotationSpeed(M_PI / 4), yRotationSpeed(M_PI / 4), zoomFactor(1.0) {}

void PentaflakeDrawer::create(double centerX, double centerY) {
    fractalElements.clear();
    this->centerX = centerX;
    this->centerY = centerY;
    pentaflakeTop = centerY - baseSize / 2.0;
    pentaflakeBottom = centerY + baseSize / 2.0;
    drawFractal(centerX, centerY, baseSize, recursionCount, -M_PI / 2.0);
}

void PentaflakeDrawer::draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const {
    sf::Transform xRotation, yRotation, zoom;
    double xScale = std::abs(std::cos(xRotationAngle));
    double yScale = std::abs(std::cos(yRotationAngle));
    xRotation.scale(1.f, xScale, centerX, centerY);
    yRotation.scale(yScale, 1.f, centerX, centerY);
    zoom.scale(zoomFactor, zoomFactor, centerX, centerY);

    sf::Transform rotation;
    rotation.rotate(totalRotation * 180 / M_PI, centerX, centerY);

    states.transform *= zoom * xRotation * yRotation * rotation;

    for (const auto& element : fractalElements) {
        renderTarget.draw(element, states);
    }
}

void PentaflakeDrawer::rotate(double angle) {
    totalRotation += angle;
    totalRotation = fmod(totalRotation, 2 * M_PI);
}

void PentaflakeDrawer::update(float deltaTime) {
    if (isRotatingClockwise) {
        rotate(rotationSpeed * deltaTime);
    }
    if (isRotatingCounterclockwise) {
        rotate(-rotationSpeed * deltaTime);
    }
    if (isXRotating) {
        xRotationAngle += xRotationSpeed * deltaTime;
        xRotationAngle = std::fmod(xRotationAngle, 2 * M_PI);
    }
    if (isYRotating) {
        yRotationAngle += yRotationSpeed * deltaTime;
        yRotationAngle = std::fmod(yRotationAngle, 2 * M_PI);
    }
}

void PentaflakeDrawer::toggleRotation(bool clockwise) {
    if (clockwise) {
        isRotatingClockwise = !isRotatingClockwise;
        isRotatingCounterclockwise = false;
    } else {
        isRotatingCounterclockwise = !isRotatingCounterclockwise;
        isRotatingClockwise = false;
    }
}

void PentaflakeDrawer::toggleXRotation() {
    isXRotating = !isXRotating;
}

void PentaflakeDrawer::toggleYRotation() {
    isYRotating = !isYRotating;
}

void PentaflakeDrawer::
drawFractal(double x, double y, double edge, int depth, double rotationAngle) {
    if (depth == 0) {
        sf::ConvexShape pentagon = createPolygon(x, y, edge, rotationAngle);
        pentagon.setFillColor(determineColor(y));
        fractalElements.push_back(pentagon);
        return;
    }

    double scaleFactor = edge / (1 + (1 + std::sqrt(5.0)) / 2.0);
    double outerRadius = edge / (2 * std::sin(M_PI / 5));
    double innerOffset = scaleFactor / (2 * std::sin(M_PI / 5));

    drawFractal(x, y, scaleFactor, depth - 1, rotationAngle);

    for (int i = 0; i < 5; ++i) {
        double angle = (2 * M_PI * i) / 5;
        double offsetX = (outerRadius - innerOffset) * std::cos(angle);
        double offsetY = (outerRadius - innerOffset) * std::sin(angle);
        double rotatedX = x + offsetX * std::cos(rotationAngle) - offsetY * std::sin(rotationAngle);
        double rotatedY = y + offsetX * std::sin(rotationAngle) + offsetY * std::cos(rotationAngle);
        drawFractal(rotatedX, rotatedY, scaleFactor, depth - 1, rotationAngle);
    }
}

sf::ConvexShape PentaflakeDrawer::
createPolygon(double x, double y, double length, double rotationAngle) const {
    sf::ConvexShape pentagon;
    pentagon.setPointCount(5);
    double radius = length / (2 * std::sin(M_PI / 5));
    for (int vertex = 0; vertex < 5; ++vertex) {
        double angle = (2 * M_PI * vertex) / 5;
        double rotatedX = x + radius * std::cos(angle) *
        std::cos(rotationAngle) - radius * std::sin(angle) * std::sin(rotationAngle);
        double rotatedY = y + radius * std::cos(angle) *
        std::sin(rotationAngle) + radius * std::sin(angle) * std::cos(rotationAngle);
        pentagon.setPoint(vertex, sf::Vector2f(rotatedX, rotatedY));
    }
    return pentagon;
}

sf::Color PentaflakeDrawer::determineColor(double y) const {
    double height = pentaflakeBottom - pentaflakeTop;
    double relativeY = (y - pentaflakeTop) / height;
    sf::Color colors[5] = {
        sf::Color(255, 182, 193),  // Light Pink
        sf::Color(255, 218, 185),  // Peach Puff
        sf::Color(255, 255, 224),  // Light Yellow
        sf::Color(176, 224, 230),  // Powder Blue
        sf::Color(230, 230, 250)   // Lavender
    };
    int index = static_cast<int>(relativeY * 4);
    double t = relativeY * 4 - index;
    return lerpColor(colors[index], colors[index + 1], t);
}

sf::Color PentaflakeDrawer::lerpColor(const sf::Color& c1, const sf::Color& c2, double t) const {
    auto rgbToHsl = [](const sf::Color& c) {
        float r = c.r / 255.0f, g = c.g / 255.0f, b = c.b / 255.0f;
        float max = std::max({r, g, b}), min = std::min({r, g, b});
        float h, s, l = (max + min) / 2;

        if (max == min) {
            h = s = 0;
        } else {
            float d = max - min;
            s = l > 0.5f ? d / (2 - max - min) : d / (max + min);
            if (max == r)
                h = (g - b) / d + (g < b ? 6 : 0);
            else if (max == g)
                h = (b - r) / d + 2;
            else
                h = (r - g) / d + 4;
            h /= 6;
        }
        return std::make_tuple(h, s, l);
    };

    auto hslToRgb = [](float h, float s, float l) {
        auto hue2rgb = [](float p, float q, float t) -> float {
            if (t < 0) t += 1;
            if (t > 1) t -= 1;
            if (t < 1.0f/6) return p + (q - p) * 6 * t;
            if (t < 1.0f/2) return q;
            if (t < 2.0f/3) return p + (q - p) * (2.0f/3 - t) * 6;
            return p;
        };

        if (s == 0) {
            return sf::Color(l * 255, l * 255, l * 255);
        } else {
            float q = l < 0.5f ? l * (1 + s) : l + s - l * s;
            float p = 2 * l - q;
            return sf::Color(
                hue2rgb(p, q, h + 1.0f/3) * 255,
                hue2rgb(p, q, h) * 255,
                hue2rgb(p, q, h - 1.0f/3) * 255);
        }
    };

    auto [h1, s1, l1] = rgbToHsl(c1);
    auto [h2, s2, l2] = rgbToHsl(c2);

    float h = h1 + t * (h2 - h1);
    float s = s1 + t * (s2 - s1);
    float l = l1 + t * (l2 - l1);

    return hslToRgb(h, s, l);
}

void PentaflakeDrawer::loadMusic() {
    if (!normalMusic.openFromFile("normal.ogg") ||
        !rightRotationMusic.openFromFile("RR.ogg") ||
        !leftRotationMusic.openFromFile("LR.ogg")) {
        // Handle error loading music files
    }
    normalMusic.setLoop(true);
    rightRotationMusic.setLoop(true);
    leftRotationMusic.setLoop(true);
}

void PentaflakeDrawer::updateAudio() {
    if (isRotatingClockwise) {
        if (normalMusic.getStatus() == sf::Music::Playing) normalMusic.stop();
        if (leftRotationMusic.getStatus() == sf::Music::Playing) leftRotationMusic.stop();
        if (rightRotationMusic.getStatus() != sf::Music::Playing) rightRotationMusic.play();
    } else if (isRotatingCounterclockwise) {
        if (normalMusic.getStatus() == sf::Music::Playing) normalMusic.stop();
        if (rightRotationMusic.getStatus() == sf::Music::Playing) rightRotationMusic.stop();
        if (leftRotationMusic.getStatus() != sf::Music::Playing) leftRotationMusic.play();
    } else {
        if (rightRotationMusic.getStatus() == sf::Music::Playing) rightRotationMusic.stop();
        if (leftRotationMusic.getStatus() == sf::Music::Playing) leftRotationMusic.stop();
        if (normalMusic.getStatus() != sf::Music::Playing) normalMusic.play();
    }
}

void PentaflakeDrawer::reset() {
    totalRotation = 0.0;
    xRotationAngle = 0.0;
    yRotationAngle = 0.0;
    isRotatingClockwise = false;
    isRotatingCounterclockwise = false;
    isXRotating = false;
    isYRotating = false;
    zoomFactor = 1.0;
    rightRotationMusic.stop();
    leftRotationMusic.stop();
    normalMusic.stop();
    normalMusic.play();
}

void PentaflakeDrawer::zoomIn() {
    zoomFactor *= 1.1;
}

void PentaflakeDrawer::zoomOut() {
    zoomFactor /= 1.1;
}
