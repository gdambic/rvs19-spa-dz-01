#include "Cvijet.h"
#include <math.h>
#include <iostream>


Cvijet::Cvijet():Cvijet(window)
{
	
	
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->middlePoint = sf::Vector2f(400, 300);
	this->radius = 25;
	this->scaling = 2;
	this->window = (window);
	
	//stabiljka
	this->line = sf::RectangleShape(sf::Vector2f(5, 300));
	line.setPosition(middlePoint);
	line.setFillColor(sf::Color::Green);
	line.setOrigin(2.5, 0);

	//Tucak
    this->bud = sf::CircleShape(radius / 2);
	bud.setPosition(middlePoint);
	bud.setOrigin(radius / 2, radius / 2);
	bud.setFillColor(sf::Color::Yellow);
	bud.setOutlineColor(sf::Color::Blue);
	bud.setOutlineThickness(2);

	//Petal
	this->petalOne = sf::CircleShape(25);
	petalOne.setPosition(middlePoint);
	petalOne.setScale(2.5, 1);
	petalOne.setOrigin(radius, radius);

	this->petalTwo = sf::CircleShape(25);
	petalTwo.setPosition(middlePoint);
	petalTwo.setScale(1, 2.5);
	petalTwo.setOrigin(radius, radius);

	this->petalThree = sf::CircleShape(25);
	petalThree.setPosition(middlePoint);
	petalThree.setScale(1, 2.5);
	petalThree.setOrigin(radius, radius);


	petalOne.scale(2, 2);
	petalTwo.scale(2, 2);
	petalThree.scale(2, 2);
	bud.scale(2, 2);
	
	
	set_degree(0.0);
	
	this->colour = sf::Color(255, 0, 0, 128);
	this->stepOne = false;
	this->stepTwo = false;
	this->stepThree = false;
	this->stepFinal = false;
	
	
	
	//-400,-300

}

void Cvijet::set_degree(float degree)
{
	this->degree = degree;
}

float Cvijet::get_degree()
{
	return this->degree;
}



void Cvijet::draw()
{

	window->draw(line);


	

	petalTwo.setRotation(45);
	petalTwo.rotate(degree);


	petalThree.setRotation(90);
	petalThree.rotate(degree);

	petalOne.setRotation(250);
	petalOne.rotate(degree);
	
	petalOne.setFillColor(colour+(colour,sf::Color(128,128,0,0)));
	petalTwo.setFillColor(colour + (colour, sf::Color(0, 128, 128, 0)));
	petalThree.setFillColor(colour + (colour, sf::Color(128, 0, 128, 0)));
	window->draw(petalTwo);
	window->draw(petalThree);
	window->draw(petalOne);
	window->draw(bud);
	
	
	degree += 1;
	
	if (get_degree() == 360) {
		set_degree(0);
	}
	
	if (colour==(colour,sf::Color(0,0,0,128))||stepOne==true) {
		colour += (colour, sf::Color(1, 0, 0, 0));
		stepOne = true;
	}
	
	if (colour==(colour,sf::Color(255,0,0,128))||stepTwo==true) {
		colour += (colour, sf::Color(0, 1, 0, 0));
		colour -= (colour, sf::Color(1, 0, 0, 0));
		stepTwo = true;
		stepOne = false;
		stepFinal = false;
	}
	if ((colour.g == 255 && colour.a==128)||stepThree==true) {
		colour += (colour, sf::Color(0, 0, 1, 0));
		colour -= (colour, sf::Color(0, 1, 0, 0));
		stepThree = true;
		stepTwo = false;
	}
	if ((colour.b == 255 && colour.a==128)|| stepFinal == true) {
		colour += (colour, sf::Color(1, 0, 0, 0));
		colour -= (colour, sf::Color(0, 0, 1, 0));
		stepFinal = true;
		stepThree = false;
	}
}
