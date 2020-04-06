#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\System\Clock.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
private:
	sf::RenderWindow* moj_window;
	sf::Clock frameClock;
};

