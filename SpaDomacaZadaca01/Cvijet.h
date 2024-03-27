#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Cvijet
{
private:
	sf::RenderWindow* window;
	vector<sf::ConvexShape> petals; 
	sf::CircleShape circle;
	sf::CircleShape concentricCircle;
	sf::RectangleShape stem;
	
	sf::Clock frameClock;
	sf::CircleShape sun;

	 
	

public:
	Cvijet(sf::RenderWindow* window);
	void draw_flower();

};

