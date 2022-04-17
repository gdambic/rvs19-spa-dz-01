#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(RenderWindow *window)
{
	this->window=window;
}

void Cvijet::draw()
{
	//nebo
	Texture nebo;
	if (!nebo.loadFromFile("nebo_1.jpg"))
	{
		std::cout<<"404"<<std::endl;
	}
	Sprite sprite(nebo, IntRect(0,0,800,550));
	sprite.setScale(3, 4);
	window->draw(sprite);

	//okrugli cvijet
	CircleShape core;
	core.setRadius(50);
	core.setOutlineThickness(20);
	core.setOutlineColor(Color::Magenta);
	core.setFillColor(Color::Yellow);
	core.setOrigin(50,50);
	core.setPosition(Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	window->draw(core);

	//stabljika
	RectangleShape stabljika;
	stabljika.setSize(Vector2f(10, 230));
	stabljika.setFillColor(Color::Green);
	stabljika.setPosition(Vector2f(395, 370));
	window->draw(stabljika);
	
	//list
	ConvexShape listovi;
	listovi.setPointCount(9);
	listovi.setFillColor(Color::Green);
	listovi.setPoint(0, sf::Vector2f(395.f,480.f));
	listovi.setPoint(1, sf::Vector2f(320.f,445.f));
	listovi.setPoint(2, sf::Vector2f(280.f,460.f));
	listovi.setPoint(3, sf::Vector2f(330.f, 440.f));
	listovi.setPoint(4, sf::Vector2f(395.f,480.f));
	listovi.setPoint(5, sf::Vector2f(465.f, 440.f));
	listovi.setPoint(6, sf::Vector2f(515.f,455.f));
	listovi.setPoint(7, sf::Vector2f(485.f,447.f));
	listovi.setPoint(8, sf::Vector2f(395.f,480.f));
	window->draw(listovi);

	//livada
	RectangleShape livada;
	livada.setSize(Vector2f(800,50));
	livada.setFillColor(Color::Green);
	livada.setPosition(Vector2f(0,550));
	window->draw(livada);

	//sunce
	CircleShape sunce(150);
	sunce.setFillColor(Color::Yellow);
	sunce.setOrigin(Vector2f(150, 150));
	sunce.setPosition(Vector2f(175, 50));
	window->draw(sunce);
	
	CircleShape naocale,dodatak;
	naocale.setRadius(20);
	naocale.setFillColor(Color::Black);
	naocale.setOrigin(Vector2f(20, 20));
	naocale.setPosition(Vector2f(140, 40));
	window->draw(naocale);

	dodatak.setRadius(20);
	dodatak.setFillColor(Color::Black);
	dodatak.setOrigin(Vector2f(20, 20));
	dodatak.setPosition(Vector2f(210, 40));
	window->draw(dodatak);

	RectangleShape poveznica(Vector2f(70, 5));
	poveznica.setFillColor(Color::Black);
	poveznica.setPosition(Vector2f(145, 30));
	window->draw(poveznica);
	
	ConvexShape osmijeh;
	osmijeh.setPointCount(6);
	osmijeh.setFillColor(Color::Black);

	osmijeh.setPoint(0, Vector2f(175, 100));
	osmijeh.setPoint(1, Vector2f(245, 95));
	osmijeh.setPoint(2, Vector2f(210, 110));
	osmijeh.setPoint(3, Vector2f(175, 120));
	osmijeh.setPoint(4, Vector2f(140, 110));
	osmijeh.setPoint(5, Vector2f(105, 95));
	window->draw(osmijeh);
}



