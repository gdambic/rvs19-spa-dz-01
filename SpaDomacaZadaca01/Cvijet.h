#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Cvijet
{

private:
	
	
	//Varijable - oblici
	sf::CircleShape sredina;
	sf::CircleShape latice[8];
	sf::RectangleShape grancica;
	sf::ConvexShape list1;
	sf::ConvexShape list2;
	sf::RenderWindow* window;
	
	//Varijable za animaciju
	sf::Clock clock;
	sf::Time time;
	float x_upper_limit = 425.f;
	float x_lower_limit = -425.f;
	float y_upper_limit = 300.f;
	float y_lower_limit = -275.f;
	float x = 0.f;
	float y = 0.f;
	float pps_x = 100.f;
	float pps_y = 100.f;
	float angle = 1.5f;

public:

	//Konstruktor
	Cvijet(sf::RenderWindow* window);

	//Draw metoda
	void draw();

	//Setteri
	void set_all_position(const float x, const float y);
	void set_sredina(const float x, const float y);
	void set_latice(const float x, const float y);
	void set_grancica(const float x, const float y);
	void set_list1(const float x, const float y);
	void set_list2(const float x, const float y);
};

