#pragma once
#include<SFML/Graphics.hpp>

class Cvijet
{
private:

	sf::RenderWindow* window; 
	sf::Clock clock;

public:

	Cvijet(sf::RenderWindow* window, sf::Clock clock);
	void draw(); 

};

