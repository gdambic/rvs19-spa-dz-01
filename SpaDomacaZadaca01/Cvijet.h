#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	 sf::RenderWindow* window;
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
	int gen_rnd(int min, int max);
	sf::Color boja();
	

	

	

};

