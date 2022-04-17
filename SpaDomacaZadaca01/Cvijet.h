#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape stabljika; 
	sf::CircleShape unutarnji;
	sf::CircleShape vanjski;
	sf::CircleShape sunce;
	sf::ConvexShape list;
	sf::Clock clock;
	float sunceX = 10;
	float sunceRadius = 10;
	bool animacijaCheck = 0;
	bool radiusCheck = 0;
public:
	Cvijet(sf::RenderWindow* window);
	void stabljika_setup();
	void unutarnji_setup();
	void vanjski_setup();
	void list_setup();
	void draw();
};

