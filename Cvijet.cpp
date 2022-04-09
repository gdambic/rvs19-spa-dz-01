#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window, sf::Clock clock)
{

	this->window = window; 
	this->clock = clock; 

}

void Cvijet::draw()
{
	
	sf::CircleShape Sun(75);
	Sun.setFillColor(sf::Color{ 255, 215, 0 });
	Sun.setPosition(625, 50);
	
	sf::CircleShape OutterFlower(100);
	OutterFlower.setFillColor(sf::Color{ 255, 0, 0 });
	OutterFlower.setPosition(150, 200);

	sf::CircleShape InnerFlower(65);
	InnerFlower.setFillColor(sf::Color{ 255, 255, 0 });
	InnerFlower.setPosition(185, 235);

	sf::RectangleShape Stem(sf::Vector2f(250, 15)); 
	Stem.setFillColor(sf::Color{ 0, 255, 0 });
	Stem.setPosition(260, 400); 
	Stem.rotate(90); 

	sf::ConvexShape Leaf; 
	Leaf.setPointCount(4); 
	Leaf.setPoint(0, sf::Vector2f(260, 500));
	Leaf.setPoint(1, sf::Vector2f(360, 430));
	Leaf.setPoint(2, sf::Vector2f(480, 380));
	Leaf.setPoint(3, sf::Vector2f(360, 500));
	Leaf.setFillColor(sf::Color{ 0, 255, 0 });

	//std::cout << clock.getElapsedTime().asSeconds() << std::endl;

	if (clock.getElapsedTime().asSeconds() < 1) {
		Sun.scale(1, 1);
	}
	else if (clock.getElapsedTime().asSeconds() < 2) {
		Sun.scale(2, 2);
	}
	else if (clock.getElapsedTime().asSeconds() < 3) {
		Sun.scale(1, 1);
		clock.restart();

	}
		//sf::sleep(sf::milliseconds(100));
	


	window->draw(Sun); 
	window->draw(OutterFlower); 
	window->draw(InnerFlower); 
	window->draw(Stem);
	window->draw(Leaf);

}
