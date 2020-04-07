#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *prozor);
	void draw();


private:
	sf::RenderWindow *window;
	
};

