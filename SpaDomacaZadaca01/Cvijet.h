#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window; //pokazivac na window

	//oblici cvijeta0-6
	sf::RectangleShape flower_piece0; //trava
	sf::RectangleShape flower_piece1; //korijen
	sf::ConvexShape flower_piece2; //list
	sf::CircleShape flower_piece3; //latice
	sf::CircleShape flower_piece4; //tucak

	sf::CircleShape flower_piece5; //sunce

	sf::Clock clock; //sat

public:
	Cvijet(sf::RenderWindow* window); //pokazivac za prozor
	void update_flower(); //izracun
	void create_flower(); //napravi cvijet
	void draw_flower(); //crtaj cvijet
};