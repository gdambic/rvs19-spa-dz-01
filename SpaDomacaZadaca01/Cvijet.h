#pragma once
#include<SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void vukovi();
	void cvijet();
	void mjesec();
	void livada();
	sf::Texture postavljanje(int i);
	sf::Texture raspored_slika();

private:
	sf::RenderWindow* window;
	int brojac = 0;
	int koordinataX = 0;
	sf::Texture zvjeri[18];
};

