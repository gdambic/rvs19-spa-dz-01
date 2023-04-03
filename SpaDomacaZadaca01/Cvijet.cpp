#include "Cvijet.h"
#include <SFML/Graphics.hpp>


void Cvijet::NacrtajTucak()
{
	sf::CircleShape tucak(50.f);

	sf::Vector2f position;
	position.x = 350;
	position.y= 250;

	tucak.setFillColor(sf::Color(243, 99, 215));
	tucak.setPosition(position);

	tucak.setOutlineThickness(20);



	window->draw(tucak);
}

void Cvijet::NacrtajStabljika()
{
	sf::RectangleShape stabljika(sf::Vector2f(30.f,120.f));
	sf::Vector2f position;
	position.x = 385;
	position.y = 370;


	stabljika.setFillColor(sf::Color(99, 243, 126));
	stabljika.setPosition(position);
	window->draw(stabljika);

}

void Cvijet::NacrtajLatica()
{
	sf::ConvexShape list;

	// resize it to 4 points
	list.setPointCount(4);

	list.setFillColor(sf::Color(99, 243, 126));

	// define the points
	list.setPoint(0, sf::Vector2f(415.f, 440.f));
	list.setPoint(1, sf::Vector2f(465.f, 445.f));
	list.setPoint(2, sf::Vector2f(510.f, 400.f));
	list.setPoint(3, sf::Vector2f(448.f, 400.f));
	window->draw(list);
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	NacrtajTucak();
	NacrtajStabljika();
	NacrtajLatica();
}
