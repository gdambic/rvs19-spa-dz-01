#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

//Prozor 800x600

class Cvijet
{
private:
	sf::CircleShape pupoljak;
	sf::CircleShape sunce;
	sf::CircleShape sjemenka;
	sf::CircleShape list[2];
	sf::RectangleShape stabijka;
	sf::RectangleShape livada;
public:
	Cvijet(sf::RenderWindow* window);

	void set_pupoljak();
	void set_sjemenka();
	void set_list();
	void set_stabiljka();
	void set_livada();
	void set_sunce();

	void draw(sf::RenderWindow* window);
};

