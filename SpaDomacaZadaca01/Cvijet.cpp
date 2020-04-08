#include "Cvijet.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Cvijet::Cvijet(sf::RenderWindow* Win)
{
	this->Win = Win;
	frame = 0;
}



void Cvijet::draw()
{	
	//Sunce
	CircleShape sun(60.f);
	sun.setFillColor(Color(255, 255, 0));
	sun.setOutlineColor(Color(255, 234, 0));
	sun.setOutlineThickness(10);
	sun.setPosition(frame, 100);
	frame++;
	if (frame > 800) {
		frame = 0;
	}
	Win->draw(sun);

	//Stabiljka
	RectangleShape stem(Vector2f(20, 250));
	stem.setFillColor(Color(0, 255, 0));
	stem.setPosition(400, 370);
	Win->draw(stem);

	//Glava
	CircleShape flower(50.f);
	flower.setFillColor(Color(255, 255, 0));
	flower.setOutlineColor(Color(255, 0, 0));
	flower.setOutlineThickness(10);
	flower.setPosition(360, 300);

	CircleShape innerOutline(30.f);
	innerOutline.setFillColor(Color(255, 255, 0));
	innerOutline.setOutlineColor(Color(255, 0, 0));
	innerOutline.setOutlineThickness(10);
	innerOutline.setPosition(380, 320);

	Win->draw(flower);
	Win->draw(innerOutline);

}
