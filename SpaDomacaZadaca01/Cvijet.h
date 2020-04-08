#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	
private:
	
	sf::Clock frameClock;
	sf::RenderWindow* window;
	std::vector <sf::CircleShape> dijelovi;
	sf::RectangleShape stem;
	sf::ConvexShape leaf;
	
	float duration;
	int direction;
	int increase;
	int a;
	int b;
	int c;
	sf::Color boja;		
};