#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	void NacrtajTucak();
	void NacrtajStabljika();
	void NacrtajLatica();
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

