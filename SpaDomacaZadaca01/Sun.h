#pragma once

#include "AnimatedElement.h"

class Sun : public AnimatedElement {
private:
	sf::CircleShape sun;

public:
	Sun(const sf::Vector2f& position, const sf::Vector2f& velocity);
	virtual void draw(sf::RenderWindow& window) override;
	virtual void update(const sf::Time& deltaTime) override;
};

