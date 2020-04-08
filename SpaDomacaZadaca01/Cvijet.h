#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* konzola);
	void draw();
private:

	sf::RenderWindow *konzola;
	std::vector<sf::CircleShape> dijelovi;
};

