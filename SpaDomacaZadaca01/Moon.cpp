#include "Moon.h"

Moon::Moon(
	const sf::Color& crescentCoverColor,
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
), crescentCover(radius) {
	sf::Color moonColor(241, 233, 207);
	circleShape.setFillColor(moonColor);
	setCrescentCoverColor(crescentCoverColor);
	crescentCover.setOrigin(radius, radius);
}

void Moon::draw(sf::RenderWindow& window) {
	circleShape.setPosition(position);
	crescentCover.setPosition(position.x + (this->radius / 2.f), position.y - (this->radius / 4.f));
	window.draw(circleShape);
	window.draw(crescentCover);
}

void Moon::setCrescentCoverColor(const sf::Color& crescentCoverColor) {
	this->crescentCoverColor = crescentCoverColor;
	crescentCover.setFillColor(crescentCoverColor);
}
