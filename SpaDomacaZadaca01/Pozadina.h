#pragma once
#include <SFML/Graphics.hpp>
class Pozadina
{
private:
	sf::RenderWindow* window;
	int i = 1;
	int j = 0;
	int k = 1022;
	int h = 0;
	int noc = 510;
	sf::Vector2f zvjezde_lokacija[100];
	sf::CircleShape zvjezde[100];

public:
	Pozadina(sf::RenderWindow* window);

	void draw();
	void drawPozadina();
	void drawZvijezde();
	int getNoc();
};

