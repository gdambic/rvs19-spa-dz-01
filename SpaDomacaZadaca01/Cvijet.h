#pragma once
#include <SFML/Graphics.hpp>


class cvijet
{
public:

	cvijet(sf::RenderWindow *window) :m_window(window) {};
	void draw();
	void update(sf::Clock *vrijeme);

private:


	sf::RenderWindow* m_window;
	sf::CircleShape shape;
	sf::RectangleShape line;
	sf::ConvexShape convex;
	sf::CircleShape sunce;

	void napravi_shape();
	void napravi_liniju();
	void napravi_convex();
	void napravi_sunce();
};

