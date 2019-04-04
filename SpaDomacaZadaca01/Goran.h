#pragma once
#include <SFML/Graphics.hpp>
class Goran
{
private:
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::Sprite sprite;
public:
	Goran(sf::RenderWindow* window);
	void spawn();
};

