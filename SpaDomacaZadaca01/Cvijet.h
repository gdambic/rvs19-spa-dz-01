#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Color color;
	bool firstChange;
	bool returnToBlue;
	sf::Color secondcolor;
	bool secondChange;
	bool returnToRed;
	sf::Color thirdcolor;
	bool thirdChange;
	bool returnToMagenta;
	

public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

