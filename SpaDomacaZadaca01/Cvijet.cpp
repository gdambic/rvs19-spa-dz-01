#include "Cvijet.h"

#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape main_circle(30);
	main_circle.setFillColor(sf::Color::Yellow);
	main_circle.setPosition(sf::Vector2f(385, 300));

	sf::CircleShape sun_circle(30);
	sun_circle.setFillColor(sf::Color::Yellow);
	sun_circle.setPosition(sf::Vector2f(0, 0));

	sf::CircleShape circle_up(30);
	circle_up.setFillColor(sf::Color::Red);
	circle_up.setPosition(sf::Vector2f(385, 330));

	sf::CircleShape circle_left(30);
	circle_left.setFillColor(sf::Color::Red);
	circle_left.setPosition(sf::Vector2f(360, 300));

	sf::CircleShape circle_right(30);
	circle_right.setFillColor(sf::Color::Red);
	circle_right.setPosition(sf::Vector2f(410, 300));

	sf::CircleShape circle_down(30);
	circle_down.setFillColor(sf::Color::Red);
	circle_down.setPosition(sf::Vector2f(385, 270));


	sf::RectangleShape rectangle_base(sf::Vector2f(5, 300));
	rectangle_base.setPosition(sf::Vector2f(412, 300));
	rectangle_base.setFillColor(sf::Color::Green);

	sf::RectangleShape rectangle_grass(sf::Vector2f(800, 100));
	rectangle_grass.setPosition(sf::Vector2f(0, 500));
	rectangle_grass.setFillColor(sf::Color::Green);

	sf::RectangleShape rectangle_sky(sf::Vector2f(800, 500));
	rectangle_sky.setPosition(sf::Vector2f(0, 0));
	rectangle_sky.setFillColor(sf::Color::Cyan);


	window->draw(rectangle_grass);
	window->draw(rectangle_sky);
	window->draw(rectangle_base);
	window->draw(sun_circle);
	window->draw(circle_left);
	window->draw(circle_right);
	window->draw(circle_down);
	window->draw(circle_up);
	window->draw(main_circle);

}
