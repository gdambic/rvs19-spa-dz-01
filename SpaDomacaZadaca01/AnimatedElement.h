#pragma once

#include <SFML/Graphics.hpp>

class AnimatedElement {
protected:
	sf::Vector2f position;
	sf::Vector2f velocity;

public:
	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;

	AnimatedElement(
		const sf::Vector2f& position,
		const sf::Vector2f& velocity
	) : position(position), velocity(velocity) {}
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(const sf::Time& deltaTime) = 0;
};
