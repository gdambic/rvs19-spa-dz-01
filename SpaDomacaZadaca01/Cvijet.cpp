#include "Cvijet.h"
#include <cmath>

using namespace std;
using namespace sf;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	frameClock.restart();
	float r_sunca = 40.0f;
	float x_sunca = 0.0f;
	float y_sunca = 25.0f;

	float r_latice = 20.0f;
	float x_latice = 200.0f;
	float y_latice = 200.0f;

	float r_kruga = 60.0f;

	double omjer = (0.92 + (r_latice / r_kruga));

	float x_krug = x_latice / omjer;
	float y_krug = y_latice / omjer;

	float x_stabljike = x_latice + 10;
	float y_stabljike = y_latice;

	stabljika.setPosition(Vector2f(x_stabljike, y_stabljike));
	stabljika.setSize(Vector2f(20.0f, 400.0f));
	stabljika.setFillColor(Color::Green);

	desni_list.setPointCount(5);
	desni_list.setPoint(0, Vector2f(x_stabljike, (y_stabljike + 200)));
	desni_list.setPoint(1, Vector2f((x_stabljike + 100), (y_stabljike + 110)));
	desni_list.setPoint(2, Vector2f((x_stabljike + 180), (y_stabljike + 130)));
	desni_list.setPoint(3, Vector2f((x_stabljike + 120), (y_stabljike + 180)));
	desni_list.setPoint(4, Vector2f(x_stabljike, (y_stabljike + 200)));
	desni_list.setFillColor(Color::Green);

	lijevi_list.setPointCount(5);
	lijevi_list.setPoint(0, Vector2f(x_stabljike, (y_stabljike + 300)));
	lijevi_list.setPoint(1, Vector2f((x_stabljike - 120), (y_stabljike + 280)));
	lijevi_list.setPoint(2, Vector2f((x_stabljike - 160), (y_stabljike + 230)));
	lijevi_list.setPoint(3, Vector2f((x_stabljike - 100), (y_stabljike + 210)));
	lijevi_list.setPoint(4, Vector2f(x_stabljike, (y_stabljike + 290)));
	lijevi_list.setFillColor(Color::Green);

	krug.setRadius(r_kruga);
	krug.setOutlineColor(Color::Green);
	krug.setFillColor(Color::Yellow);
	krug.setOutlineThickness(2);
	krug.setPosition(x_krug, y_krug);

	int pozicija_sunca = 0;
	do
	{
		window->clear();
		window->draw(stabljika);
		window->draw(desni_list);
		window->draw(lijevi_list);
		window->draw(krug);
		int broj_latica = 12;
		int i = 1;
		do
		{
			float razmak = 2 * 3.14 / broj_latica;
			latica.setRadius(r_latice);
			latica.setFillColor(Color::Red);
			latica.setPosition(x_latice, y_latice);
			latica.setOrigin((r_latice + r_kruga) * sin(i * razmak), (r_latice + r_kruga) * cos(i * razmak));
			latica.setOutlineColor(Color::Green);
			latica.setOutlineThickness(2);
			window->draw(latica);
			i++;
		} while (i <= broj_latica);
		window->draw(sunce);
		window->display();
		sunce.setPosition((x_sunca + pozicija_sunca), y_sunca);
		sunce.setRadius(r_sunca);
		sunce.setFillColor(Color::Yellow);
		sunce.setOutlineThickness(1);
		sunce.setOutlineColor(Color::Red);
		window->draw(sunce);
		Time t = frameClock.getElapsedTime();
		if (t.asSeconds() > 0.01)
		{
			pozicija_sunca++;
		}
	} while (pozicija_sunca < 850);
}
