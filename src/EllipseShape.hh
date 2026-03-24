//
//  EllipseShape.hh
//  https://www.sfml-dev.org/tutorials/3.0/graphics/shape/#lines
//

#pragma once
#include <SFML/Graphics.hpp>

class EllipseShape : public sf::Shape {
   private:
      sf::Vector2f m_radius;

   public:
      explicit EllipseShape(sf::Vector2f radius = sf::Vector2f(0, 0));
      void setRadius(sf::Vector2f radius);
      sf::Vector2f getRadius() const;
      std::size_t getPointCount() const override;
      sf::Vector2f getPoint(std::size_t index) const override;
};