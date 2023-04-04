#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	
	void draw(sf::RenderWindow& window);
private:
	sf::RenderWindow* window;
	sf::Texture stem_texture;
	sf::Texture center_texture;
	sf::Texture petal_texture;
	sf::Texture leaf_texture;
	sf::Clock frameClock;
	sf::Texture grass_texture;

};

