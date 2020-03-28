#include "Cvijet.h"
#include<SFML/Graphics.hpp>
#include<vector>


using namespace std;
using namespace sf;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
	
}

void::Cvijet::draw()
{

	sunce.setRadius(60);
	sunce.setPointCount(30);
	sunce.setFillColor(Color(255, 69, 0));
	sunce.setOutlineThickness(-14);
	sunce.setOutlineColor(Color(250, 128, 0));

	tucak.setPosition(200.f, 300.f);
	tucak.setRadius(50);
	tucak.setPointCount(30);
	tucak.setFillColor(Color(255, 255, 0));
	tucak.setOutlineThickness(-14);
	tucak.setOutlineColor(Color(250, 128, 0));

	stabljika.setSize(Vector2f(20.f, 200.f));
	stabljika.setFillColor(Color(0, 100, 0));
	stabljika.setPosition(239.f, 400.f);

	list01.setPointCount(3);
	list01.setRadius(50);
	list01.setFillColor(Color(0, 100, 0));
	list01.setPosition(249.f, 400.f);
	
	list02.setPointCount(3);
	list02.setRadius(35);
	list02.setFillColor(Color(124, 252, 0));
	list02.setPosition(255.f, 418.f);





	window->draw(sunce);
	window->draw(tucak);
	window->draw(stabljika);
	window->draw(list01);
	window->draw(list02);

}
