#include "Cvijet.h"
#include <cmath>
using namespace sf;

Cvijet::Cvijet(RenderWindow* target)
{
    this->window = target;

	stabljika.setPointCount(4);
	stabljika.setPoint(0, Vector2f(398, 300));
	stabljika.setPoint(1, Vector2f(402, 300));
	stabljika.setPoint(2, Vector2f(412, 580));
	stabljika.setPoint(3, Vector2f(388, 580));
	stabljika.setFillColor(Color(34, 139, 40));

	listLijevo.setPointCount(4);
	listLijevo.setPoint(0, Vector2f(0, 0));
	listLijevo.setPoint(1, Vector2f(50, -20));
	listLijevo.setPoint(2, Vector2f(90, 0));
	listLijevo.setPoint(3, Vector2f(50, 20));
	listLijevo.setFillColor(Color(50, 205, 50));
	listLijevo.setScale(-1, 1);
	listLijevo.setPosition(398, 500);
	listLijevo.setRotation(40);

	listDesno.setPointCount(4);
	listDesno.setPoint(0, Vector2f(0, 0));
	listDesno.setPoint(1, Vector2f(50, -20));
	listDesno.setPoint(2, Vector2f(90, 0));
	listDesno.setPoint(3, Vector2f(50, 20));
	listDesno.setFillColor(Color(50, 205, 50));
	listDesno.setPosition(402, 450);
	listDesno.setRotation(-35);

	listDesnoDole.setPointCount(4);
	listDesnoDole.setPoint(0, Vector2f(0, 0));
	listDesnoDole.setPoint(1, Vector2f(50, -20));
	listDesnoDole.setPoint(2, Vector2f(90, 0));
	listDesnoDole.setPoint(3, Vector2f(50, 20));
	listDesnoDole.setFillColor(Color(50, 205, 50));
	listDesnoDole.setPosition(402, 530);
	listDesnoDole.setRotation(-35);


	for (int i = 0; i < 8; i++) {
		CircleShape l(25.f);
		l.setFillColor(Color(255, 182, 193));
		l.setOrigin(25, 25);
		float kut = i * 2 * 3.14f / 8;
		l.setPosition(400 + cos(kut) * 45, 300 + sin(kut) * 45);
		latice.push_back(l);
	}

	tucak.setRadius(35.f);
	tucak.setFillColor(Color::White);
	tucak.setOrigin(35, 35);
	tucak.setPosition(400, 300);

	nebo.setSize(Vector2f(800, 400));
	nebo.setFillColor(Color(135, 206, 235));

	trava.setSize(Vector2f(800, 200));
	trava.setPosition(0, 400);
	trava.setFillColor(Color::Green);

	sunce.setRadius(30);
	sunce.setFillColor(Color::Yellow);
	sunce.setOrigin(30, 30);
	sunce.setPosition(70, 70);

	o1.setRadius(20); o1.setFillColor(Color::White);
	o2.setRadius(25); o2.setFillColor(Color::White);
	o3.setRadius(20); o3.setFillColor(Color::White);

	o4.setRadius(15); o4.setFillColor(Color::White);
	o5.setRadius(20); o5.setFillColor(Color::White);
	o6.setRadius(15); o6.setFillColor(Color::White);



}

void Cvijet::draw()
{
	Time odPocetka = frameClock.getElapsedTime();
	float sekunde = odPocetka.asSeconds();

	float skala = 1.0f + sin(sekunde * 3.0f) * 0.2f;
	sunce.setScale(skala, skala);

	float x1 = fmod(sekunde * 40, 900) - 100;
	float x2 = fmod(sekunde * 60, 1000) - 200;

	o1.setPosition(x1, 80); o2.setPosition(x1 + 25, 70); o3.setPosition(x1 + 50, 80);
	o4.setPosition(x2, 150); o5.setPosition(x2 + 20, 140); o6.setPosition(x2 + 40, 150);

	window->draw(nebo);
	window->draw(trava);
	window->draw(sunce);
	window->draw(o1); window->draw(o2); window->draw(o3);
	window->draw(o4); window->draw(o5); window->draw(o6);
	window->draw(stabljika);
	window->draw(listLijevo);
	window->draw(listDesno);
	window->draw(listDesnoDole);

	for (int i = 0; i < latice.size(); i++) {
		window->draw(latice[i]);
	}

	window->draw(tucak);

}
