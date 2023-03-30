#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.setFillColor(sf::Color::Yellow);
	line.move(55.f, 80.f);
	line.rotate(90.f);
	window->draw(line);

	sf::ConvexShape list;
	list.setPointCount(3);
	list.setPoint(0, sf::Vector2f(55.f, 180.f));
	list.setPoint(1, sf::Vector2f(150.f, 100.f));
	list.setPoint(2, sf::Vector2f(55.f, 200.f));
	list.setFillColor(sf::Color::Red);
	window->draw(list);
		
	sf::CircleShape krug(50.f);
	krug.setFillColor(sf::Color::Yellow);
	krug.setOutlineThickness(-10.f);
	krug.setOutlineColor(sf::Color::Green);
	window->draw(krug);
}

void Cvijet::animacija()
{
	sf::Clock clock;
	sf::Time elapsed1 = clock.getElapsedTime();
	cout << elapsed1;
	sf::CircleShape trokut(50.f, 3);
	trokut.move(150.f, 85.f);
	window->draw(trokut);
}
