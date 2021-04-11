#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	float povecanje = 1;
	float granica, radijus;

	sf::RenderWindow* window;
	sf::CircleShape sunce;
	sf::CircleShape tucak;
	sf::RectangleShape stabiljka;
	sf::ConvexShape list;

	void animacija();
	void set_pozicija_lista(const float sirina, const float visina);
	void set_pozicija_stabiljke(const float sirina);
public:
	Cvijet(sf::RenderWindow* window);
	void set_radijus_tucka(const float radijus);
	void set_pozicija_tucka(const float radijus, const float x, const float y);
	void set_dimenzija_stabiljke(const float sirina, const float visina);
	void set_radijus_sunca(const float radijus);
	void set_pozicija_sunca(const float x, const float y);
	void draw();
};