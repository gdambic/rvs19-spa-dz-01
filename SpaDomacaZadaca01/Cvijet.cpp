#include "Cvijet.h"


Cvijet::Cvijet(RenderWindow *window) : mwin(*window)
{
}

void Cvijet::draw()
{
	while (mwin.isOpen())
	{
		Event event;
		while (mwin.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				mwin.close();
			}
		}

		mwin.clear();

		CircleShape sunce(20.f);
		sunce.setFillColor(Color::Yellow);
		sunce.setPosition(10, 50);


		CircleShape krug(45.f);
		krug.setFillColor(Color::Yellow);
		krug.setPosition(50, 135);


		krug.setOutlineThickness(25.f);
		krug.setOutlineColor(Color::Red);

		RectangleShape linija(Vector2f(150.f, 5.f));
		linija.setFillColor(Color::Green);
		linija.rotate(90.f);
		linija.setPosition(100, 250);

		ConvexShape kocka;
		kocka.setFillColor(Color::Green);
		kocka.setPosition(100, 200);
		kocka.setPointCount(4);
		kocka.setPoint(0, Vector2f(45.f, 60.f));
		kocka.setPoint(1, Vector2f(70, 20.f));
		kocka.setPoint(2, Vector2f(30.f, 150.f));
		kocka.setPoint(3, Vector2f(0.f, 100.f));

		mwin.draw(sunce);
		mwin.draw(krug);
		mwin.draw(linija);
		mwin.draw(kocka);
		mwin.display();
	}
}





