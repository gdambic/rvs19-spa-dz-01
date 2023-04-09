#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
class Cvijet 
{
private:
	sf::RenderWindow* window;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

