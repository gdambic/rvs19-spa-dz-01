#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:

	void pozicijaStabiljka(float x, float y);

	sf::RenderWindow* window;
	sf::CircleShape sunce;
	sf::CircleShape cvijet;
	sf::RectangleShape stabiljka;
	sf::ConvexShape listic;

public:

	Cvijet(sf::RenderWindow* window);
	void draw();
	void RadiusSunca(float radius);
	void RadiusCvijeta(float radius);
	void pozicijaSunca(float x, float y);
	void pozicijaCvijeta(float x, float y);
	void dimenzijeStabiljka(float x, float y);
	void dimenzijeListica(float x, float y);
};

