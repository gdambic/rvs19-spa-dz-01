#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	for (int i = 0; i < 3; i++)
	{
		convex.setPointCount(6);
		convex.setPoint(1, sf::Vector2f(150.f, 350.f - 50 * i));
		convex.setPoint(2, sf::Vector2f(175.f, 425.f - 50 * i));
		convex.setPoint(3, sf::Vector2f(325.f, 425.f - 50 * i));
		convex.setPoint(4, sf::Vector2f(350.f, 350.f - 50 * i));
		convex.setPoint(5, sf::Vector2f(325.f, 375.f - 50 * i));
		convex.setPoint(0, sf::Vector2f(175.f, 375.f - 50 * i));
		convex.setFillColor(sf::Color(255, 0, 0));
		window->draw(convex);
	}

	rectangle.setSize(sf::Vector2f(50.f, 175.f));
	rectangle.setPosition(sf::Vector2f(225.f, 425.f));
	rectangle.setFillColor(sf::Color(100, 250, 50));
	window->draw(rectangle);

	circle.setPosition(sf::Vector2f(175.f, 200.f));
	circle.setFillColor(sf::Color(255, 0, 0));
	circle.setRadius(75);
	window->draw(circle);

	sf::Clock frame_clock;
	float duration = 0;
	float i = 0.f;

	while (true) {
		sf::Time dt = frame_clock.restart();
		duration += dt.asMicroseconds();

		if (duration > 100.0f)
		{
			circle.setPosition(sf::Vector2f(175.f, 150.f - i));

			window->clear();
			window->draw(rectangle);
			window->draw(circle);
			for (int i = 0; i < 3; i++)
			{
				convex.setPointCount(6);
				convex.setPoint(1, sf::Vector2f(150.f, 350.f - 50 * i));
				convex.setPoint(2, sf::Vector2f(175.f, 425.f - 50 * i));
				convex.setPoint(3, sf::Vector2f(325.f, 425.f - 50 * i));
				convex.setPoint(4, sf::Vector2f(350.f, 350.f - 50 * i));
				convex.setPoint(5, sf::Vector2f(325.f, 375.f - 50 * i));
				convex.setPoint(0, sf::Vector2f(175.f, 375.f - 50 * i));
				convex.setFillColor(sf::Color(255, 0, 0));
				window->draw(convex);
			}
			window->display();
		}
		if (i == 50.f)
		{
			i = 0.f;
		}
		else
		{
			i += 25.f;
		}
	}
}