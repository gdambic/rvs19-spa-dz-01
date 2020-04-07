#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	void draw_petal(sf::Color boja, int cur_velicina, int br_latica,int max_velicina);
	void draw_stem(int duljina);
	int frame;
	sf::CircleShape shape;
	
public:
	Cvijet(sf::RenderWindow* win);
	void draw(); 
};

