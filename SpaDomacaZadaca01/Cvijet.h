#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::CircleShape krug;
	sf::RenderWindow window;


public:
	Cvijet(); //sf::RenderWindow& window
	void draw(sf::RenderWindow& window);
};

