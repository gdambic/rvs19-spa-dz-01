#pragma once
#include <SFML/Graphics.hpp>



class Cvijet {
public:
	Cvijet(sf::RenderWindow* window);
	void draw();



private:
	sf::RenderWindow* window;
	float rotacija = 0.0f;
	float pocetni_x = 0.0f;
	float pocetni_y = 320.0f;
	static const int BR_LATICA = 5;
};