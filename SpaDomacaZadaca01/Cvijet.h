#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
private:
	sf::RenderWindow* window;
	int x;
	int y;
	sf::Color bojaLatica;
	sf::Color bojaStabljika;
	int rotacija = 0;
	double uvecanje = 0.1;
	double velicinalatice = 17.5;

	
};

