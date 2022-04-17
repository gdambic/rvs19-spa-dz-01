#pragma once
#include <sfml/Graphics.hpp>
using namespace sf;

class Cvijet
{
public:

	Cvijet(sf::RenderWindow* window);
	
	void draw_krug(sf::CircleShape krug);
	void draw_sunce(sf::CircleShape sunce);
	void draw_stabljika(sf::RectangleShape stabljika);

		/*
	void draw(sf::RenderWindow& window) {
		window.draw(cvijet);
	}*/
private:
	
	sf::CircleShape krug;
	sf::CircleShape sunce;
	sf::RectangleShape stabljika;

};

