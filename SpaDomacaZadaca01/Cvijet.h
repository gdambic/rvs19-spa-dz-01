#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
		

private:
	sf::RenderWindow *window;
	sf::Clock frameClock;
};

