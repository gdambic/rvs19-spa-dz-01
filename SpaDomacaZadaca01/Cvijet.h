#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::RectangleShape line;
	sf::CircleShape elipse;
	sf::CircleShape elipse2;
	sf::CircleShape elipse3;
	sf::CircleShape sun;

	float x = 0.f;
	float y = 0.f;
	

public:
	void draw();
	Cvijet(sf::RenderWindow* window);

};