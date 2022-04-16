#include "Nebo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

using namespace std;

Nebo::Nebo(sf::RenderWindow* window)
{
    this->window = window;
}

void Nebo::draw()
{
	int num = gen_randNum();
	if (num % 2 == 0)
	{
		nebo.setOrigin(15, 15);
		nebo.setSize(sf::Vector2f(330.0f, 1000.0f));
		nebo.setFillColor(sf::Color::Color(135, 206, 250));
		nebo.setRotation(90);
		nebo.setPosition(800, 15);
		window->draw(nebo);
	}
	else if (num % 2 != 0)
	{
		nebo.setOrigin(15, 15);
		nebo.setSize(sf::Vector2f(330.0f, 1000.0f));
		nebo.setFillColor(sf::Color::Color(70, 130, 180));
		nebo.setRotation(90);
		nebo.setPosition(800, 15);
		window->draw(nebo);
	}

	if (num % 2 == 0)
	{
		sunce.setRadius(40.f);
		sunce.setFillColor(sf::Color::Yellow);
		sunce.setOrigin(15, 15);
		sunce.setPosition(480, 40);
		window->draw(sunce);
	}
	else if (num % 2 != 0)
	{
		sunce.setRadius(40.f);
		sunce.setFillColor(sf::Color::Yellow);
		sunce.setOrigin(15, 15);
		sunce.setPosition(400, 5);
		window->draw(sunce);
	}
}

sf::RectangleShape Nebo::get_nebo() const
{
    return nebo;
}

void Nebo::set_nebo(const sf::RectangleShape nebo)
{
    this->nebo = nebo;
}

sf::CircleShape Nebo::get_Sunce() const
{
	return sunce;
}

void Nebo::set_Sunce(const sf::CircleShape sunce)
{
	this->sunce = sunce;
}

int Nebo::gen_randNum()
{
	srand(time(NULL));
	int min = 1;
	int max = 100;
	int range = max - min + 1;

	int num = rand() % range + min;
	return num;
}
