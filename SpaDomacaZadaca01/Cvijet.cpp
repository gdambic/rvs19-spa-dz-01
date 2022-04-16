#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	// clock is started
	sf::Clock clock = this->clock;
}

void Cvijet::draw()
{
	scene_animation();
	draw_flower(545.f, 365.f);
	draw_flower(405.f, 380.f);	
	draw_flower(220.f, 360.f);
}

void Cvijet::draw_flower(float x, float y)
{
	// the root position "rt"
	sf::Vector2f rt(x, y);	
	// peduncle
	sf::RectangleShape peduncle(sf::Vector2f(200.f, 10.f));
	peduncle.setFillColor(sf::Color(123, 130, 53));
	peduncle.setOutlineThickness(2.f);
	peduncle.setOutlineColor(sf::Color(27, 27, 27));
	peduncle.setPosition(rt.x, rt.y);
	peduncle.rotate(90.f);
	// blossom
	sf::CircleShape petal(90.f, 10);
	petal.setFillColor(sf::Color(251, 169, 20));
	petal.setOutlineThickness(2.f);
	petal.setOutlineColor(sf::Color(27, 27, 27));
	petal.setPosition(rt.x - 95.f, rt.y - 170.f); //position relative to the root
	sf::CircleShape stamen(40.f);
	stamen.setFillColor(sf::Color(50, 36, 19));
	stamen.setOutlineThickness(10.f);
	stamen.setOutlineColor(sf::Color(223, 109, 38));
	stamen.setPosition(rt.x - 45.f, rt.y - 120.f); //position relative to the root
	// drawing all flower parts
	window->draw(peduncle);
	window->draw(petal);
	window->draw(stamen);
}

void Cvijet::draw_environment()
{
	sf::ConvexShape environment;
	environment.setPointCount(8);
	environment.setPoint(0, sf::Vector2f(0.f, 570.f));
	environment.setPoint(1, sf::Vector2f(50.f, 520.f));
	environment.setPoint(2, sf::Vector2f(250.f, 480.f));
	environment.setPoint(3, sf::Vector2f(450.f, 500.f));
	environment.setPoint(4, sf::Vector2f(650.f, 450.f));
	environment.setPoint(5, sf::Vector2f(800.f, 560.f));
	environment.setPoint(6, sf::Vector2f(800.f, 600.f));
	environment.setPoint(7, sf::Vector2f(0.f, 600.f));
	environment.setFillColor(sf::Color(137, 193, 89));
	environment.setOutlineThickness(2.f);
	environment.setOutlineColor(sf::Color(220, 220, 182));
	window->draw(environment);
}

void Cvijet::scene_animation()
{
	// time tracking in console
	sf::Time elapsed = clock.getElapsedTime();
	float sec = elapsed.asSeconds();
	std::cout << sec << std::endl;

	// create background color
	sf::ConvexShape back;
	back.setPointCount(8);
	back.setPoint(0, sf::Vector2f(0.f, 0.f));
	back.setPoint(1, sf::Vector2f(800.f, 0.f));
	back.setPoint(2, sf::Vector2f(800.f, 600.f));
	back.setPoint(3, sf::Vector2f(0.f, 600.f));

	//create the Sun
	sf::CircleShape sun(90.f);

	if (sec >= 24.f)
	{
		clock.restart();
	}
	else
	{
		// update background color
		back.setFillColor(sf::Color(58, 59, 139));
		int red_b = 18 + (8 * sec);
		int green_b = 19 + (8 * sec);
		int blue_b = 39 + (8 * sec);
		back.setFillColor(sf::Color(red_b, green_b, blue_b));
		// drawing the background
		window->draw(back);

		// update Sun color
		int red_s = 226 + sec;
		int green_s = 101 + (6 * sec);
		sun.setFillColor(sf::Color(red_s, green_s, 60));
		// update Sun position
		int speed = 12;
		float move_x = 450.f - (12.f + (sec * speed));
		float move_y = 480.f - (sec * speed * 2);
		sun.setPosition(move_x, move_y);
		// update Sun size
		float size = 90.f - (sec * 2);
		sun.setRadius(size);
		// drawing the Sun
		window->draw(sun);
	}

	draw_environment();
}
