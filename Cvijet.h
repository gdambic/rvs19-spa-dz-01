#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
class Cvijet 
{
private:
	sf::RenderWindow *window;
	sf::Clock frameClock;
public:
	Cvijet(sf::RenderWindow* window);
	void draw() const;
};

