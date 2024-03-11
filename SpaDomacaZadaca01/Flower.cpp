#include "Flower.h"

Flower::Flower(
    int petalNum,
    float petalSize,
    float stemSize,
    float centerSize,
    int leavesNum,
    float leafSize,
    sf::Color petalColor,
    sf::Color centerColor,
    sf::Color stemColor,
    sf::Color leafColor){
}

void Flower::draw(sf::RenderWindow& window) {
	

	sf::CircleShape center(50); 
	center.setPosition(400 - 50, 300 - 50); 
	center.setFillColor(sf::Color::Red),
	window.draw(center);
}

//problem: i can draw the circle using hardcoded values, but if i use my variable as a value, the circle is gone.