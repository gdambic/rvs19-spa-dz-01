#pragma once
#include <SFML/Graphics.hpp>

class Flower
{
private:
	sf::RenderWindow* window; 

public: 
	Flower (sf::RenderWindow* window);
	void draw(); 
	
};
