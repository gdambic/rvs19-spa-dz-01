#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window; //only member variable needed to run the program
public:
	Cvijet(sf::RenderWindow* window);  //constructor
	void draw(); //main function
};