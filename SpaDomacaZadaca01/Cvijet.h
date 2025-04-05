#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	bool movingRight = true;
	float moveDistance = 2.f;
	float timePassed = 0.f;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

