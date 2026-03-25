#include "test.h"
#include <cmath>
Cvijet::Cvijet(sf::RenderWindow* window)
{

	this->window = window;

	//initialize the shapes for the flower
	

	// the stem
	stem.setSize(sf::Vector2f(10.f,200.f));
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(395.f, 300.f);

	// the center of the flower
	center.setRadius(40.f);
	center.setFillColor(sf::Color::Yellow);

	center.setOrigin(40.f, 40.f);
	center.setPosition(400.f, 290.f);

	// the petal
	petal.setRadius(40.f);
	petal.setFillColor(sf::Color::Red);
	petal.setOrigin(40.f, 40.f);
}

void Cvijet::draw()
{
	float time = clock.getElapsedTime().asSeconds();

	//frequency of animation 
	float scale = 1.3f + 0.07f * sin(time * 6.0f); 

	center.setScale(scale, scale);
	petal.setScale(scale, scale);

	window->draw(stem);

	//t
	petal.setPosition(400.0f, 230.0f);
	window->draw(petal);
	//b
	petal.setPosition(400.0f, 345.0f);
	window->draw(petal);
	//l
	petal.setPosition(340.0f, 290.0f);
	window->draw(petal);
	//r
	petal.setPosition(460.0f, 290.0f);
	window->draw(petal);

	window->draw(center);

}