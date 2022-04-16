#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window)
	{
		setIme(window);

	}
	void setIme(sf::RenderWindow* window)
	{
		this->ime = window;
	}


	void draw()
	{
		// zuti mali krug
		sf::CircleShape shape(20);
		shape.setFillColor(color1);
		ime->draw(shape);
		// crveni krug
		sf::CircleShape shape2(60.f);
		shape2.setFillColor(sf::Color(255, 247, 3));
		shape2.setPosition(60, 60);
		shape2.setOutlineThickness(35.f);
		shape2.setOutlineColor(sf::Color(255, 24, 3));
		ime->draw(shape2);
		// stabljika
		sf::RectangleShape line(sf::Vector2f(180, 10));
		line.setFillColor(sf::Color(41, 255, 3));
		line.setPosition(125, 215);
		line.rotate(90.f);
		ime->draw(line);
		// list
		// create an empty shape
		sf::ConvexShape convex;

		// resize it to 5 points
		convex.setPointCount(5);

		// define the points
		convex.setPointCount(4);
		convex.setPoint(0, sf::Vector2f(50, -90));
		convex.setPoint(1, sf::Vector2f(20, 100));
		convex.setPoint(2, sf::Vector2f(50, 200));
		convex.setPoint(3, sf::Vector2f(100, 100));
		convex.rotate(70.f);
		convex.setPosition(290, 190);
		convex.setFillColor(sf::Color(41, 255, 3));
		ime->draw(convex);
		// clock123(shape);
		srand(time(NULL));
		shape.setFillColor(sf::Color(rand() % 255, rand() % 242, rand() % 255));
		ime->draw(shape);
		// animacija
		/* NOTE: ukljucila sam ovdje i proslu verziju animacije gdje nije program ulazio u while loop
		void clock123(sf::CircleShape shape)
	{
		sf::Clock clock;
		sf::Time sekunda = sf::seconds(2);
		while (1 == 1)
		{
			if (clock.getElapsedTime() == sekunda)
			{

				if (shape.getFillColor() == color1)
				{
					shape.setFillColor(color2);
				}
				else
				{
					shape.setFillColor(color1);
				}
				ime->draw(shape);
				clock.restart();
			}*/

	}


private:
	sf::RenderWindow* ime;
	sf::Color color1 = sf::Color(255, 247, 3);
	sf::Color color2 = sf::Color(255, 51, 0);

};

// sf::CircleShape shape(50.f);

// set the shape color to green
// shape.setFillColor(sf::Color(100, 250, 50));

