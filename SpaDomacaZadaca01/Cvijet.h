#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
private:
	sf::RenderWindow *prozor;

public:
	Cvijet(sf::RenderWindow *prozor);
	~Cvijet();
	void draw();
	sf::CircleShape oblikReceptaculum();
	sf::RectangleShape oblikStabiljka();
	sf::ConvexShape oblikSepala();
};

