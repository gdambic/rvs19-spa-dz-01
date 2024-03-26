#include "Sun.h"

Sun::Sun(
	const sf::Vector2f& orbitCenter,
	float radius,
	float orbitRadius,
	float angle,
	float angularVelocity
) : CelestialBody(
	orbitCenter,
	radius,
	orbitRadius,
	angle,
	angularVelocity
) {
	circleShape.setFillColor(sf::Color::Yellow);
}

void Sun::draw(sf::RenderWindow& window) {
	circleShape.setPosition(position);
	window.draw(circleShape);
}

float Sun::getAngle() const {
	return angle;
}
