#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* prozor);
	void set_colourtrokut();
	void set_colourstabljika();
	void set_colourlist();
	void set_pointnumbertrokut();
	void set_pointnumberlist();
	void set_radiustrokut();
	void set_radiusstabljika();
	void set_positiontrokut();
	void set_positionstabljika();
	void set_positionlist();
	void set_thicknesstrokut();
	void set_thicknessstabljika();
	void pripremi_trokut();
	void pripremi_stabljiku();
	void pripremi_list();
	void draw();
	
	


private:
	sf::RenderWindow* prozor;
	sf::CircleShape trokut;
	sf::RectangleShape stabljika;
	sf::ConvexShape list;
};

