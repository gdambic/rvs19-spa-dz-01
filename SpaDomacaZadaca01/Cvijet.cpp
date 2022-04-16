#include "Cvijet.h"
#include "SFML/Graphics.hpp"
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{	//------------NEBO-------------
	sf::RectangleShape nebo(sf::Vector2f(800, 480));
	nebo.setFillColor(sf::Color::Cyan);
	nebo.setPosition(0, 0);
	window->draw(nebo);
	//----------------BREZULJAK-----------
	sf::CircleShape brezuljak;
	brezuljak.setRadius(60);
	brezuljak.setFillColor(sf::Color::Green);
	brezuljak.setOutlineColor(sf::Color::White);
	brezuljak.setOutlineThickness(1);
	brezuljak.setPosition(193, 450);
	window->draw(brezuljak);
	//----------------TRAVA-----------------
	sf::RectangleShape trava(sf::Vector2f(800, 120));
	trava.setFillColor(sf::Color::Green);
	trava.setOutlineColor(sf::Color::White);
	trava.setOutlineThickness(1);
	trava.setPosition(0, 480);
	window->draw(trava);
	//---------------LIST---------------------
	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(253, 380));
	list.setPoint(1, sf::Vector2f(350, 350));
	list.setPoint(2, sf::Vector2f(380, 315));
	list.setPoint(3, sf::Vector2f(320, 320));
	list.setFillColor(sf::Color::Green);
	list.setOutlineColor(sf::Color::White);
	list.setOutlineThickness(1);
	//animacija lista pomoću tipkovnice
	enum Smjer { Dolje };
	sf::Vector2i v1(0, Dolje);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		v1.y = Dolje;
		list.move(0, 150);
	}
	window->draw(list);
	//---------------STABLJIKA--------------------
	sf::RectangleShape stabljika(sf::Vector2f(5, 150));
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setPosition(250, 300);
	window->draw(stabljika);
	//----------------SREDINA CVIJETA-----------------
	sf::CircleShape sredina;
	sredina.setRadius(30);
	sredina.setFillColor(sf::Color::White);
	sredina.setPosition(225, 245);
	window->draw(sredina);
	//------------------LATICE------------------------
	sf::CircleShape latica1;
	latica1.setRadius(17);
	latica1.setFillColor(sf::Color::Magenta);
	latica1.setPosition(220, 230);
	latica1.setOutlineColor(sf::Color::Yellow);
	latica1.setOutlineThickness(1);
	window->draw(latica1);

	sf::CircleShape latica2;
	latica2.setRadius(17);
	latica2.setFillColor(sf::Color::Magenta);
	latica2.setPosition(248, 227);
	latica2.setOutlineColor(sf::Color::Yellow);
	latica2.setOutlineThickness(1);
	window->draw(latica2);

	sf::CircleShape latica3;
	latica3.setRadius(17);
	latica3.setFillColor(sf::Color::Magenta);
	latica3.setPosition(269, 248);
	latica3.setOutlineColor(sf::Color::Yellow);
	latica3.setOutlineThickness(1);
	window->draw(latica3);

	sf::CircleShape latica4;
	latica4.setRadius(17);
	latica4.setFillColor(sf::Color::Magenta);
	latica4.setPosition(264, 277);
	latica4.setOutlineColor(sf::Color::Yellow);
	latica4.setOutlineThickness(1);
	window->draw(latica4);

	sf::CircleShape latica5;
	latica5.setRadius(17);
	latica5.setFillColor(sf::Color::Magenta);
	latica5.setPosition(238, 289);
	latica5.setOutlineColor(sf::Color::Yellow);
	latica5.setOutlineThickness(1);
	window->draw(latica5);

	sf::CircleShape latica6;
	latica6.setRadius(17);
	latica6.setFillColor(sf::Color::Magenta);
	latica6.setPosition(215, 277);
	latica6.setOutlineColor(sf::Color::Yellow);
	latica6.setOutlineThickness(1);
	window->draw(latica6);

	sf::CircleShape latica7;
	latica7.setRadius(17);
	latica7.setFillColor(sf::Color::Magenta);
	latica7.setPosition(208, 252);
	latica7.setOutlineColor(sf::Color::Yellow);
	latica7.setOutlineThickness(1);
	window->draw(latica7);
}