#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include<SFML/Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<iostream>
#include<fstream>

using namespace std;
using namespace sf;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{

	float granica_gornja = 500.0f;
	float granica_donja = 100.0f;
	float x = 300.0f;
	float y = 200.0f;
	float brzina = 100.0f; // piksela u sekundi


	sf::CircleShape circle(15.f);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(x, y);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear(sf::Color::Black);

		sf::Time dt = clock.restart();
		/****** POÈETAK ******/

		circle.setPosition(x, y);
		window->draw(circle);

		x += brzina * dt.asSeconds();

		if (x >= granica_gornja || x <= granica_donja) {
			brzina *= -1.0f;
		}


		//Texture tucak;
		//tucak.loadFromFile("tuckic.png");
		sf::CircleShape shapekrugmanji(50.f);
		//shape.setTexture(&tucak);
		shapekrugmanji.setFillColor(sf::Color::Yellow);
		shapekrugmanji.setOutlineThickness(30.f);
		shapekrugmanji.setOutlineColor(sf::Color::Red);

		shapekrugmanji.move(50, 50);
		window->draw(shapekrugmanji);

		sf::RectangleShape line(sf::Vector2f(200.f, 12.f));
		line.rotate(90.f);
		line.setFillColor(sf::Color::Green);
		line.move(100, 180);
		window->draw(line);

		sf::CircleShape square(40.f, 4);
		square.setFillColor(sf::Color::Green);
		square.move(100, 220);
		window->draw(square);


		window->display();



	}
}
