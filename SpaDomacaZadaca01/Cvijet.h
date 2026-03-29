#pragma once
#include <SFML/Graphics.hpp>

// Ideja je da crtezi budu pixel art zbog toga ima malo vise linija koda u Cvijet.cpp :)

class Cvijet
{
private:
	sf::RenderWindow* win;
	void render(std::vector<sf::RectangleShape>* art);
public:
	Cvijet(sf::RenderWindow* pwin);
	void draw();
};

