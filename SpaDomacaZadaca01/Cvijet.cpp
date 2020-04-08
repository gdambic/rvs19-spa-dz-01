#include "Cvijet.h"
#include<vector>
#include<SFML/Graphics.hpp>

using namespace sf;

Cvijet::Cvijet(RenderWindow& window) :window(window)
{
}

void Cvijet::draw()
{
	krug.setRadius(100);
	krug.setPosition(100.f, 100.f);
	krug.setFillColor(Color(250, 250, 0));

	krug.setOutlineThickness(40.f);
	krug.setOutlineColor(Color(150, 0, 0));

	tijelo.setSize(Vector2f(30, 200));
	tijelo.setPosition(185.f, 340.f);
	tijelo.setFillColor(Color(0, 150, 0));

	list.setPointCount(4);
	list.setPoint(0, Vector2f(215, 430));
	list.setPoint(1, Vector2f(215, 480));
	list.setPoint(2, Vector2f(235, 460));
	list.setPoint(3, Vector2f(255, 410));
	list.setFillColor(Color(50, 150, 0));

	list2.setPointCount(4);
	list2.setPoint(0, Vector2f(185, 430));
	list2.setPoint(1, Vector2f(185, 480));
	list2.setPoint(2, Vector2f(185, 420));
	list2.setPoint(3, Vector2f(125, 360));
	list2.setFillColor(Color(50, 150, 0));

	krug2.setRadius(30);
	krug2.setFillColor(Color(250, 250, 0));

	Vertex zraka[] =
	{
		Vertex(Vector2f(30.f, 30.f)),
		Vertex(Vector2f(70.f,70.f))

	};

	Vertex zraka2[] =
	{
		Vertex(Vector2f(30.f, 30.f)),
		Vertex(Vector2f(30.f,90.f))

	};

	Vertex zraka3[] =
	{
		Vertex(Vector2f(30.f, 30.f)),
		Vertex(Vector2f(45.f,75.f))

	};

	Vertex zraka4[] =
	{
		Vertex(Vector2f(30.f, 30.f)),
		Vertex(Vector2f(75.f,25.f))

	};

	zraka->color = Color::Yellow;
	zraka2->color = Color::Yellow;
	zraka3->color = Color::Yellow;
	zraka4->color = Color::Yellow;




	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (clock.getElapsedTime().asSeconds() > 1.0f) {

			if (krug2.getRadius() == 30.f)
			{
				krug2.setRadius(25.f);
				
			}
			else {
				
				krug2.setRadius(30.f);
				
			}

			clock.restart();
		}

		window.clear();

		window.draw(tijelo);
		window.draw(krug);
		window.draw(list);
		window.draw(list2);
		window.draw(krug2);
		window.draw(zraka, 2, Lines);
		window.draw(zraka2, 2, Lines);
		window.draw(zraka3, 2, Lines);
		window.draw(zraka4, 2, Lines);




		window.display();
	}
}


	