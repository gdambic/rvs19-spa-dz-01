#include "Cvijet.h"
#include "Elipsa.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Cvijet::Cvijet(RenderWindow &window) : window(window)
{
	this->brzina = 7;
	this->brzina2 = -4;
	this->r = 280.f;
	this->x= 380.f;
	this->elipsaX = 380.f;
	this->elipsa2X = 465.f;
	this->elipsa3X = 500.f;
	this->elipsa4X = 480.f;
	this->elipsa5X = 420.f;
	this->elipsa6X = 350.f;
	this->elipsa7X = 220.f;
	this->elipsa7X = 330.f;
	this->listR = 200.f;
	this->list2R = 160.f;
	//dt = clock.restart();
}

void Cvijet::draw_krug()
{
	CircleShape krug;
	krug.setRadius((30.f));
	krug.setFillColor(Color(215, 185, 35));
	krug.setPosition(x, 160);
	krug.setOutlineThickness(2.f);
	krug.setOutlineColor(Color(230, 165, 10));
	
	x += brzina * dt.asSeconds();

	window.draw(krug);
}

void Cvijet::draw_stabljika() {

	RectangleShape stabljika1(Vector2f(80.f, 3.f));
	stabljika1.setPosition(376, 322);
	stabljika1.rotate(r);
	stabljika1.setFillColor(Color(52, 150, 59));
	stabljika1.setOutlineThickness(1.f);
	stabljika1.setOutlineColor(Color(40, 100, 44));

	RectangleShape stabljika2(Vector2f(80.f, 3.f));
	stabljika2.setPosition(379, 325);
	stabljika2.rotate(95.f);
	stabljika2.setFillColor(Color(52, 150, 59));
	stabljika2.setOutlineThickness(1.f);
	stabljika2.setOutlineColor(Color(40, 100, 44));

	RectangleShape stabljika3(Vector2f(80.f, 3.f));
	stabljika3.setPosition(372, 400);
	stabljika3.rotate(80.f);
	stabljika3.setFillColor(Color(52, 150, 59));
	stabljika3.setOutlineThickness(1.f);
	stabljika3.setOutlineColor(Color(40, 100, 44));

	RectangleShape stabljika4(Vector2f(82.f, 2.5f));
	stabljika4.setPosition(379, 322);
	stabljika4.rotate(95.f);
	stabljika4.setFillColor(Color(52, 150, 59));

	r += brzina * dt.asSeconds();

	window.draw(stabljika1);
	window.draw(stabljika2);
	window.draw(stabljika3);
	window.draw(stabljika4);
}

void Cvijet::draw_list()
{
	Elipsa list(Vector2f(30.f, 55.f));
	list.setPosition(415, 495);
	list.setFillColor(Color(52, 150, 59));
	list.rotate(listR);
	list.setOutlineThickness(1.f);
	list.setOutlineColor(Color(40, 100, 44));

	listR += brzina2 * dt.asSeconds();

	window.draw(list);
}

void Cvijet::draw_list2()
{
	Elipsa list2(Vector2f(30.f, 55.f));
	list2.setPosition(405, 470);
	list2.setFillColor(Color(52, 150, 59));
	list2.rotate(list2R);
	list2.setOutlineThickness(1.f);
	list2.setOutlineColor(Color(40, 100, 44));

	list2R += brzina * dt.asSeconds();

	window.draw(list2);
}

void Cvijet::draw_trava()
{
	CircleShape trava(1200.f);
	trava.setFillColor(Color(64, 143, 69));
	trava.setPosition(-800, 450);
	trava.setOutlineThickness(2.f);
	trava.setOutlineColor(Color(42, 105, 50));

	window.draw(trava);
}

void Cvijet::draw_latice() { 

	Elipsa elipsa(Vector2f(30.f, 40.f));
	elipsa.setPosition(elipsaX, 100);
	elipsa.setFillColor(Color(165, 53, 53));
	elipsa.setOutlineThickness(1.f);
	elipsa.setOutlineColor(Color(115, 53, 53));

	Elipsa elipsa2(Vector2f(30.f, 40.f));
	elipsa2.setPosition(elipsa2X, 110);
	elipsa2.setFillColor(Color(165, 53, 53));
	elipsa2.rotate(45.f);
	elipsa2.setOutlineThickness(1.f);
	elipsa2.setOutlineColor(Color(115, 53, 53));

	Elipsa elipsa3(Vector2f(30.f, 40.f));
	elipsa3.setPosition(elipsa3X, 170);
	elipsa3.setFillColor(Color(165, 53, 53));
	elipsa3.rotate(90.f);
	elipsa3.setOutlineThickness(1.f);
	elipsa3.setOutlineColor(Color(115, 53, 53));

	Elipsa elipsa4(Vector2f(30.f, 40.f));
	elipsa4.setPosition(elipsa4X, 240);
	elipsa4.setFillColor(Color(165, 53, 53));
	elipsa4.rotate(135.f);
	elipsa4.setOutlineThickness(1.f);
	elipsa4.setOutlineColor(Color(115, 53, 53));

	Elipsa elipsa5(Vector2f(30.f, 40.f));
	elipsa5.setPosition(elipsa5X, 280);
	elipsa5.setFillColor(Color(165, 53, 53));
	elipsa5.rotate(190.f);
	elipsa5.setOutlineThickness(1.f);
	elipsa5.setOutlineColor(Color(115, 53, 53));

	Elipsa elipsa6(Vector2f(30.f, 40.f));
	elipsa6.setPosition(elipsa6X, 250);
	elipsa6.setFillColor(Color(165, 53, 53));
	elipsa6.rotate(240.f);
	elipsa6.setOutlineThickness(1.f);
	elipsa6.setOutlineColor(Color(115, 53, 53));

	Elipsa elipsa7(Vector2f(30.f, 40.f));
	elipsa7.setPosition(elipsa7X, 150);
	elipsa7.setFillColor(Color(165, 53, 53));
	elipsa7.rotate(320.f);
	elipsa7.setOutlineThickness(1.f);
	elipsa7.setOutlineColor(Color(115, 53, 53));	

	window.draw(elipsa);
	window.draw(elipsa2);
	window.draw(elipsa4);
	window.draw(elipsa3);
	window.draw(elipsa6);
	window.draw(elipsa5);
	window.draw(elipsa7);

	elipsaX += brzina * dt.asSeconds();
	elipsa2X += brzina * dt.asSeconds();
	elipsa3X += brzina * dt.asSeconds();
	elipsa4X += brzina * dt.asSeconds();
	elipsa5X += brzina * dt.asSeconds();
	elipsa6X += brzina * dt.asSeconds();
	elipsa7X += brzina * dt.asSeconds();
}

void Cvijet::draw() 
{
	//Iscrtavanje
	window.clear(Color(10, 125, 196));
	draw_trava();
	draw_list2();
	draw_stabljika();
	draw_latice();
	draw_list();
	draw_krug();

	dt = clock.restart();

	if (r >= 290 || r <= 280) {
		brzina *= -1.0f;
	}

	if (r >= 290 || r <= 280) {
		brzina2 *= -1.0f;
	}
}
