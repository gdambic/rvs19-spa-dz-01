#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
	this->brojac = 0;
}

void Cvijet::draw() 
{
	brojac++;

	RectangleShape nebo;
	nebo.setSize(Vector2f(800, 400));
	nebo.setFillColor(Color::Blue);
	window->draw(nebo);

	RectangleShape trava;
	trava.setPosition(0.f, 400.f);
	trava.setSize(Vector2f(800, 200));
	trava.setFillColor(Color(0, 255, 0));
	window->draw(trava);

	CircleShape sunce(30.f);
	sunce.setPosition(120.f, 60.f);
	if (brojac % 60 >= 0 && brojac % 60 <= 30)
	{
		sunce.setFillColor(Color::Yellow);
	}
	else
	{
		sunce.setFillColor(Color::Red);
	}
	window->draw(sunce);

	RectangleShape stabljika_cvijeta;
	stabljika_cvijeta.setPosition(400.f, 250.f);
	stabljika_cvijeta.setSize(Vector2f(20, 150));
	stabljika_cvijeta.setFillColor(Color(0, 100, 0));
	window->draw(stabljika_cvijeta);

	CircleShape vanjski_dio_cvijeta(60.f);
	vanjski_dio_cvijeta.setFillColor(Color(153, 50, 204));
	vanjski_dio_cvijeta.setPosition(350.f, 140.f);
	window->draw(vanjski_dio_cvijeta);

	CircleShape unutarnji_dio_cvijeta_jedan(30.f);
	unutarnji_dio_cvijeta_jedan.setPointCount(4);
	unutarnji_dio_cvijeta_jedan.setFillColor(Color(255, 255, 255));
	unutarnji_dio_cvijeta_jedan.setPosition(380.f, 170.f);
	window->draw(unutarnji_dio_cvijeta_jedan);

	CircleShape unutarnji_dio_cvijeta_dva(15.f);
	unutarnji_dio_cvijeta_dva.setFillColor(Color(204, 204, 0));
	unutarnji_dio_cvijeta_dva.setPosition(395.f, 185.f);
	window->draw(unutarnji_dio_cvijeta_dva);

}