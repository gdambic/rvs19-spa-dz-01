#include "Cvijet.h"
#include <SFML/Graphics.hpp>


Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape circleOuter(80, 8);
	circleOuter.setPosition(300, 200);
	circleOuter.setFillColor(sf::Color::Magenta);
	window->draw(circleOuter);

	sf::CircleShape circleInner(40);
	circleInner.setPosition(340, 240);
	window->draw(circleInner);

	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.setFillColor(sf::Color::Green);
	line.rotate(80.f);
	line.setPosition(400, 352);
	window->draw(line);

	sf::RectangleShape grass(sf::Vector2f(120.f, 50.f));
	grass.setSize(sf::Vector2f(800.f, 150.f));
	grass.setPosition(0, 495);
	grass.setFillColor(sf::Color(57, 155, 7));
	window->draw(grass);

	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(20, 50));
	leaf.setPoint(1, sf::Vector2f(120, -50));
	leaf.setPoint(2, sf::Vector2f(110, -30));
	leaf.setPoint(3, sf::Vector2f(90, 20));
	leaf.setFillColor(sf::Color::Green);
	leaf.rotate(180);
	leaf.setPosition(530, 380);
	window->draw(leaf);


	sf::CircleShape sun(50);
	sun.setFillColor(sf::Color::Yellow);
	window->draw(sun);










}

