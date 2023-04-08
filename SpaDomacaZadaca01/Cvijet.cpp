#include "Cvijet.h"
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->clock = clock;
}

void Cvijet::draw(float origin_x, float origin_y)
{
	// Animation
	int time = clock.getElapsedTime().asMilliseconds();
	float intensity = 3;
	float speed = 0.001;
	
	// Offset of the base
	float base_x = origin_x;
	float base_y = origin_y-50;

	// Petals -- declaration
	int petal_no = 10;
	float petal_angle_1 = -60;
	float petal_angle_add = 12;
	float petal_red = 28;
	float petal_red_add = 22;
	float petal_green = 106;
	float petal_green_add = 13;
	float petal_blue = 202;
	float petal_blue_add = 3;

	// Stem
	sf::RectangleShape stem(sf::Vector2f(150.f, 5.f));
	stem.setPosition(base_x, base_y);
	stem.rotate(93.f+ std::sin(time * speed) * intensity/4);
	stem.setFillColor(sf::Color(0, 179, 89));
	window->draw(stem);

	// Leaf
	float leafRotation = 69.f + std::sin(time * speed * 4) * intensity / 4;
	sf::ConvexShape leaf;
	leaf.setPointCount(8);
	leaf.setPoint(0, sf::Vector2f(0.f, 0.f));
	leaf.setPoint(1, sf::Vector2f(-10.f, -20.f));
	leaf.setPoint(2, sf::Vector2f(-12.f, -50.f));
	leaf.setPoint(3, sf::Vector2f(-6.f, -70.f));
	leaf.setPoint(4, sf::Vector2f(0.f, -80.f));
	leaf.setPoint(5, sf::Vector2f(6.f, -70.f));
	leaf.setPoint(6, sf::Vector2f(12.f, -50.f));
	leaf.setPoint(7, sf::Vector2f(10.f, -20.f));
	leaf.rotate(leafRotation);
	leaf.setFillColor(sf::Color(0, 179, 89));
	leaf.setPosition(base_x - 8, base_y + 96);
	window->draw(leaf);
	// Second leaf
	leaf.rotate(leafRotation+163.f);
	leaf.scale(0.7, 0.75);
	window->draw(leaf);

	// Petals
	sf::ConvexShape petal;
	petal.setPointCount(5);
	petal.setPoint(0, sf::Vector2f(0.f, 0.f));
	petal.setPoint(1, sf::Vector2f(-10.f, -20.f));
	petal.setPoint(2, sf::Vector2f(-12.f, -50.f));
	petal.setPoint(3, sf::Vector2f(-6.f, -70.f));
	petal.setPoint(4, sf::Vector2f(0.f, -80.f));
	petal.setPosition(base_x, base_y);

	// Petals -- angle and colour loop
	petal.rotate(petal_angle_1 + std::sin(time*speed) * intensity);
	for (int i = 0; i < petal_no; i++)
	{
		int timeShift = std::sin(time * speed * 2) * intensity * 5;
		petal.rotate(petal_angle_add);
		petal.setFillColor(sf::Color(
			petal_red + i * petal_red_add + timeShift,
			petal_green + i * petal_green_add + timeShift,
			petal_blue + i * petal_blue_add + timeShift
		));
		window->draw(petal);
	}

	// Origin point -- only used for alignment
	/*float circle_r = 5;
	sf::CircleShape circle(circle_r);
	circle.setPosition(base_x - circle_r, base_y - circle_r);
	circle.setFillColor(sf::Color(100, 250, 50));
	window->draw(circle);*/
}
