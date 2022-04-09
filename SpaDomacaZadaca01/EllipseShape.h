#pragma once
#include <SFML/Graphics.hpp>

class EllipseShape : public sf::Shape
{
public:
	EllipseShape(sf::Vector2f radius);

	virtual sf::Vector2f getPoint(std::size_t index) const;
	virtual std::size_t getPointCount() const;

private:
	sf::Vector2f radius;

};

