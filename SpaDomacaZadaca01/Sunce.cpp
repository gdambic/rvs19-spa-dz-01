#include "Sunce.h"
#include <iostream>

//KONSTRUKTOR
Sunce::Sunce(sf::RenderWindow * prozor, float velicinaKruga)
{
this->prozor = prozor;
this->velicinaKruga = velicinaKruga;
}

//DEKONSTRUKTOR
Sunce::~Sunce() { }

//NACRTAJ
void Sunce::draw()
{
	prozor->draw(oblikKruga());
	animirajSunce();
}

//ANIMACIJA SUNCA
void Sunce::animirajSunce()
{
	sf::Time srednjeVrijeme = animacijaObjekta.getElapsedTime() - prosloVrijeme;
	prosloVrijeme += srednjeVrijeme;
	this->velicinaKruga = 10 + (prosloVrijeme.asSeconds() * 5);
	sf::Time krajnjeVrijeme = sf::seconds(2.0f);

	if (prosloVrijeme.asSeconds() > krajnjeVrijeme.asSeconds()) {
		animacijaObjekta.restart();
	}
}

//KRUG SUNCA
sf::CircleShape Sunce::oblikKruga()
{
	sf::CircleShape krug(velicinaKruga);
	krug.setFillColor(sf::Color::Yellow);
	krug.setPosition(220.f, 5.f);

	return krug;
}
