#include"Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {}

void Cvijet::draw(sf::RenderWindow* window, Cvijet* cvijet)
{
	sf::CircleShape circle1(10.f);
	circle1.setFillColor(sf::Color(255, 255, 0));

	sf::CircleShape circle2(cvijet->c2_r);
	circle2.setPosition(30.f, 30.f);
	circle2.setFillColor(sf::Color(255, 255, 0));
	circle2.setOutlineThickness(30.f);
	circle2.setOutlineColor(sf::Color(255, 0, 0));

	sf::RectangleShape line(sf::Vector2f(120.f, 10.f));
	line.setFillColor(sf::Color(0, 255, 0));
	line.setPosition(80.f, 130.f);
	line.rotate(90.f);

	sf::ConvexShape convex;
	convex.setFillColor(sf::Color(0, 255, 0));
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(80.f, 200.f));
	convex.setPoint(1, sf::Vector2f(130.f, 170.f));
	convex.setPoint(2, sf::Vector2f(210.f, 160.f));
	convex.setPoint(3, sf::Vector2f(130.f, 205.f));

	window->draw(circle1);
	window->draw(line);
	window->draw(circle2);
	window->draw(convex);

}

void Cvijet::update(Cvijet* cvijet, float* dt)
{
	cvijet->c2_r = (50 - 40) * sin(*dt) + 40;
}