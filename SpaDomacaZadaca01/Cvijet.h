#pragma once
#include<SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Cvijet
{
private:
	RectangleShape stabiljka;
	CircleShape glava;
	CircleShape latica;
	CircleShape listic;
public:
	Cvijet(RenderWindow &window);

	RectangleShape get_stabiljka() const;
	CircleShape get_glava() const;
	CircleShape get_latica() const;
	CircleShape get_listic() const;

	void set_stabiljka(RectangleShape stabiljka);
	void set_glava(CircleShape glava);
	void set_latica(CircleShape latica);
	void set_listic(CircleShape list);
};

