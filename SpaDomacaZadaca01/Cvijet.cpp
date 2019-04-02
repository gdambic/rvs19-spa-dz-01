#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;

}

void Cvijet::flower()
{
	
	
	window->draw(stem);
	draw_cshape(leaf);
	draw_cshape(leaf2);

	
}
void Cvijet::draw_cshape(sf::CircleShape shape) {
	window->draw(shape);

}

void Cvijet::rotation()
{
	petal.rotate(100.f);
	petal2.rotate(200.f);
	petal3.rotate(300.f);
}

void Cvijet::set_shape()
{
	middle.setRadius(80.f);
	middle.setPointCount(8);
	middlem.setRadius(10.f);
	 petal.setRadius(50.f);
	 petal2.setRadius(50.f);
	 petal3.setRadius(50.f);
	 stem.setSize(sf::Vector2f(10.f, 250.f));
	 leaf.setRadius(35.f);
	 leaf.setPointCount(4);
	 leaf2.setRadius(35.f);
	 leaf2.setPointCount(4);
}

void Cvijet::set_color()
{
	petal.setFillColor(sf::Color::Red);
	petal2.setFillColor(sf::Color::Red);
	petal3.setFillColor(sf::Color::Red);
	middlem.setFillColor(sf::Color::Magenta);
	middle.setFillColor(sf::Color::Yellow);
	leaf.setFillColor(sf::Color::Green);
	leaf2.setFillColor(sf::Color::Green);
	stem.setFillColor(sf::Color::Green);
	
}

void Cvijet::set_position()
{
	
	middle.setPosition(210.f, 150.f);
	middlem.setPosition(280.f, 225.f);
	stem.setPosition(285.f, 305.f);
	leaf.setPosition(305.f, 405.f);
	leaf.setRotation(120.f);
	leaf2.setPosition(370.f, 455.f);
	leaf2.setRotation(120.f);
	petal.setOrigin(10.f, 10.f);
	petal.setPosition(290.f, 235.f);
	petal2.setOrigin(10.f, 10.f);
	petal2.setPosition(290.f, 235.f);
	petal3.setOrigin(10.f, 10.f);
	petal3.setPosition(290.f, 235.f);
}


void Cvijet::draw()
{
	rotation();
	
	elapsed = clock.getElapsedTime().asSeconds();

		if ( elapsed >= 1.0f) 
		{
			petal.setFillColor(sf::Color::Blue);
			petal2.setFillColor(sf::Color::Blue);
			petal3.setFillColor(sf::Color::Blue);
			middlem.setFillColor(sf::Color::Cyan);
		}
	 if (elapsed >= 2.0f)
	 {
		 clock.restart();
	 }
	 
	 draw_cshape(middle);
		draw_cshape(petal);
		draw_cshape(petal2);
		draw_cshape(petal3);
		draw_cshape(middlem);
	}










