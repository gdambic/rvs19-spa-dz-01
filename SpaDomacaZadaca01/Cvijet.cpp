#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

using namespace std;


Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
}
void Cvijet::draw()
{
	sf::CircleShape shape1(50.f);
	shape1.setFillColor(sf::Color(0, 0, 0));
	shape1.setPosition(350.f, 200.f);
	shape1.setOutlineThickness(50.f);
	shape1.setOutlineColor(sf::Color(43, 29, 20));

	sf::RectangleShape rectangle3(sf::Vector2f(800.f, 600.f));
	rectangle3.setFillColor(sf::Color(0, 220, 0));
	rectangle3.setPosition(0.f, 0.f);
	rectangle3.rotate(0.f);
	window->draw(rectangle3);

	sf::RectangleShape rectangle2(sf::Vector2f(800.f, 400.f));
	rectangle2.setFillColor(sf::Color(135, 206, 235));
	rectangle2.setPosition(0.f, 0.f);
	rectangle2.rotate(0.f);
	window->draw(rectangle2);


	sf::RectangleShape rectangle1(sf::Vector2f(250.f, 40.f));
	rectangle1.setFillColor(sf::Color(0, 200, 0));
	rectangle1.setPosition(420.f, 250.f);
	rectangle1.setOutlineThickness(2.f);
	rectangle1.setOutlineColor(sf::Color(0, 100, 0));
	rectangle1.rotate(90.f);
	window->draw(rectangle1);


	array<sf::ConvexShape,16> convex1;
	for (int i = 0; i < 16; i++)
	{
		convex1[i].setPointCount(4);
		convex1[i].setFillColor(sf::Color(255, 213, 128));
		convex1[i].setPoint(0, sf::Vector2f(400.f, 250.f));
		convex1[i].setPoint(1, sf::Vector2f((500-400)*cos(PI/8*i)-(225-250)*sin(PI/8*i)+400.f, (500 - 400) * sin(PI / 8 * i) + (225 - 250) * cos(PI / 8 * i) + 250.f));
		convex1[i].setPoint(2, sf::Vector2f((600-400)*cos(PI/8*i)+400.f, (600 - 400) * sin(PI / 8 * i) + 250.f));
		convex1[i].setPoint(3, sf::Vector2f((500 - 400) * cos(PI / 8 * i) - (275 - 250) * sin(PI / 8 * i) + 400.f, (500 - 400) * sin(PI / 8 * i) + (275 - 250) * cos(PI / 8 * i) + 250.f));
		convex1[i].setOutlineThickness(5.f);
		convex1[i].setOutlineColor(sf::Color(255, 255, 0));
		window->draw(convex1[i]);
	}
	
	window->draw(shape1);

	array<sf::ConvexShape, 16> convex2;

	sf::Time elapsed = clock.getElapsedTime();
	
	for (int i = 0; i < 16; i++)
	{
		convex2[i].setPointCount(4);
		convex2[i].setFillColor(sf::Color(255, 213, 128));
		convex2[i].setPoint(0, sf::Vector2f(50.f, 50.f));
		convex2[i].setPoint(1, sf::Vector2f((60 - 50) * cos(PI / 8 * i) - (40 - 50) * sin(PI / 8 * i) + 50.f, (60 - 50) * sin(PI / 8 * i) + (40 - 50) * cos(PI / 8 * i) + 50.f));
		convex2[i].setPoint(2, sf::Vector2f((70 - 50) * cos(PI / 8 * i) + 50.f, (70 - 50) * sin(PI / 8 * i) + 50.f));
		convex2[i].setPoint(3, sf::Vector2f((60 - 50) * cos(PI / 8 * i) - (60 - 50) * sin(PI / 8 * i) + 50.f, (60 - 50) * sin(PI / 8 * i) + (60 - 50) * cos(PI / 8 * i) + 50.f));
		convex2[i].setOutlineThickness(5*sin(PI/4*clock.getElapsedTime().asSeconds())+10.f);
		convex2[i].setOutlineColor(sf::Color(255, 213, 128));
		window->draw(convex2[i]);
	}


}