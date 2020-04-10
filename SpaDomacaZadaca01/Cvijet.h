#pragma once
#include<SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void desno();
	void lijevo();
	void kordinate();
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
	int pomakSunce = 0;
	int pomakCvijet = 0;
};

