#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
using namespace sf;
class Cvijet
{private:

	RenderWindow* window = nullptr;


public:
	Cvijet(sf::RenderWindow *window);
	RectangleShape Background();
	CircleShape krug1Sunce();
	CircleShape krug2Sunce();
	RectangleShape Trava();
	RectangleShape Cvijetic();
	CircleShape Cvijetic2();
	CircleShape Latica1();
	CircleShape Latica2();
	CircleShape Latica3();
	CircleShape Latica4();
	CircleShape Latica5();
	CircleShape Latica6();
	CircleShape Latica7();
	CircleShape Latica8();

	void draw();

};

