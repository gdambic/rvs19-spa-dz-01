#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class EllipseShape : public sf::Shape
{
public:

    explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
        m_radius(radius)
    {
        update();
    }

    void setRadius(const sf::Vector2f& radius)
    {
        m_radius = radius;
        update();
    }

    const sf::Vector2f& getRadius() const
    {
        return m_radius;
    }

    

    virtual sf::Vector2f getPoint(unsigned int index) const
    {
        static const float pi = 3.141592654f;

        float angle = index * 2 * pi / 30 - pi / 2;
        float x = std::cos(angle) * m_radius.x;
        float y = std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x + x, m_radius.y + y);
    }

private:

    sf::Vector2f m_radius;
};