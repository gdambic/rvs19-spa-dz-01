#pragma once
#include <SFML/Graphics.hpp>	
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window;
	float vrijemeCiklusa = 2.0f;
	float minimalniRadijus = 15.f;
	float maksimalniRadijus = 20.f;
	sf::Clock frameClock;

public:

	Cvijet(sf::RenderWindow* window);
	void draw();
	


};

