#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window) : _window(window)
{
}

sf::CircleShape Cvijet::colorChange(sf::CircleShape &circle)
{
	sf::Time currentTime = _clock.getElapsedTime();
	float colorValue = (std::sin(currentTime.asSeconds() * 3) + 1) / 2;
	circle.setOutlineColor(sf::Color(colorValue * 255, 255, (1 - colorValue) * 255));

	return circle;
}

void Cvijet::drawFlower()
{
	sf::CircleShape flower(60.f);
	flower.setFillColor(sf::Color(255, 128, 0));
	flower.setOutlineThickness(30.f);
	flower.setOutlineColor(sf::Color(255, 0, 0));
	flower.setPosition(50.f, 50.f);

	colorChange(flower);

	_window.draw(flower);
}

void Cvijet::drawStem()
{
	sf::RectangleShape stem(sf::Vector2f(10.f, 400.f));
	stem.setFillColor(sf::Color(0, 255, 0));
	stem.setPosition(105.f, 50.f);

	_window.draw(stem);
}

void Cvijet::drawLeaf()
{
	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setFillColor(sf::Color(0, 255, 0));

	leaf.setPoint(0, sf::Vector2f(110.f, 400.f));
	leaf.setPoint(1, sf::Vector2f(150.f, 350.f));
	leaf.setPoint(2, sf::Vector2f(300.f, 320.f));
	leaf.setPoint(3, sf::Vector2f(200.f, 400.f));

	_window.draw(leaf);
}

void Cvijet::drawSun()
{
	sf::CircleShape sun(20.f);
	sun.setFillColor(sf::Color(255, 255, 0));

	_window.draw(sun);
}

void Cvijet::draw()
{
	drawSun();
	drawStem();
	drawLeaf();
	drawFlower();
}


