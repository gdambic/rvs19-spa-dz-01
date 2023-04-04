#include "Flower.h"
#include<ctime>
#include <chrono>
#include <SFML/Graphics.hpp>




Flower::Flower(sf::RenderWindow* window)
{
	this->window = window;
	float radius = 20;
}

int Flower::randc()
{
	return rand()%251;
}


void Flower::draw()
{
	srand(time(nullptr));

	if (radius > 200) {
		window->clear(sf::Color::Blue);
		
	}
	if (radius < 700) {
		radius++;
	}

	sf::CircleShape sun(50.f);
	sun.setFillColor(sf::Color::Yellow);
	sun.setRadius(radius*0.5);
	sun.setPosition(400-radius*0.5, 500-radius * 0.5);
	window->draw(sun);
	

	sf::RectangleShape grass(sf::Vector2f(800, 200));
	grass.setFillColor(sf::Color(34, 139, 34));
	grass.setPosition(0, 400);
	window->draw(grass);

	sf::RectangleShape stem(sf::Vector2f(20, 200));
	stem.setFillColor(sf::Color(0, 128, 0));
	stem.setPosition(240, 280);
	window->draw(stem);

	sf::CircleShape petals(50.f);
	petals.setFillColor(sf::Color(250, 250, 0));
	petals.setOutlineThickness(30.f);
	petals.setOutlineColor(sf::Color(randc(), randc(), randc()));
	petals.setPosition(200, 155);
	window->draw(petals);
	
}
	
	
	
	
	



