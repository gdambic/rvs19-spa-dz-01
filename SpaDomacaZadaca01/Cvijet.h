#pragma once
#include <SFML/Graphics.hpp>


class Cvijet {
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void cvijet();
	void travnjak();
	void mjesec();

private:
	sf::RenderWindow* window;

};

