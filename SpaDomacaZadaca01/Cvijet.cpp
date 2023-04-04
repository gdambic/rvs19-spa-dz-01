#include "Cvijet.h"

void Cvijet::initPetals(sf::RenderWindow* window)
{
	petals.setRadius(80);
	petals.setPosition(sf::Vector2f(300, 97));
	petals.setFillColor(sf::Color(200, 250, 50));
	petals.setOutlineThickness(-25);
	petals.setOutlineColor(sf::Color(150, 10, 250));
}

void Cvijet::initStem(sf::RenderWindow* window)
{
	stem.setPosition(sf::Vector2f(375, 257));
	stem.setSize(sf::Vector2f(10, 150));
	stem.setFillColor(sf::Color(100, 200, 15));
}

void Cvijet::initLeaf(sf::RenderWindow* window)
{
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(380, 300));
	leaf.setPoint(1, sf::Vector2f(450, 260));
	leaf.setPoint(2, sf::Vector2f(600, 250));
	leaf.setPoint(3, sf::Vector2f(450, 350));
	leaf.setFillColor(sf::Color(100, 200, 15));
}

void Cvijet::initGrass(sf::RenderWindow* window)
{
	grass.setSize(sf::Vector2f(800, 200));
	grass.setPosition(sf::Vector2f(0, 400));
	grass.setFillColor(sf::Color(110, 120, 15));
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	initPetals(window);
	initStem(window);
	initLeaf(window);
	initGrass(window);
}

void Cvijet::initFlower(sf::RenderWindow* window)
{
	window->draw(petals);
	window->draw(stem);
	window->draw(leaf);
	window->draw(grass);
}

void Cvijet::updateFlower(sf::RenderWindow* window)
{
	initFlower(window);
}

void Cvijet::initAnimation(sf::RenderWindow* window)
{
	this->AverageScale = 2.f;
	this->ScaleVariance = 0.1f;
	this->OscilationFrequency = 2.f;
	this->CosFactor = 10.f / OscilationFrequency;

	sun.setRadius(30);
	sun.setPosition(sf::Vector2f(40, 20));
	sun.setFillColor(sf::Color::Yellow);
}

void Cvijet::setAnimation(sf::RenderWindow* window)
{
	initAnimation(window);
}

void Cvijet::draw(sf::RenderWindow* window)
{
	window->draw(sun);
	const float s = AverageScale + ScaleVariance * std::cos(CosFactor * timer.getElapsedTime().asSeconds());
	sun.setScale(s, s);
}





