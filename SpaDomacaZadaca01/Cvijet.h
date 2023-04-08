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
	sf::Texture gynoecium_texture;
	sf::Texture petal_disk_texture;
	sf::Texture leaf_texture;
	sf::Texture grass_texture;
	sf::Texture sky_texture;
};

