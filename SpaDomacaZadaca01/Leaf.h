#pragma once

#include "AnimatedElement.h"

class Leaf : public AnimatedElement {
private:
	sf::ConvexShape leaf;
	int facesDirection;
	float animationDirection;
	float pixelsMoved;
	const static float MAX_PIXELS_MOVED;

public:
	Leaf(
		const sf::Vector2f& position,
		const sf::Vector2f& velocity,
		int facesDirection
	);
	void draw(sf::RenderWindow& window);
	void update(const sf::Time& deltaTime);
};
