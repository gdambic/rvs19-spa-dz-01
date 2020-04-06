#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Cvijet
{public:
	Cvijet(sf::RenderWindow* window);
	void draw() const;
private:
	sf::RenderWindow* window;
	sf::Clock clock;
}; 

