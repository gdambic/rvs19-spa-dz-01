#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
using namespace sf;

class Cvijet
{	
private:
	RenderWindow* prozor;
	ConvexShape latice1;
	ConvexShape latice2;
	RectangleShape stabiljka;
	CircleShape sjemenka;
	RectangleShape trava;
	RectangleShape pozadina;
	Sprite lopta;
	Texture slika_lopte;
	Clock sat;
	int visina_lopte = 424;
	bool provjera_visine = false;
public:
	Cvijet(RenderWindow* prozor);
	Cvijet();
	void latice1_setup();
	void latice2_setup();
	void stabiljka_setup();
	void sjemenka_setup();
	void trava_setup();
	void pozadina_setup();
	void draw();
};

