#pragma once
#include "SFML/Graphics.hpp"


class Cvijet
{

private:

	sf::RenderWindow& prozor;
	sf::CircleShape tucak;
	sf::CircleShape latice;
	sf::RectangleShape stabljika;
	sf::ConvexShape list;
	sf::CircleShape sunce;
	void genSunce();
	void genStabljika();
	void genList();
	void genTucak();
	void genLatice();
	sf::Time vrijeme;
	sf::Clock stoperica;

public :

	Cvijet(sf::RenderWindow& window);
	void draw();
	

};

