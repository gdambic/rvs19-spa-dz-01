#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw_background()
{
	//Sky
	window->clear(sf::Color::Cyan);

	//Ground
	sf::RectangleShape rectangle(sf::Vector2f(800.f, 100.f));
	rectangle.setPosition(0, 500);
	rectangle.setFillColor(sf::Color(200, 160, 0));
	window->draw(rectangle);
}

void Cvijet::draw_flower()
{
	//Line
	sf::RectangleShape line(sf::Vector2f(230.f, 10.f));
	line.setPosition(380, 300);
	line.rotate(90.f);
	line.setFillColor(sf::Color::Green);
	window->draw(line);

	//Leaf
	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(380.f, 400));
	leaf.setPoint(1, sf::Vector2f(420.f, 380));
	leaf.setPoint(2, sf::Vector2f(470.f, 400));
	leaf.setPoint(3, sf::Vector2f(420.f, 420));
	leaf.setFillColor(sf::Color(6, 120, 0));
	window->draw(leaf);

	//Flower
	sf::CircleShape flower(10.f);
	flower.setPosition(365, 280);
	flower.setFillColor(sf::Color::Yellow);
	window->draw(flower);

	sf::CircleShape circle1(15.f);
	circle1.setPosition(345, 295);
	circle1.setFillColor(sf::Color::Red);
	window->draw(circle1);

	sf::CircleShape circle2(15.f);
	circle2.setPosition(336, 267);
	circle2.setFillColor(sf::Color::Red);
	window->draw(circle2);

	sf::CircleShape circle3(15.f);
	circle3.setPosition(360, 250);
	circle3.setFillColor(sf::Color::Red);
	window->draw(circle3);

	sf::CircleShape circle4(15.f);
	circle4.setPosition(384, 267);
	circle4.setFillColor(sf::Color::Red);
	window->draw(circle4);

	sf::CircleShape circle5(15.f);
	circle5.setPosition(375, 295);
	circle5.setFillColor(sf::Color::Red);
	window->draw(circle5);
}

void Cvijet::draw_clouds()
{
	sf::RectangleShape cloud1(sf::Vector2f(120.f, 50.f));
	cloud1.setPosition(150, 10);
	cloud1.setFillColor(sf::Color::White);
	window->draw(cloud1);

	sf::RectangleShape cloud2(sf::Vector2f(80.f, 20.f));
	cloud2.setPosition(255, 65);
	cloud2.setFillColor(sf::Color::White);
	window->draw(cloud2);

	sf::RectangleShape cloud3(sf::Vector2f(145.f, 80.f));
	cloud3.setPosition(355, 15);
	cloud2.setFillColor(sf::Color::White);
	window->draw(cloud3);

	sf::RectangleShape cloud4(sf::Vector2f(100.f, 35.f));
	cloud4.setPosition(515, 10);
	cloud4.setFillColor(sf::Color::White);
	window->draw(cloud4);

	sf::RectangleShape cloud5(sf::Vector2f(110.f, 45.f));
	cloud5.setPosition(625, 30);
	cloud5.setFillColor(sf::Color::White);
	window->draw(cloud5);
}

void Cvijet::draw_sun()
{
	sf::CircleShape sun(25.f);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(10, 10);

	//Animation
	sf::Time frame = frameClock.getElapsedTime();
	if (frame.asSeconds() > 1.f)
	{
		sun.setRadius(sun.getRadius() + 15);
	}
	if (frame.asSeconds() > 2.f)
	{
		sun.setRadius(sun.getRadius() + 15);
	}
	if (frame.asSeconds() > 3.f)
	{
		sun.setRadius(sun.getRadius() - 15);
	}
	if (frame.asSeconds() > 4.f)
	{
		frameClock.restart();
	}
	window->draw(sun);
}

void Cvijet::draw()
{
	draw_background();
	draw_flower();
	draw_clouds();
	draw_sun();
}