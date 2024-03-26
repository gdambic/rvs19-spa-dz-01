#pragma once
#include <SFML/Graphics.hpp>	
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window;
	float min_r = 15.f;
	float max_r = 20.f;
	float cycle = 5.0f;
	sf::Clock frameClock;
	


public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	
};

