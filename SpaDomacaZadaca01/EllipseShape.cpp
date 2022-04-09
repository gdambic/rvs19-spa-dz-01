#include "EllipseShape.h"

EllipseShape::EllipseShape(sf::Vector2f radius)
{
    this->radius = radius;
    update();
}

sf::Vector2f EllipseShape::getPoint(std::size_t index) const
{
    static const float PI = 3.141592;

    float angle = index * 2 * PI / getPointCount() - PI / 2;
    float x = std::cos(angle) * radius.x;
    float y = std::sin(angle) * radius.y;

    return sf::Vector2f(radius.x + x, radius.y + y);
}

std::size_t EllipseShape::getPointCount() const
{
    return 30;
}
