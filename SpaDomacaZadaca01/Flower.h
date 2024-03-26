#pragma once

#include "AnimatedElement.h"
#include "Leaf.h"

class Flower : public AnimatedElement {
private:
	sf::RectangleShape stem;
	sf::CircleShape flower;
	sf::CircleShape flowerInside;
	Leaf leftLeaf;
	Leaf rightLeaf;

public:
	Flower(
		const sf::Vector2f& position,
		const sf::Vector2f& velocity,
		const sf::Color& flowerColor,
		float stemLength
	);
	void draw(sf::RenderWindow& window) override;
	void update(const sf::Time& deltaTime) override;
};
