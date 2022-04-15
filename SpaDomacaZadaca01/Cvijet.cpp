#include "Cvijet.h"
#include<SFML/Graphics.hpp>
#include<iostream>
//using namespace sf;
Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}
void Cvijet::draw()
{
	sf::CircleShape ruza(90.f,8);
	ruza.setFillColor(sf::Color::Red);
	ruza.setOrigin(-300, -40);
	sf::CircleShape unutarruze(35.f);
	unutarruze.setOrigin(-360,-95);
	sf::RectangleShape stabiljka(sf::Vector2f(400, 8.f));
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.rotate(90.f);
	stabiljka.setOrigin(-220,390);
	sf::CircleShape trn1(20.f, 3);
	trn1.setFillColor(sf::Color::Green);
	trn1.setOrigin(-350,-260);
	sf::CircleShape trn2(20.f, 3);
	trn2.setFillColor(sf::Color::Green);
	trn2.setOrigin(-380, -360);
	sf::CircleShape trn3(20.f, 3);
	trn3.setFillColor(sf::Color::Green);
	trn3.setOrigin(-350, -460);
	sf::CircleShape trn4(20.f, 3);
	trn4.setFillColor(sf::Color::Green);
	trn4.setOrigin(-380, -560);
	sf::CircleShape sun(50.f);
	sun.setPosition(1.f, 1.f);
	sun.setFillColor(sf::Color::Yellow);
	if (clock.getElapsedTime().asMilliseconds() > 1000)
	{
		sun.setPosition(140.f - 250.f * ((clock.getElapsedTime().asMilliseconds() - 1000) / 1000.f), 30.f);

		if (clock.getElapsedTime().asMilliseconds() >= 5000)
		{
			clock.restart();
		}
	}
	else
	{


		sun.setPosition(220.f + 250.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);


	}
	window->draw(ruza);
	window->draw(unutarruze);
	window->draw(stabiljka);
	window->draw(trn1);
	window->draw(trn2);
	window->draw(trn3);
	window->draw(trn4);
	window->draw(sun);



}









