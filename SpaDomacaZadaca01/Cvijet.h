#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window_;
	sf::Clock frameClock_;
	int currentColorIndex_;
public:
	Cvijet(sf::RenderWindow* window) : window_(window), currentColorIndex_(0) {}
	void draw();
  
};
