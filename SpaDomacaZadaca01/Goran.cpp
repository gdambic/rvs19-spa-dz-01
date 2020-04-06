#include "Goran.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

Goran::Goran(sf::RenderWindow* window) : window{window}	{}

void Goran::spawn() {
	texture.loadFromFile("goran.png");
	sprite.setTexture(texture);
	window->draw(sprite);
}