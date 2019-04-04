#include "Cvijet.h"
#include <SFML/Graphics.hpp>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw() 
{

	sf::CircleShape cvijet(40.f);
	cvijet.setFillColor(sf::Color(255, 255, 0));
	cvijet.setOutlineThickness(40.f);

	cvijet.setOutlineColor(sf::Color(128,0,128));
	float a = 320;
	float b = 80;
	cvijet.setPosition(a, b);
	window->draw(cvijet);


	sf::RectangleShape stabljika(sf::Vector2f(200.f, 5.f));
	stabljika.setPosition(360, 200);
	stabljika.rotate(90.f);
	stabljika.setFillColor(sf::Color::Green);
	window->draw(stabljika);
	///////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	//sunce
	sf::CircleShape sunce(85.f);
	sunce.setFillColor(sf::Color(255, 255, 0));
	float x = -53;
	float y = -53;
	
	sunce.setPosition(x, y);

	
	//animacija
	
	int vrijeme = frameClock.getElapsedTime().asSeconds()*10 ;
	if (sunce.getPosition().x+vrijeme<-5)
	{
		sunce.move(vrijeme, 0);
	}
	else
	{
		sunce.setPosition(x, y);
		frameClock.restart();
	}

	window->draw(sunce);



	//zrake
	sf::RectangleShape zraka(sf::Vector2f(250.f, 5.f));
	zraka.setFillColor(sf::Color(255, 255, 0));
	zraka.setPosition(30, 20);
	for (int i = 0; i < 360; i+=20)
	{
		zraka.setRotation(i);
		window->draw(zraka);
	}
	



	//polje
	sf::RectangleShape polje(sf::Vector2f(800,200));
	polje.setFillColor(sf::Color::Green);
	polje.setPosition(0, 400);
	
	window->draw(polje);
	
	//list
	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(360.f, 290.f));
	list.setPoint(1, sf::Vector2f(390.f, 260.f));
	list.setPoint(2, sf::Vector2f(480.f, 260.f));
	list.setPoint(3, sf::Vector2f(400.f, 300.f));
	list.setFillColor(sf::Color::Green);

	

	window->draw(list);


	




	
}
