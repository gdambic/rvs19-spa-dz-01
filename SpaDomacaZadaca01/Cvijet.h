#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
class Cvijet
{
private: 
	sf::CircleShape shape;
	sf::RectangleShape line;
	sf::ConvexShape convex;
	sf::RectangleShape ground;
	
	
	

public: 
	Cvijet(sf::RenderWindow *window);

	void draw(sf::RenderWindow &window);
		
	
};

