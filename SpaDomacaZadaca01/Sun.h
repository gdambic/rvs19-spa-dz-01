#pragma once

#include "CelestialBody.h"

class Sun : public CelestialBody {
public:
	Sun(
		const sf::Vector2f& orbitCenter,
		float radius,
		float orbitRadius,
		float angle,
		float angularVelocity
	);
	virtual void draw(sf::RenderWindow& window) override;
	float getAngle() const;
};
