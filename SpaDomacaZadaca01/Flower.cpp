#include "Flower.h"

Flower::Flower(
	int petalNum,
	float petalSize,
	float stemSize,
	float centerSize,
	int leavesNum,
	float leafSize,
	sf::Color petalColor,
	sf::Color centerColorw,
	sf::Color stemColor,
	sf::Color leafColor){



}

void Flower::draw(sf::RenderWindow& window) {
	
	sf::CircleShape circle(50); // Circle with a radius of 50
	circle.setPosition(400 - 50, 300 - 50); // Position it in the center of an 800x600 window
	circle.setFillColor(sf::Color::Red); // Make it red for visibility
	window.draw(circle);
}