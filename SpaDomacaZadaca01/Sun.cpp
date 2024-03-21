#include "Sun.h"

Sun::Sun(
	const sf::Vector2f& position,
	const sf::Vector2f& velocity
) : AnimatedElement(position, velocity), sun(50.f) {
	sun.setFillColor(sf::Color::Yellow);
}

void Sun::draw(sf::RenderWindow& window) {
	sun.setPosition(position);
	window.draw(sun);
}

void Sun::update(const sf::Time& deltaTime) {
	position += velocity * deltaTime.asSeconds();
}
