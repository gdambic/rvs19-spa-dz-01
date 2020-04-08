#include <SFML/Graphics.hpp>
#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(255, 255, 153));
	shape.setPosition(-40, -40);
	window->draw(shape);

	for (unsigned i = 0; i < 200; i += 50)
	{
		sf::CircleShape cloud((30 - (i / 20)));
		cloud.setFillColor(sf::Color::White);
		cloud.setPosition((i + 200), 10 + (i / 10));
		window->draw(cloud);
	}

	for (unsigned i = 0; i < 200; i += 50)
	{
		sf::CircleShape cloud((20 - (i / 20)));
		cloud.setFillColor(sf::Color::White);
		cloud.setPosition((i / 2 + 600), 100 + (i / 10));
		window->draw(cloud);
	}

	sf::RectangleShape ground3(sf::Vector2f(1000.f, 500.f));
	ground3.setPosition(0, 390);
	ground3.setFillColor(sf::Color(24, 134, 45));
	ground3.setOutlineThickness(1);
	ground3.setOutlineColor(sf::Color::Black);
	window->draw(ground3);

	sf::RectangleShape ground2(sf::Vector2f(1000.f, 500.f));
	ground2.setPosition(0, 430);
	ground2.setFillColor(sf::Color(81, 164, 82));
	window->draw(ground2);

	sf::RectangleShape ground1(sf::Vector2f(1000.f, 500.f));
	ground1.setPosition(0, 500);
	ground1.setFillColor(sf::Color(133, 196, 120));
	window->draw(ground1);


	sf::RectangleShape line(sf::Vector2f(250.f, 20.f));
	line.rotate(90.f);
	line.setPosition(400, 300);
	line.setFillColor(sf::Color(50, 205, 50));
	line.setOutlineThickness(3);
	line.setOutlineColor(sf::Color::Black);
	window->draw(line);

	sf::CircleShape shape3(70);
	shape3.setFillColor(sf::Color(254, 227, 197));
	shape3.setPosition(320, 110);
	shape3.setOutlineThickness(3);
	shape3.setOutlineColor(sf::Color::Black);
	window->draw(shape3);

	sf::CircleShape shape4(70);
	shape4.setFillColor(sf::Color(254, 227, 197));
	shape4.setPosition(420, 210);
	shape4.setOutlineThickness(3);
	shape4.setOutlineColor(sf::Color::Black);
	window->draw(shape4);

	sf::CircleShape shape5(70);
	shape5.setFillColor(sf::Color(254, 227, 197));
	shape5.setPosition(320, 310);
	shape5.setOutlineThickness(3);
	shape5.setOutlineColor(sf::Color::Black);
	window->draw(shape5);

	sf::CircleShape shape6(70);
	shape6.setFillColor(sf::Color(254, 227, 197));
	shape6.setPosition(220, 210);
	shape6.setOutlineThickness(3);
	shape6.setOutlineColor(sf::Color::Black);
	window->draw(shape6);

	sf::CircleShape shape2(65);
	shape2.setFillColor(sf::Color::Yellow);
	shape2.setPosition(325, 220);
	shape2.setOutlineThickness(3);
	shape2.setOutlineColor(sf::Color::Black);
	window->draw(shape2);

	//////////////ANIMACIJA////////////

	sf::Time elapsed1 = sat.getElapsedTime();

	sf::RectangleShape light1(sf::Vector2f(300.f, 2.f));
	light1.rotate(45.f);
	light1.setOrigin(150, 1);
	light1.setFillColor(sf::Color(255, 255, 153));
	light1.setRotation(elapsed1.asMilliseconds()-1000);
	window->draw(light1);

	sf::RectangleShape light2(sf::Vector2f(600.f, 2.f));
	light2.rotate(100.f);
	light2.setOrigin(300, 1);
	light2.setFillColor(sf::Color(255, 255, 153));
	light2.setRotation(elapsed1.asMilliseconds()-800);
	window->draw(light2);

	sf::RectangleShape light3(sf::Vector2f(600.f, 2.f));
	light3.rotate(100.f);
	light3.setOrigin(300, 1);
	light3.setFillColor(sf::Color(255, 255, 153));
	light3.setRotation(elapsed1.asMilliseconds()-600);
	window->draw(light3);

	sf::RectangleShape light4(sf::Vector2f(300.f, 2.f));
	light4.rotate(45.f);
	light4.setOrigin(150, 1);
	light4.setFillColor(sf::Color(255, 255, 153));
	light4.setRotation(elapsed1.asMilliseconds()-400);
	window->draw(light4);

	sf::RectangleShape light5(sf::Vector2f(600.f, 2.f));
	light5.rotate(100.f);
	light5.setOrigin(300, 1);
	light5.setFillColor(sf::Color(255, 255, 153));
	light5.setRotation(elapsed1.asMilliseconds()-200);
	window->draw(light5);

	sf::RectangleShape light6(sf::Vector2f(300.f, 2.f));
	light6.rotate(45.f);
	light6.setOrigin(150, 1);
	light6.setFillColor(sf::Color(255, 255, 153));
	light6.setRotation(elapsed1.asMilliseconds()-100);
	window->draw(light6);

	sf::RectangleShape light7(sf::Vector2f(600.f, 2.f));
	light7.rotate(100.f);
	light7.setOrigin(300, 1);
	light7.setFillColor(sf::Color(255, 255, 153));
	light7.setRotation(elapsed1.asMilliseconds()-500);
	window->draw(light7);
}
