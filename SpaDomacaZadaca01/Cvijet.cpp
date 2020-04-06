#include "Cvijet.h"
#include<chrono>
#include"SFML/Graphics.hpp"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw() const
{
	sf::Time elapsed1 = sat.getElapsedTime();

	sf::RectangleShape background(sf::Vector2f(1000.f, 500.f));
	background.setFillColor(sf::Color::Cyan);
	window->draw(background);

	sf::CircleShape rainbowRed(400.f);
	rainbowRed.setFillColor(sf::Color(250, 50, 0));
	rainbowRed.setPosition(170.f, 0.f);
	window->draw(rainbowRed);

	sf::CircleShape rainbowOrange(400.f);
	rainbowOrange.setFillColor(sf::Color(250, 180, 0));
	rainbowOrange.setPosition(170.f, 40.f);
	window->draw(rainbowOrange);

	sf::CircleShape rainbowYellow(400.f);
	rainbowYellow.setFillColor(sf::Color(250, 220, 0));
	rainbowYellow.setPosition(170.f, 80.f);
	window->draw(rainbowYellow);

	sf::CircleShape rainbowGreen(400.f);
	rainbowGreen.setFillColor(sf::Color(0, 200, 0));
	rainbowGreen.setPosition(170.f, 120.f);
	window->draw(rainbowGreen);

	sf::CircleShape rainbowBabyBlue(400.f);
	rainbowBabyBlue.setFillColor(sf::Color::Blue);
	rainbowBabyBlue.setPosition(170.f, 160.f);
	window->draw(rainbowBabyBlue);

	sf::CircleShape rainbowDarkBlue(400.f);
	rainbowDarkBlue.setFillColor(sf::Color(0, 0, 150));
	rainbowDarkBlue.setPosition(170.f, 200.f);
	window->draw(rainbowDarkBlue);

	sf::CircleShape rainbowPurple(400.f);
	rainbowPurple.setFillColor(sf::Color(100, 0, 100));
	rainbowPurple.setPosition(170.f, 240.f);
	window->draw(rainbowPurple);

	sf::CircleShape rainbowEnd(400.f);
	rainbowEnd.setFillColor(sf::Color::Cyan);
	rainbowEnd.setPosition(170.f, 280.f);
	window->draw(rainbowEnd);

	sf::CircleShape pestle(10.f);
	pestle.setFillColor(sf::Color::Yellow);
	pestle.setOutlineColor(sf::Color::Magenta);
	pestle.setOutlineThickness(50.f);
	pestle.setPosition(500.f, 250.f);
	window->draw(pestle);

	sf::RectangleShape grass(sf::Vector2f(800.f, 5.f));
	grass.setFillColor(sf::Color::Green);
	grass.setPosition(50.f, 550.f);
	grass.setOutlineColor(sf::Color::Green);
	grass.setOutlineThickness(50.f);
	grass.rotate(0.f);
	window->draw(grass);

	sf::RectangleShape stamp(sf::Vector2f(180.f, 5.f));
	stamp.setFillColor(sf::Color(0, 100, 0));
	stamp.rotate(90.f);
	stamp.setPosition(510.f, 320.f);
	window->draw(stamp);

	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(50.f, 50.f));
	leaf.setPoint(1, sf::Vector2f(100.f, 25.f));
	leaf.setPoint(2, sf::Vector2f(210.f, 50.f));
	leaf.setPoint(3, sf::Vector2f(100.f, 75.f));
	leaf.setFillColor(sf::Color(0, 120, 0));
	leaf.setPosition(sf::Vector2f(438.f, 360.f));
	leaf.rotate(-25.f);
	window->draw(leaf);

	sf::ConvexShape leaf2;
	leaf2.setPointCount(4);
	leaf2.setPoint(0, sf::Vector2f(50.f, 42.f));
	leaf2.setPoint(1, sf::Vector2f(100.f, 25.f));
	leaf2.setPoint(2, sf::Vector2f(188.f, 50.f));
	leaf2.setPoint(3, sf::Vector2f(100.f, 65.f));
	leaf2.setFillColor(sf::Color(0, 70, 20));
	leaf2.setPosition(sf::Vector2f(545.f, 460.f));
	leaf2.rotate(198.f);
	window->draw(leaf2);

	sf::CircleShape octagon(70.f, 9);
	octagon.setFillColor(sf::Color::Yellow);
	octagon.setOutlineThickness(20.f);
	octagon.setOutlineColor(sf::Color(250, 128, 0));
	octagon.setPosition(110, 100);
	octagon.setOrigin(50, 70);
	octagon.setRotation(elapsed1.asMilliseconds() / 60);
	window->draw(octagon);
}