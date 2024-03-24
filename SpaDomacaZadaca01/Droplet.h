#pragma once

#include <random>
#include "AnimatedElement.h"

class Droplet : public AnimatedElement {
private:
	static const float MIN_WIDTH;
	static const float MAX_WIDTH;
	static const float MIN_HEIGHT;
	static const float MAX_HEIGHT;
	static const float MIN_VELOCITY;
	static const float MAX_VELOCITY;
	static const float MIN_GRAVITY;
	static const float MAX_GRAVITY;
	static const float START;

	float width;
	float gravity;
	float fallHeight;

	std::default_random_engine& gen;
	std::uniform_real_distribution<float> dis;
	sf::RectangleShape droplet;

public:
	float nextFloat(float origin, float bound);
	Droplet(std::default_random_engine& gen);
	void draw(sf::RenderWindow& window) override;
	void update(const sf::Time& deltaTime) override;
	bool hasFallen() const;
};
