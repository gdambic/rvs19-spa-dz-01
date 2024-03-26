#pragma once

#include "CelestialBody.h"

class Moon : public CelestialBody {
private:
	sf::CircleShape crescentCover;
	sf::Color crescentCoverColor;

public:
	Moon(
		const sf::Color& crescentCoverColor,
		const sf::Vector2f& orbitCenter,
		float radius,
		float orbitRadius,
		float angle,
		float angularVelocity
	);
	virtual void draw(sf::RenderWindow& window) override;
	void setCrescentCoverColor(const sf::Color& color);
};
