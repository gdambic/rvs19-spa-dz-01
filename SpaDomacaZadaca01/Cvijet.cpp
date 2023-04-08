#include "Cvijet.h"
#include <SFML/Graphics.hpp>
using namespace std;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

RectangleShape Cvijet::Nebo()
{
	return RectangleShape(Vector2f(1920.f,1080.f));
}

CircleShape Cvijet::Sunce()
{
	return CircleShape(150.f);
}

CircleShape Cvijet::Sunce2()
{
	return CircleShape(100.f);
}

RectangleShape Cvijet::Trava()
{
	return RectangleShape(Vector2f(1920.f,200.f));
}

RectangleShape Cvijet::Cvijetic()
{
	return RectangleShape(Vector2f(25.f,300.f));
}

CircleShape Cvijet::Cvijetic2()
{
	return CircleShape(100.f);
}

CircleShape Cvijet::Latica()
{
	return CircleShape(50.f);
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

RectangleShape Cvijet::Kuca()
{
	return RectangleShape(Vector2f(400.f,400.f));
}

RectangleShape Cvijet::Vrata()
{
	return RectangleShape(Vector2f(150.f,200.f));
}

CircleShape Cvijet::Rucka()
{
	return CircleShape(5.f);
}

RectangleShape Cvijet::Krov()
{
	return RectangleShape(Vector2f(365.f,25.f));
}

RectangleShape Cvijet::Krov1()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov2()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov3()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov4()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov5()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov6()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov7()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov8()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}

RectangleShape Cvijet::Krov9()
{
	return RectangleShape(Vector2f(365.f, 25.f));
}





void Cvijet::draw()
{
	RectangleShape Sky = Nebo();
	RectangleShape Grass = Trava();
	CircleShape Sun = Sunce();
	CircleShape  Sun1 = Sunce2();
	RectangleShape Flower = Cvijetic();
	CircleShape Flower2 = Cvijetic2();
	CircleShape Latica12 = Latica();
	CircleShape Latica13 = Latica1();
	CircleShape Latica14 = Latica2();
	CircleShape Latica15 = Latica3();
	CircleShape Latica16 = Latica4();
	CircleShape Latica17 = Latica5();
	CircleShape Latica18 = Latica6();
	RectangleShape House = Kuca();
	RectangleShape Door = Vrata();
	CircleShape Handle = Rucka();
	RectangleShape Roof = Krov();
	RectangleShape Roof1 = Krov1();
	RectangleShape Roof2 = Krov2();
	RectangleShape Roof3 = Krov3();
	RectangleShape Roof4 = Krov4();
	RectangleShape Roof5 = Krov5();
	RectangleShape Roof6 = Krov6();
	RectangleShape Roof7 = Krov7();
	RectangleShape Roof8 = Krov8();
	RectangleShape Roof9 = Krov9();
	

	Sky.setFillColor(Color(41, 182, 242));
	Grass.setFillColor(Color::Green);
	Sun.setFillColor(Color(227, 195, 14));
	Sun1.setFillColor(Color(250, 205, 25));
	Flower.setFillColor(Color(19, 117, 43));
	Flower2.setFillColor(Color(250, 205, 25));
	Latica12.setFillColor(Color(117, 19, 19));
	Latica13.setFillColor(Color(117, 19, 19));
	Latica14.setFillColor(Color(117, 19, 19));
	Latica15.setFillColor(Color(117, 19, 19));
	Latica16.setFillColor(Color(117, 19, 19));
	Latica17.setFillColor(Color(117, 19, 19));
	Latica18.setFillColor(Color(117, 19, 19));
	House.setFillColor(Color(158, 88, 35));
	Door.setFillColor(Color(79, 44, 5));
	Handle.setFillColor(Color::Black);
	Roof.setFillColor(Color(87, 44, 12));
	Roof1.setFillColor(Color(87, 44, 12));
	Roof2.setFillColor(Color(87, 44, 12));
	Roof3.setFillColor(Color(87, 44, 12));
	Roof4.setFillColor(Color(87, 44, 12));
	Roof5.setFillColor(Color(87, 44, 12));
	Roof6.setFillColor(Color(87, 44, 12));
	Roof7.setFillColor(Color(87, 44, 12));
	Roof8.setFillColor(Color(87, 44, 12));
	Roof9.setFillColor(Color(87, 44, 12));
	Grass.move(0, 900);
	Sun1.move(50, 50);
	Flower.move(800, 650);
	Flower2.move(715, 550);
	Latica12.move(720,670);
	Latica13.move(800,670 );
	Latica14.move(675, 620);
	Latica15.move(690, 535);
	Latica16.move(770,510);
	Latica17.move(840,550);
	Latica18.move(845,610);
	House.move(1600, 500);
	Door.move(1650, 700);
	Handle.move(1775, 800);
	Roof.move(1550, 515);
	Roof1.move(1570, 500);
	Roof2.move(1590, 485);
	Roof3.move(1610, 470);
	Roof4.move(1630, 455);
	Roof5.move(1650, 440);
	Roof6.move(1670, 425);
	Roof7.move(1690, 410);
	Roof8.move(1710, 395);
	Roof9.move(1730, 380);

	this->window->draw(Sky);
	this->window->draw(Sun);
	this->window->draw(Sun1);
	this->window->draw(Grass);
	this->window->draw(Flower);
	this->window->draw(Flower2);
	this->window->draw(Latica12);
	this->window->draw(Latica13);
	this->window->draw(Latica14);
	this->window->draw(Latica15);
	this->window->draw(Latica16);
	this->window->draw(Latica17);
	this->window->draw(Latica18);
	this->window->draw(House);
	this->window->draw(Door);
	this->window->draw(Handle);
	this->window->draw(Roof);
	this->window->draw(Roof1);
	this->window->draw(Roof2);
	this->window->draw(Roof3);
	this->window->draw(Roof4);
	this->window->draw(Roof5);
	this->window->draw(Roof6);
	this->window->draw(Roof7);
	this->window->draw(Roof8);
	this->window->draw(Roof9);
	



}


