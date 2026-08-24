#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
	this->window = window;
	size = 20;
}

void Cvijet::draw() {
	if (size < 100 && clock.getElapsedTime().asMilliseconds() > 16) {
		size += 0.5;
		clock.restart();
	}

	sf::CircleShape circle(size);
	circle.setFillColor(sf::Color(255, 255, 0));
	circle.setOutlineColor(sf::Color(255, 0, 0));
	circle.setOutlineThickness(25 * size / 100);
	circle.setPosition(400 - size, 300 - size);

	sf::RectangleShape line(sf::Vector2f(20, 300));
	line.setFillColor(sf::Color(0, 255, 0));
	line.setOrigin({ 0, 300 });
	line.setPosition(400 - 10, 600);

	sf::ConvexShape leaf;
	leaf.setFillColor(sf::Color(0, 255, 0));
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(0, 100));
	leaf.setPoint(1, sf::Vector2f(100, 100));
	leaf.setPoint(2, sf::Vector2f(200, 0));
	leaf.setPoint(3, sf::Vector2f(100, 0));
	leaf.setOrigin({ 0, 100 });
	leaf.scale(size / 200, size / 200);
	sf::ConvexShape leaf2 = leaf;
	leaf.setPosition(400 - 10, 550);
	leaf.rotate(90);
	leaf.scale(-1, -1);
	leaf2.setPosition(400, 500);

	window->draw(line);
	window->draw(leaf);
	window->draw(leaf2);
	window->draw(circle);
}
