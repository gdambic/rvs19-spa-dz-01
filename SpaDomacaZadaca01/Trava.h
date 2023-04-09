#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class Trava
{
private:
	sf::RenderWindow* window;
	float height;//visina
	float rotation[800];
	float target_Rotation[800];
	sf::Color color[800];//treba pazit

public:
	Trava(sf::RenderWindow* window);
	void draw();
};



