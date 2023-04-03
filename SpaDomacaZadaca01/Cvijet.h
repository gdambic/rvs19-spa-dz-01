#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow& _window;
	sf::Clock _clock;
public:
	Cvijet(sf::RenderWindow& window);
	
	sf::CircleShape colorChange(sf::CircleShape&);
	void drawFlower();
	void drawStem();
	void drawLeaf();
	void drawSun();
	void draw();
};
