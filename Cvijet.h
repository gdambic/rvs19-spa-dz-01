#pragma once
#include <SFML/Graphics.hpp>
using namespace std;


class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::RectangleShape line;
	sf::ConvexShape convex;
	
	


public: 
	Cvijet(sf::RenderWindow* window);
	void draw();

};

