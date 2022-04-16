#pragma once
#include<SFML/Graphics.hpp>

class Cvijet
{
private:
	void sunce();
	void cvijet();
	void stabljika();
	void list();
	sf::RenderWindow* window;
	sf::Clock clock;

public:
	Cvijet(sf::RenderWindow* window);
	void crtaj();

};

