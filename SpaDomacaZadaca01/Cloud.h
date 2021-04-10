#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cloud
{
private:
	sf::RenderWindow* window;
	sf::Clock cloudFrameClock;
	sf::Time pastTime = cloudFrameClock.getElapsedTime();
	sf::CircleShape circle();
	
	float size;

public:
	//CONSTRUCTOR
	Cloud(sf::RenderWindow* window, float size);

	//DESTRUCTOR
	~Cloud();
    void draw();


	
};

