#include "Flower.h"

Flower::Flower(
	const sf::Vector2f& position,
	const sf::Vector2f& velocity,
	const sf::Color& flowerColor,
	float stemLength
) : AnimatedElement(position, velocity),
	stem(sf::Vector2f(13.f, stemLength)),
	flower(sf::CircleShape(70.f)),
	flowerInside(sf::CircleShape(35.f)),
	leftLeaf(sf::Vector2f(position.x, position.y + stemLength / 1.6f), velocity, -1),
	rightLeaf(sf::Vector2f(position.x, position.y + stemLength / 1.6f), velocity, 1) {
	stem.setFillColor(sf::Color(0, 100, 0));
	stem.setPosition(position);
	stem.setOrigin(stem.getSize().x / 2, 0);

	flower.setPosition(position);
	flower.setOrigin(flower.getRadius(), flower.getRadius());
	flower.setFillColor(flowerColor);
	flowerInside.setPosition(position);
	flowerInside.setOrigin(flowerInside.getRadius(), flowerInside.getRadius());
	flowerInside.setFillColor(sf::Color(255, 165, 0));
}

void Flower::draw(sf::RenderWindow& window) {
	window.draw(stem);
	window.draw(flower);
	window.draw(flowerInside);
	leftLeaf.draw(window);
	rightLeaf.draw(window);
}

void Flower::update(const sf::Time& deltaTime) {
	leftLeaf.update(deltaTime);
	rightLeaf.update(deltaTime);
}
