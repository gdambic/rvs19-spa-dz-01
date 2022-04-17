#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
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
public:
	Cvijet(sf::RenderWindow* window);
	Cvijet();
	void stabljika_setup();
	void unutarnji_setup();
	void vanjski_setup();
	void list_setup();
	void sunce_setup();
	void draw();
};

