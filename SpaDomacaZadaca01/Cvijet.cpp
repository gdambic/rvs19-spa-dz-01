#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow *window) : window(window){
}

void Cvijet::flower() {

	sf::CircleShape cvijet(20.f);
	cvijet.setFillColor(sf::Color(255, 255, 0));
	cvijet.setOutlineThickness(40.f);
	cvijet.setOutlineColor(sf::Color(139, 0, 139));
	cvijet.setPosition(380.f, 75.f);
	window->draw(cvijet);

	sf::RectangleShape stabljika(sf::Vector2f(200.f, 10.f));
	stabljika.rotate(90.f);
	stabljika.setPosition(405.f, 155.f);
	stabljika.setFillColor(sf::Color(50, 205, 50));
	window->draw(stabljika);

	sf::ConvexShape dlist;
	dlist.setPointCount(5);
	dlist.setFillColor(sf::Color(50, 205, 50));
	dlist.setPoint(0, sf::Vector2f(405.f, 225.f));
	dlist.setPoint(1, sf::Vector2f(465.f, 185.f));
	dlist.setPoint(2, sf::Vector2f(545.f, 200.f));
	dlist.setPoint(3, sf::Vector2f(465.f, 235.f));
	dlist.setPoint(4, sf::Vector2f(405.f, 225.f));
	window->draw(dlist);
}

void Cvijet::draw() {
	sf::CircleShape circle(15.f);
	sf::CircleShape circle1(15.f);

	circle.setPosition(25.f, 25.f);
	circle1.setPosition(725.f, 25.f);
	sf::Color boja = sf::Color::Red;

	if (duration > 0.01f) {
		red -= 1;
		blue += 1;
		boja = sf::Color(red, 0, blue);
		circle.setFillColor(boja);
		circle1.setFillColor(boja);

		if (x >= 0.f && y >= 0.f)
		{
			x += 0.01f;
			y += 0.01f;
			circle.scale(x, y);
			circle1.scale(x, y);
		}
		
		if (x >= 1.5f && y >= 1.5f) {
			x -= 1.5f;
			y -= 1.5f;
			circle.scale(x, y);
			circle1.scale(x, y);
		}
	}
	
	
	window->draw(circle);
	window->draw(circle1);
}
