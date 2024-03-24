#include "CelestialBody.h"

void CelestialBody::update(const sf::Time& deltaTime) {
	angle += velocity.x * deltaTime.asSeconds(); // velocity's x or y, doesn't matter, both should be the same
	position.x = orbitCenter.x + orbitRadius * std::cos(angle);
	position.y = orbitCenter.y + orbitRadius * std::sin(angle);
}
