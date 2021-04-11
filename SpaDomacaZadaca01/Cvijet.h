#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape latice1;
	sf::CircleShape latice2;
	sf::CircleShape latice3;
	sf::Time animacija_trajanje;
	sf::ConvexShape stabljika;
	sf::Texture tapeta;
	float okretanje = 10.0;



public:
	Cvijet(sf::RenderWindow* window);
	void draw();


};

