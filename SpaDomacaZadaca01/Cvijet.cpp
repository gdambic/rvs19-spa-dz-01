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
	Time vrijeme=sat.getElapsedTime();

	sunce.setPosition(100, 100);
	sunce.setOrigin(50, 50);
	sunce.setRadius(60);
	sunce.setRotation(vrijeme.asMilliseconds() / 10);
	sunce.setPointCount(6);
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

	list.setPointCount(4);
	list.setPoint(0, Vector2f(50.f, 50.f));
	list.setPoint(1, Vector2f(100.f, 25.f));
	list.setPoint(2, Vector2f(250.f,50.f));
	list.setPoint(3, Vector2f(100.f, 75.f));
	list.setFillColor(Color(0, 100, 0));
	list.setPosition(193, 470);
	list.setRotation(-25);
	list.move(2, 2);


	latice[0].setRadius(15);
	latice[0].setPointCount(30);
	latice[0].setPosition(228, 272);
	latice[0].setFillColor(Color(255, 255, 255));


	latice[1].setRadius(15);
	latice[1].setPointCount(30);
	latice[1].setPosition(198, 282);
	latice[1].setFillColor(Color(255, 255, 255));


	latice[2].setRadius(15);
	latice[2].setPointCount(30);
	latice[2].setPosition(175, 312);
	latice[2].setFillColor(Color(255, 255, 255));

	latice[3].setRadius(15);
	latice[3].setPointCount(30);
	latice[3].setPosition(262, 277);
	latice[3].setFillColor(Color(255, 255, 255));

	latice[4].setRadius(15);
	latice[4].setPointCount(30);
	latice[4].setPosition(288, 297);
	latice[4].setFillColor(Color(255, 255, 255));

	latice[5].setRadius(15);
	latice[5].setPointCount(30);
	latice[5].setPosition(300, 329);
	latice[5].setFillColor(Color(255, 255, 255));


	latice[6].setRadius(15);
	latice[6].setPointCount(30);
	latice[6].setPosition(294, 365);
	latice[6].setFillColor(Color(255, 255, 255));

	latice[7].setRadius(15);
	latice[7].setPointCount(30);
	latice[7].setPosition(269, 391);
	latice[7].setFillColor(Color(255, 255, 255));

	latice[8].setRadius(15);
	latice[8].setPointCount(30);
	latice[8].setPosition(171, 345);
	latice[8].setFillColor(Color(255, 255, 255));
	
	latice[9].setRadius(15);
	latice[9].setPointCount(30);
	latice[9].setPosition(186, 380);
	latice[9].setFillColor(Color(255, 255, 255));

	window->draw(sunce);
	window->draw(tucak);
	window->draw(stabljika);
	window->draw(list);
	for (int i = 0; i < 10; i++)
	{
		window->draw(latice[i]);
	}
	
	
}
