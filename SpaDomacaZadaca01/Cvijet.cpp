#include "Cvijet.h"
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;

Cvijet::Cvijet(RenderWindow& window)
{
	Color boja;
	boja.r = 255;
	boja.g = 0;
	boja.b = 0;

	stabiljka.setSize(Vector2f(10.0f, 220.0f));
	listic.setRadius(60.0f);
	latica.setRadius(50.0f);
	glava.setRadius(90.0f);

	stabiljka.setPosition(185,275);
	listic.setPosition(195,390);
	listic.setPointCount(60);
	listic.setScale(Vector2f(0.2,0.8));
	listic.setRotation(-120);
	glava.setPosition(100,100);
	latica.setPosition(140, 145);
	
	glava.setFillColor(Color::Red);
	stabiljka.setFillColor(Color::Green);
	latica.setFillColor(Color::Yellow);
	listic.setFillColor(Color::Green);
	


}

RectangleShape Cvijet::get_stabiljka() const
{
	return stabiljka;
}

CircleShape Cvijet::get_glava() const
{
	return glava;
}

CircleShape Cvijet::get_latica() const
{
	return latica;
}

CircleShape Cvijet::get_listic() const
{
	return listic;
}

void Cvijet::set_stabiljka(RectangleShape stabiljka)
{
	this->stabiljka = stabiljka;
}

void Cvijet::set_glava(CircleShape glava)
{
	this->glava = glava;
}

void Cvijet::set_latica(CircleShape latica)
{
	this->latica = latica;
}

void Cvijet::set_listic(CircleShape list)
{
	this->listic = listic;
}
