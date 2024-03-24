#pragma once

#include "AnimatedElement.h"

class Rectangle : public AnimatedElement {
private:
	sf::RectangleShape rectangleShape;

public:
	Rectangle(
		const sf::Vector2f& position,
		const sf::Vector2f& size,
		const sf::Color& color
	);
	void draw(sf::RenderWindow& window);
	void update(const sf::Time& deltaTime);
};
