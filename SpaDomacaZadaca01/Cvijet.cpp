#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;

	//0trava
	flower_piece0.setPosition(0.f, 570.f);
	flower_piece0.setSize(sf::Vector2f(800.f, 35.f));
	flower_piece0.setFillColor(sf::Color(90, 215, 60));
	flower_piece0.setOutlineThickness(5.f);
	flower_piece0.setOutlineColor(sf::Color(80, 185, 60));

	//1korijen
	flower_piece1.setPosition(400.f, 380.f);
	flower_piece1.setSize(sf::Vector2f(25.f, 200.f));
	flower_piece1.setFillColor(sf::Color(100, 250, 50));
	flower_piece1.setOutlineThickness(10.f);
	flower_piece1.setOutlineColor(sf::Color(100, 225, 60));

	//2list
	flower_piece2.setPointCount(3);
	flower_piece2.setPoint(0, { 0.f, 0.f });
	flower_piece2.setPoint(1, { 130.f, 10.f });
	flower_piece2.setPoint(2, { 120.f, 90.f });
	flower_piece2.setPosition(400.f, 410.f);
	flower_piece2.setFillColor(sf::Color(80, 195, 52));

	//3latice
	flower_piece3.setPosition(312.f, 180.f);
	flower_piece3.setPointCount(10);
	flower_piece3.setRadius(100.f);
	flower_piece3.setFillColor(sf::Color(217, 33, 33));
	flower_piece3.setOutlineThickness(20.f);
	flower_piece3.setOutlineColor(sf::Color(200, 23, 23));

	//4tucka
	flower_piece4.setPosition(410.f, 280.f);
	flower_piece4.setPointCount(12);
	flower_piece4.setRadius(50.f);
	flower_piece4.setFillColor(sf::Color(233, 233, 103));
	flower_piece4.setOutlineThickness(11.f);
	flower_piece4.setOutlineColor(sf::Color(243, 243, 83));
	flower_piece4.setOrigin(50.f, 50.f); //!

	//5sunce
	flower_piece5.setPosition(35.f, 35.f);
	flower_piece5.setRadius(50.f);
	flower_piece5.setPointCount(9);
	flower_piece5.setFillColor(sf::Color(253, 253, 103));
	flower_piece5.setOutlineThickness(15.f);
	flower_piece5.setOutlineColor(sf::Color(243, 243, 83));
	flower_piece5.setOrigin(50.f, 50.f); //!
}

void Cvijet::update_flower()
{
	float t = clock.getElapsedTime().asSeconds();
	flower_piece5.setRotation(t * 50.f);

	//float novi_radijus = prvi_radijus + (sin(vrijeme * brzina) * amplituda);
	float animacija = 40.f + sin(t * 3.f) * 4.f;
	flower_piece4.setRadius(animacija);
	flower_piece4.setOrigin(animacija, animacija);
}

void Cvijet::create_flower()
{
	window->draw(flower_piece0);
	window->draw(flower_piece1);
	window->draw(flower_piece2);
	window->draw(flower_piece3);
	window->draw(flower_piece4);
	window->draw(flower_piece5);
}

void Cvijet::draw_flower()
{
	update_flower();
	create_flower();
}