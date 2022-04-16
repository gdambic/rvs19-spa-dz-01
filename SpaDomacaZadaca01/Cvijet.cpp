#include "Cvijet.h"
#include <iostream>
#include <random>

using namespace std;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	tucak.setRadius(32.f);
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setOrigin(15, 15);
	tucak.setPosition(85, 120);
	tucak.setOutlineThickness(10.f);
	tucak.setOutlineColor(sf::Color::Red);
	window->draw(tucak);

	stabljika.setSize(sf::Vector2f(115.f, 5.f));
	stabljika.setFillColor(sf::Color::Color(34, 139, 34));
	stabljika.setRotation(90);
	stabljika.setPosition(100, 180);
	window->draw(stabljika);

	list.setPointCount(4);
	list.setRadius(80.f);
	list.setFillColor(sf::Color::Color(34, 139, 34));
	list.setScale(sf::Vector2f(0.2, 0.8));
	list.setRotation(-120);
	list.setPosition(108.f, 230);
	window->draw(list);

	zemlja.setOrigin(15, 15);
	zemlja.setSize(sf::Vector2f(330.0f, 1000.0f));
	zemlja.setFillColor(sf::Color::Color(139, 69, 19));
	zemlja.setRotation(90);
	zemlja.setPosition(800, 285);
	window->draw(zemlja);

	animate_shape_tucak(tucak);
}

void Cvijet::animate_shape_tucak(sf::CircleShape &c)
{
	srand(time(NULL));
	//c.setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	//c.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	c.setOutlineThickness(rand() % 20);
	window->draw(c);
}

sf::CircleShape Cvijet::get_tucak() const
{
	return tucak;
}

void Cvijet::set_tucak(const sf::CircleShape tucak)
{
	this->tucak = tucak;
}

sf::RectangleShape Cvijet::get_stabljika() const
{
	return stabljika;
}

void Cvijet::set_stabljika(const sf::RectangleShape stabljika)
{
	this->stabljika = stabljika;
}

sf::CircleShape Cvijet::get_latica() const
{
	return latica;
}

void Cvijet::set_latica(const sf::CircleShape latica)
{
	this->latica = latica;
}

sf::CircleShape Cvijet::get_list() const
{
	return list;
}

void Cvijet::set_list(const sf::CircleShape list)
{
	this->list = list;
}

sf::RectangleShape Cvijet::get_Zemlja() const
{
	return sf::RectangleShape();
}

void Cvijet::set_Zemlja(const sf::RectangleShape zemlja)
{
	this->zemlja = zemlja;
}

sf::RectangleShape Cvijet::get_testing() const
{
	return zemlja;
}

