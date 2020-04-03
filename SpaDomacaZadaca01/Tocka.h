#pragma once
#include<SFML/Graphics.hpp>

class Tocka {
	double x;
	double y;
public:
	Tocka();
	Tocka(double x, double y);

	void SetX(double x);
	void SetY(double y);
	void init(double x, double y);
	void init(Tocka toc);

	double GetX();
	double GetY();
	Tocka GetTocka();
	sf::Vector2f GetVector2f();

	Tocka operator+ (Tocka t);
	Tocka operator- (Tocka t);
	void operator= (Tocka t);
	void operator+= (Tocka t);
	void operator-= (Tocka t);
};