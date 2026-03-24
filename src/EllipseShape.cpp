//
//  EllipseShape.cpp
//  https://www.sfml-dev.org/tutorials/3.0/graphics/shape/#lines
//

#include "EllipseShape.hh"

EllipseShape::EllipseShape(sf::Vector2f radius) : m_radius(radius) {
   update();
}

void EllipseShape::setRadius(sf::Vector2f radius) {
   m_radius = radius;
   update();
}

sf::Vector2f EllipseShape::getRadius() const {
   return m_radius;
}

std::size_t EllipseShape::getPointCount() const {
   return 30; // fixed, but could be an attribute of the class if needed
}

sf::Vector2f EllipseShape::getPoint(std::size_t index) const {
   static constexpr float pi = 3.141592654f;

   float angle = index * 2 * pi / getPointCount() - pi / 2;
   float x     = std::cos(angle) * m_radius.x;
   float y     = std::sin(angle) * m_radius.y;

   return m_radius + sf::Vector2f(x, y);
}