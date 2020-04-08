#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::CircleShape krug;
	sf::ConvexShape list;
	sf::RectangleShape stabljika;
	sf::RectangleShape tlo;
	sf::Clock clock;



public:
	Cvijet(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	

};

