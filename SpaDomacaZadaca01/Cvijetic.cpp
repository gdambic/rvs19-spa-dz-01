#include "Cvijetic.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

Cvijetic::Cvijetic(sf::RenderWindow& window) {

	color.r = 255;
	color.r = 125;
	color.r = 55;

	if (i > 10 || i < 0)
	{
		i = 0;
	}

	std::cout << "i:" << i << std::endl;
	stabljika.setSize(sf::Vector2f(120.f, 5.f));
	tucak.setRadius(30.f);
	list.setPointCount(4);
	list.setRadius(80.f);
	latice.resize(5, sf::CircleShape(25));
	for (int i = 0; i < 5; i++)
	{
		latice.at(i).setOrigin(10, 10);

		latice.at(i).setFillColor(sf::Color::Red);
	}
	latice.at(0).setPosition(385, 420);
	latice.at(1).setPosition(415, 400);
	latice.at(2).setPosition(405, 370);
	latice.at(3).setPosition(370, 370);
	latice.at(4).setPosition(360, 400);

	stabljika.setFillColor(sf::Color::Green);
	stabljika.setPosition(400, 450);
	stabljika.setRotation(90);

	list.setFillColor(sf::Color::Green);
	list.setScale(sf::Vector2f(0.2, 0.8));
	list.setPosition(405.f, 525);
	list.setRotation(-120);

	tucak.setFillColor(sf::Color::Yellow);
	tucak.setOrigin(15, 15);
	tucak.setPosition(385, 390);
}

void Cvijetic::anim(sf::Clock& clock) {
	std::cout << clock.getElapsedTime().asSeconds() << std::endl;

	if (i == 0)
	{
		srand(time(nullptr));
		color.r = rand() % 255;
		color.b = rand() % 255;
		color.g = rand() % 255;
	}


	if (clock.getElapsedTime().asSeconds() >= 2)
	{
		ran = !ran;
		clock.restart();
		std::cout << "2s \n";
	}

	if (!ran)
	{
		if (i < 5)
		{

			if (clock.getElapsedTime().asSeconds() >= 0.75f)
			{
				std::cout << "think";
				latice.at(i).setFillColor(color);
				clock.restart();
				i++;
			}
		}
	}

	if (i == 5)
	{
		i = 0;

		clock.restart();
		ran = true;
	}
}



sf::CircleShape Cvijetic::get_tucak() const
{
	return tucak;
}

sf::RectangleShape Cvijetic::get_stabljika() const
{
	return stabljika;
}

std::vector<sf::CircleShape> Cvijetic::get_latice() const
{
	return latice;
}

sf::CircleShape Cvijetic::get_list() const
{
	return list;
}

void Cvijetic::set_tucak(const sf::CircleShape tucak)
{
	this->tucak = tucak;
}

void Cvijetic::set_stabljuka(const sf::RectangleShape stabljika)
{
	this->stabljika = stabljika;
}

void Cvijetic::set_list(const sf::CircleShape list)
{
	this->list = list;
}

void Cvijetic::set_latica(const sf::CircleShape latica, const int i)
{
	this->latice.at(i) = latica;
}

bool Cvijetic::get_ran() const
{
	return ran;
}

void Cvijetic::set_ran(const bool ran)
{
	this->ran = ran;
}
