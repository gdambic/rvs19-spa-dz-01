#include "test.h"
#include <cmath>
Cvijet::Cvijet(sf::RenderWindow* window)
{

	this->window = window;

	//initialize the shapes for the flower and the sun
	
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

	// the sun rays
	sun.setRadius(60.f);
	sun.setFillColor(sf::Color(255, 255, 0, 150)); 
	sun.setOrigin(60.f, 60.f);
	sun.setPosition(100.f, 100.f);

	//the sun center
	sunCenter.setRadius(40.f);
	sunCenter.setFillColor(sf::Color(255, 215, 0));
	sunCenter.setOrigin(40.f, 40.f);
	sunCenter.setPosition(100.f, 100.f);
}

void Cvijet::draw()
{
	float time = clock.getElapsedTime().asSeconds();

	//frequency of animation 
	float scale = 1.3f + 0.07f * sin(time * 6.0f); 
	float sunPulse = 1.0f + 0.1f * sin(time * 2.0f);

	//animation of the sun

	sun.setScale(sunPulse, sunPulse);

	// sun
	window->draw(sun);
	window->draw(sunCenter);


	//animation of the flower
	center.setScale(scale, scale);
	petal.setScale(scale, scale);

	//stem
	window->draw(stem);

	//t petal
	petal.setPosition(400.0f, 230.0f);
	window->draw(petal);
	//b petal
	petal.setPosition(400.0f, 345.0f);
	window->draw(petal);
	//l petal
	petal.setPosition(340.0f, 290.0f);
	window->draw(petal);
	//r petal
	petal.setPosition(460.0f, 290.0f);
	window->draw(petal);

	//center
	window->draw(center);

}