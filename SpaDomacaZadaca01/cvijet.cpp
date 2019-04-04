#include "cvijet.h"
#include <SFML/Graphics.hpp>


Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition(300, 300);

	shape.setOutlineThickness(15.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));

	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.setFillColor(sf::Color(102, 51, 0));
	line.rotate(90.f);
	line.setPosition(350, 415);

	sf::CircleShape circle(30.f);
	circle.setFillColor(sf::Color(204, 0, 102));
	circle.setRadius(40.f);
	circle.setPointCount(100);
	circle.setPosition(375, 375);

	sf::CircleShape circle_1(30.f);
	circle_1.setFillColor(sf::Color(204, 0, 102));
	circle_1.setRadius(40.f);
	circle_1.setPointCount(100);
	circle_1.setPosition(375, 245);

	sf::CircleShape circle_2(30.f);
	circle_2.setFillColor(sf::Color(204, 0, 102));
	circle_2.setRadius(40.f);
	circle_2.setPointCount(100);
	circle_2.setPosition(245, 375);

	sf::CircleShape circle_3(30.f);
	circle_3.setFillColor(sf::Color(204, 0, 102));
	circle_3.setRadius(40.f);
	circle_3.setPointCount(100);
	circle_3.setPosition(245, 245);

	sf::CircleShape shape_two(100.f);
	shape_two.setFillColor(sf::Color::Transparent);
	shape_two.setPosition(250, 250);

	shape_two.setOutlineThickness(50.f);
	shape_two.setOutlineColor(sf::Color(0, 128, 255));


	window->draw(shape); //zasto kada pisem window.draw(shape) prebacuje na strelicu umjesto tocke
	window->draw(shape_one);
	window->draw(shape_two);
	window->draw(line);
	window->draw(circle);
	window->draw(circle_1);
	window->draw(circle_2);
	window->draw(circle_3);
	window->draw(circle_4);

}

