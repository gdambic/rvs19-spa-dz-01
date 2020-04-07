#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* Window);
	sf::CircleShape set_Sunce();
	sf::CircleShape set_UnutarnjiCvijet();
	sf::CircleShape set_VanjskiCvijet();
	sf::RectangleShape set_Stabljika();
	sf::ConvexShape set_List();
	sf::ConvexShape set_DrugiList();
	void draw();
	float get_radius();

private:
	sf::RenderWindow* Window;
	sf::CircleShape UnutarnjiCvijet;
	sf::CircleShape VanjskiCvijet;
	sf::RectangleShape Stabljika;
	sf::ConvexShape List;
	sf::CircleShape Sunce;
	sf::Clock vrijeme;
	float konstanta = 10;

};

