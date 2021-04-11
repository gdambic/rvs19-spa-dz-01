#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace sf;
using namespace std;

Cvijet::Cvijet(sf::RenderWindow* address)
{
	this->address = address;
}


void Cvijet::draw()
{
	sf::Time counter = frameClock.getElapsedTime();
	sf::Time t1 = sf::seconds(1.00f);
	sf::Time t2 = sf::seconds(2.00f);
	sf::Time t3 = sf::seconds(3.00f);
	sf::Time t4 = sf::seconds(4.00f);
	sf::Time t5 = sf::seconds(5.00f);
	sf::Time t6 = sf::seconds(6.00f);
	sf::Time t7 = sf::seconds(7.00f);
	sf::Time t8 = sf::seconds(8.00f);
	sf::Time t9 = sf::seconds(9.00f);
	sf::Time t10 = sf::seconds(11.00f);

	cout << counter.asSeconds() << endl;

	//nebo
	sf::RectangleShape nebo(sf::Vector2f(1000.f, 700.f));
	nebo.setPosition(0.f, 0.f);
	sf::Texture neboTexture;
	neboTexture.loadFromFile("sky.jpg");
	nebo.setTexture(&neboTexture);
	address->draw(nebo);

	//livada
	sf::RectangleShape livada(sf::Vector2f(1000.f, 300.f));
	sf::Texture livadaTexture;
	livadaTexture.loadFromFile("trava.png");
	livada.setTexture(&livadaTexture);
	livada.setPosition(0.f, 700.f);
	address->draw(livada);

	//stabljika1
	sf::RectangleShape stabljika(sf::Vector2f(18.f, 185.f));
	stabljika.setPosition(491.f, 475.f);
	stabljika.setOutlineThickness(6.f);
	stabljika.setOutlineColor(sf::Color(80, 200, 50, 120));
	stabljika.setFillColor(sf::Color(30, 150, 30, 150));
	
	//list
	sf::CircleShape list(50.f, 3.f);
	list.setPosition(508.f, 605.f);
	list.setRotation(350.f);
	list.setOutlineThickness(10.f);
	list.setOutlineColor(sf::Color(80, 200, 50, 120));
	list.setFillColor(sf::Color(30, 150, 30, 150));

	//list2
	sf::CircleShape list2(50.f, 3.f);
	list2.setPosition(505.f, 575.f);
	list2.setRotation(130.f);
	list2.setOutlineThickness(10.f);
	list2.setOutlineColor(sf::Color(80, 200, 50, 120));
	list2.setFillColor(sf::Color(30, 150, 30, 150));

	//stabljika2
	sf::RectangleShape stabljika2(sf::Vector2f(18.f, 220.f));
	stabljika2.setPosition(491.f, 660.f);
	stabljika2.setOutlineThickness(6.f);
	stabljika2.setOutlineColor(sf::Color(80, 200, 50, 120));
	stabljika2.setFillColor(sf::Color(30, 150, 30, 150));

	//cvijet
	sf::CircleShape cvijet(100.f, 12.f);
	cvijet.setPosition(400.f, 274.f);
	cvijet.setFillColor(sf::Color(150, 150, 0, 110));

	//cvijet2
	sf::CircleShape cvijet2(100.f, 12.f);
	cvijet2.setPosition(420.f, 270.f);
	cvijet2.setFillColor(sf::Color(130, 0, 50, 110));

	//cvijet3
	sf::CircleShape cvijet3(100.f, 12.f);
	cvijet3.setPosition(380.f, 270.f);
	cvijet3.setFillColor(sf::Color(130, 0, 50, 140));

	//cvijet4
	sf::CircleShape cvijet4(70.f, 12.f);
	cvijet4.setPosition(430.f, 300.f);
	cvijet4.setFillColor(sf::Color(150, 150, 0, 40));

	//cvijet5
	sf::CircleShape cvijet5(60.f, 12.f);
	cvijet5.setPosition(440.f, 310.f);
	cvijet5.setFillColor(sf::Color(120, 0, 30, 50));

	if (counter >= t1)
	{
		address->draw(stabljika2);
	}
	if (counter >= t2)
	{
		address->draw(list);
	}
	if (counter >= t3)
	{
		address->draw(stabljika);
	}
	if (counter >= t4)
	{
		address->draw(list2);
	}
	if (counter >= t5)
	{
		address->draw(cvijet);
	}
	if (counter >= t6)
	{
		address->draw(cvijet2);
	}
	if (counter >= t7)
	{
		address->draw(cvijet3);
	}
	if (counter >= t8)
	{
		address->draw(cvijet4);
	}
	if (counter >= t9)
	{
		address->draw(cvijet5);
	}
	if (counter >= t10)
	{
		frameClock.restart();
	}
}
