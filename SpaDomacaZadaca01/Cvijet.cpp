#include "Cvijet.h"
#include <vector>
#include<string>
using namespace std;

Cvijet::Cvijet(sf::RenderWindow* konzola)
{
	this->konzola = konzola;
}

void Cvijet::draw()
{
	//stabljika
	sf::RectangleShape line(sf::Vector2f(150, 7));
	line.setPosition(sf::Vector2f(405, 270));
	line.rotate(90);
	line.setFillColor(sf::Color(100, 250, 50));
	//list
	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(50, 30));
	convex.setPoint(1, sf::Vector2f(100, 30));
	convex.setPoint(2, sf::Vector2f(50, 60));
	convex.setPoint(3, sf::Vector2f(0, 70));
	convex.setPosition(sf::Vector2f(407, 270));
	convex.setFillColor(sf::Color(100, 250, 50));
	//S0nce
	sf::CircleShape shape1(50.f);
	shape1.setFillColor(sf::Color::Yellow);
	shape1.setPosition(sf::Vector2f(200, -10));
	//"Trava"
	sf::RectangleShape line1(sf::Vector2f(800, 50));
	line1.setPosition(sf::Vector2f(800, 425));
	line1.rotate(180);
	line1.setFillColor(sf::Color(100, 250, 50));
	konzola->draw(convex);
	konzola->draw(shape1);
	konzola->draw(line);
	konzola->draw(line1);
	//"cvijet"

	sf::CircleShape cvetak(50);
	cvetak.setFillColor(sf::Color::Yellow);
	cvetak.setOutlineThickness(30);
	cvetak.setOutlineColor(sf::Color::Red);
	cvetak.setPosition(350, 155);
	konzola->draw(cvetak);

	
}
