#include "Cvijet.h"
#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	set_Background();
	set_Moon();
	set_Circle();
	set_Prince();
	set_Flower();
	set_Stem();
}

void Cvijet::set_Background()
{
	Background.setSize(sf::Vector2f(800.f, 600.f));
	TexBackground.loadFromFile("background.png");
	Background.setTexture(&TexBackground);
}

void Cvijet::set_Moon()
{
	Moon.setRadius(70.f);
	Moon.setOrigin(sf::Vector2f(35.f, 35.f));
	Moon.setPosition(sf::Vector2f(300.f, 100.f));
	TexMoon.loadFromFile("moon.png");
	Moon.setTexture(&TexMoon);
	Moon.setOutlineThickness(15.f);
	Moon.setOutlineColor(sf::Color(255, 255, 210, 15));
}

void Cvijet::set_Circle()
{
	Circle.setRadius(70.f);
	Circle.setOrigin(sf::Vector2f(35.f, 35.f));
	Circle.setFillColor(sf::Color(255, 255, 210, 15));
	Circle.setPosition(Moon.getPosition());
}

void Cvijet::set_Prince()
{
	Prince.setSize(sf::Vector2f(400.f, 400.f));
	Prince.setOrigin(200.f, 200.f);
	TexPrince.loadFromFile("prince.png");
	Prince.setTexture(&TexPrince);
	Prince.setPosition(140, 380);
}

void Cvijet::set_Flower()
{
	Flower.setRadius(50.f);
	Flower.setOrigin(25.f, 50.f);
	TexFlower.loadFromFile("flower.png");
	Flower.setTexture(&TexFlower);
	Flower.setPosition(550.f, 350.f);
}

void Cvijet::set_Stem()
{
	Stem.setSize(sf::Vector2f(60.f, 80.f));
	Stem.setOrigin(3.f, 0.f);
	TexStem.loadFromFile("stem.png");
	Stem.setTexture(&TexStem);
	Stem.setPosition(Flower.getPosition());
}

void Cvijet::draw()
{
	float frequency = 3;
	Time = Clock.getElapsedTime();
	float aura = 7 + sin(Time.asSeconds()/frequency * 2 * 3.14159265358979323846) * 10;
	Moon.setOutlineThickness(aura);

	window->draw(Background);
	window->draw(Prince);
	window->draw(Stem);
	window->draw(Flower);
	window->draw(Circle);
	window->draw(Moon);
	
}










