#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;

	//petiljka
	sf::RectangleShape branch(sf::Vector2f(10.f, 300.f));
	branch.setFillColor(sf::Color::Green);
	branch.setPosition(sf::Vector2f(240, 300));

	this->branch = branch;

	//pupoljak
	sf::ConvexShape convex;
	convex.setFillColor(sf::Color::White);
	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(240, 290));
	convex.setPoint(1, sf::Vector2f(320, 380));
	convex.setPoint(2, sf::Vector2f(260, 400));

	this->convex = convex;

	//krug na petiljci
	sf::CircleShape circle(10.f);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(sf::Vector2f(235, 290));

	this->circle = circle;

	//krug u pupoljku
	sf::CircleShape circle2(10.f);
	circle2.setFillColor(sf::Color::Yellow);
	circle2.setPosition(sf::Vector2f(280, 380));

	this->circle2 = circle2;

	//listic
	sf::ConvexShape leaf;
	leaf.setFillColor(sf::Color::Green);
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(244, 500));
	leaf.setPoint(1, sf::Vector2f(200, 490));
	leaf.setPoint(3, sf::Vector2f(225, 465));
	leaf.setPoint(2, sf::Vector2f(180, 455));

	this->leaf = leaf;

	//trava
	sf::RectangleShape grass1(sf::Vector2f(5.f, 100.f));
	sf::RectangleShape grass2(sf::Vector2f(5.f, 100.f));
	sf::RectangleShape grass3(sf::Vector2f(5.f, 100.f));
	sf::RectangleShape grass4(sf::Vector2f(5.f, 100.f));
	sf::RectangleShape grass5(sf::Vector2f(5.f, 100.f));
	sf::RectangleShape grass6(sf::Vector2f(5.f, 100.f));
	grass1.setFillColor(sf::Color::Green);
	grass2.setFillColor(sf::Color::Green);
	grass3.setFillColor(sf::Color::Green);
	grass4.setFillColor(sf::Color::Green);
	grass5.setFillColor(sf::Color::Green);
	grass6.setFillColor(sf::Color::Green);
	grass1.setPosition(sf::Vector2f(250, 610));
	grass1.rotate(140);
	grass2.setPosition(sf::Vector2f(250, 610));
	grass2.rotate(150);
	grass3.setPosition(sf::Vector2f(250, 610));
	grass3.rotate(160);
	grass4.setPosition(sf::Vector2f(247, 610));
	grass4.rotate(-140);
	grass5.setPosition(sf::Vector2f(247, 610));
	grass5.rotate(-150);
	grass6.setPosition(sf::Vector2f(247, 610));
	grass6.rotate(-160);

	this->grass1 = grass1;
	this->grass2 = grass2;
	this->grass3 = grass3;
	this->grass4 = grass4;
	this->grass5 = grass5;
	this->grass6 = grass6;

	//kapljica kise
	sf::CircleShape raindrop(5.f);
	raindrop.setPosition(600, y);
	raindrop.setFillColor(sf::Color::Blue);

	this->raindrop = raindrop;
	y = 0;
}

void Cvijet::draw()
{

	window->draw(circle2);
	window->draw(leaf);
	window->draw(branch);
	window->draw(convex);
	window->draw(circle);
	window->draw(grass1);
	window->draw(grass2);
	window->draw(grass3);
	window->draw(grass4);
	window->draw(grass5);
	window->draw(grass6);

	//animacija
	window->draw(raindrop);

	for (unsigned long long i = 0; i < 10000000; i++)
	{

	}

	y = y + 10;
	raindrop.setPosition(285, y);

	if (y == 380)
		y = 0;
	
}
