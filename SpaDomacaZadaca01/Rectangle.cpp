#include "Rectangle.h"

Rectangle::Rectangle(
	const sf::Vector2f& position,
	const sf::Vector2f& size,
	const sf::Color& color
) : AnimatedElement(position, sf::Vector2f(0, 0)) {
	rectangleShape.setPosition(position);
	rectangleShape.setSize(size);
	rectangleShape.setFillColor(color);
}

void Rectangle::draw(sf::RenderWindow& window) {
	window.draw(rectangleShape);
}

void Rectangle::update(const sf::Time& deltaTime) {}
