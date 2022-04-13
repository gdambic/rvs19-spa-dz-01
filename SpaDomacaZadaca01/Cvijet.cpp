#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Cvijet::Cvijet(RenderWindow& window)
{
	glavaCvijeta.setRadius(125);
	glavaCvijeta.setFillColor(Color(255, 255, 102));
	glavaCvijeta.setPosition(275, 50);
	glavaCvijeta.setOutlineThickness(10);
	glavaCvijeta.setOutlineColor(Color(102, 255, 102));
	glavaCvijeta.setPointCount(300);

	tijeloCvijeta.setSize(Vector2f(14, 400));
	tijeloCvijeta.setFillColor(Color(102, 255, 102));
	tijeloCvijeta.setPosition(393, 300);

	list1.setPointCount(4);
	list1.setFillColor(Color(102, 255, 102));
	list1.setPoint(0, Vector2f(400, 500));
	list1.setPoint(1, Vector2f(600, 400));
	list1.setPoint(2, Vector2f(500, 500));
	list1.setPoint(3, Vector2f(600, 500));

	list2.setPointCount(4);
	list2.setFillColor(Color(102, 255, 102));
	list2.setPoint(0, Vector2f(400, 500));
	list2.setPoint(1, Vector2f(200, 400));
	list2.setPoint(2, Vector2f(300, 500));
	list2.setPoint(3, Vector2f(200, 500));

	mouth.setSize(Vector2f(80, 20));
	mouth.setFillColor(Color(0, 0, 0));
	mouth.setPosition(360, 230);

	eye1.setRadius(20);
	eye1.setPosition(320, 120);
	eye1.setFillColor(Color(255, 69, 0));
	eye1.setPointCount(300);

	eye2.setRadius(20);
	eye2.setPosition(440, 120);
	eye2.setFillColor(Color(255, 69, 0));
	eye2.setPointCount(300);
}

void Cvijet::Draw(RenderWindow& window)
{
	window.draw(glavaCvijeta);
	window.draw(tijeloCvijeta);
	window.draw(list1);
	window.draw(list2);
	window.draw(mouth);
	window.draw(eye1);
	window.draw(eye2);
}

void Cvijet::Animate(Clock& clock)
{
	cout << clock.getElapsedTime().asSeconds() << endl;
	
	if (clock.getElapsedTime().asSeconds() >= 1)
	{
		eye1.setRadius(40);
		eye1.setFillColor(Color(0, 0, 0));
		eye2.setRadius(40);
		eye2.setFillColor(Color(0, 0, 0));
		mouth.setSize(Vector2f(80, 75));

	}

	if (clock.getElapsedTime().asSeconds() >= 2)
	{
		eye1.setRadius(20);
		eye1.setFillColor(Color(255, 69, 0));
		eye2.setRadius(20);
		eye2.setFillColor(Color(255, 69, 0));
		mouth.setSize(Vector2f(80, 20));

		clock.restart();
	}
}

