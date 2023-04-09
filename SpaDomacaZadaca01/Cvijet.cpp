#include "Cvijet.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

RectangleShape Cvijet::Background()
{
	return RectangleShape(Vector2f(1920.f, 1080.f));
}

CircleShape Cvijet::krug1Sunce()
{
	return CircleShape(150.f);
}

CircleShape Cvijet::krug2Sunce()
{
	return CircleShape(100.f);
}

RectangleShape Cvijet::Trava()
{
	return RectangleShape(Vector2f(1920.f, 200.f));
}

RectangleShape Cvijet::Cvijetic()
{
	return RectangleShape(Vector2f(25.f, 300.f));
}

CircleShape Cvijet::Cvijetic2()
{
	return CircleShape(100.f);
}

CircleShape Cvijet::Latica1()
{
	return CircleShape(50.f);
}

CircleShape Cvijet::Latica2()
{
	return CircleShape(50.f);
}

CircleShape Cvijet::Latica3()
{
	return CircleShape(50.f);
}

CircleShape Cvijet::Latica4()
{
	return CircleShape(50.f);
}

CircleShape Cvijet::Latica5()
{
	return CircleShape(50.f);
}

CircleShape Cvijet::Latica6()
{
	return CircleShape(50.f);
}

CircleShape Cvijet::Latica7()
{
	return CircleShape(50.f);
}


CircleShape Cvijet::Latica8()
{
	return CircleShape(50.f);
}


void Cvijet::draw()
{
	RectangleShape Nebo = Background();
	RectangleShape Trva = Trava();
	CircleShape Sunce = krug1Sunce();
	CircleShape Sunce2 = krug2Sunce();
	RectangleShape Flower = Cvijetic();
	CircleShape Flower2 = Cvijetic2();
	CircleShape Latica01 = Latica1();
	CircleShape Latica02 = Latica2();
	CircleShape Latica03 = Latica3();
	CircleShape Latica04 = Latica4();
	CircleShape Latica05 = Latica5();
	CircleShape Latica06 = Latica6();
	CircleShape Latica07 = Latica7();
	CircleShape Latica08 = Latica8();
	

	Nebo.setFillColor(Color(41, 182, 242));
	Trva.setFillColor(Color::Green);
	Sunce.setFillColor(Color(227, 182, 242));
	Sunce2.setFillColor(Color(250, 205, 25));
	Flower2.setFillColor(Color(227, 182, 242));
	Flower.setFillColor(Color(19, 117, 43));
	Latica01.setFillColor(Color(117, 19, 19));
	Latica02.setFillColor(Color(117, 19, 19));
	Latica03.setFillColor(Color(117, 19, 19));
	Latica04.setFillColor(Color(117, 19, 19));
	Latica05.setFillColor(Color(117, 19, 19));
	Latica06.setFillColor(Color(117, 19, 19));
	Latica06.setFillColor(Color(117, 19, 19));
	Latica07.setFillColor(Color(117, 19, 19));
	Latica08.setFillColor(Color(117, 19, 19));

	Sunce.move(50, 50);
	Sunce2.move(50, 100);
	Trva.move(0, 900);
	Flower.move(800, 650);
	Flower2.move(720, 550);
	Latica01.move(715, 550);
	Latica02.move(720, 670);
	Latica03.move(800, 670);
	Latica04.move(675, 620);
	Latica05.move(770, 510);
	Latica06.move(690, 535);
	Latica06.move(840, 550);
	Latica07.move(845, 610);
	Latica08.move(845, 550);



	this->window->draw(Nebo);
	this->window->draw(Trva);
	this->window->draw(Sunce);
	this->window->draw(Sunce2);
	this->window->draw(Flower);
	this->window->draw(Flower2);
	this->window->draw(Latica01);
	this->window->draw(Latica02);
	this->window->draw(Latica03);
	this->window->draw(Latica04);
	this->window->draw(Latica05);
	this->window->draw(Latica06);
	this->window->draw(Latica07);
	this->window->draw(Latica08);
	
}
