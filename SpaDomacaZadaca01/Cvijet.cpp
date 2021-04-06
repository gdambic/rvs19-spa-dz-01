#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Cvijet::Cvijet() //: window(window), RenderWindow& window
{
	//CircleShape krug(50.f);
	//krug.setFillColor(Color(100, 250, 50));
	//krug.setPosition(90.f, 90.f);
}

void Cvijet::draw(RenderWindow& window)
{
	CircleShape krug(50.f);
	window.draw(krug);
}
