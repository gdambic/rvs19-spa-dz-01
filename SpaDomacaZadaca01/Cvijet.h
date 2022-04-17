#pragma once 
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();

	sf::ConvexShape get_stem() const;

	void set_stem(const sf::ConvexShape stem);

	sf::CircleShape get_cvijet() const;

	void set_cvijet(const sf::CircleShape dolly);

	float get_const() const;

	void set_const(const float constant);

	sf::CircleShape get_sun() const;

	void set_sun(const sf::CircleShape sun);

private:
	sf::RenderWindow* window;
	sf::CircleShape dolly;
	sf::ConvexShape stem;
	sf::CircleShape sun;
	sf::Clock frameClock;
	float constant;
};