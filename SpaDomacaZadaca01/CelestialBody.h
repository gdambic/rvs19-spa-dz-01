#pragma once

#include "AnimatedElement.h"

class CelestialBody : public AnimatedElement {
protected:
	float radius;
	sf::CircleShape circleShape;

	const sf::Vector2f orbitCenter;
	float orbitRadius;
	float angle;

public:
	CelestialBody(
		const sf::Vector2f& orbitCenter,
		float radius,
		float orbitRadius,
		float angle,
		float angularVelocity
	) : AnimatedElement(
		sf::Vector2f(orbitCenter.x + orbitRadius * std::cos(angle), orbitCenter.y + orbitRadius * std::sin(angle)),
		sf::Vector2f(angularVelocity, angularVelocity)
	), radius(radius),
		circleShape(radius),
		orbitCenter(orbitCenter),
		orbitRadius(orbitRadius),
		angle(angle) {
		circleShape.setOrigin(radius, radius);
	}
	void update(const sf::Time& deltaTime) override;
};
