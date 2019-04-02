#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
 Cvijet(sf::RenderWindow * window);
 void flower();
 void set_shape();
 void set_color();
 void set_position();
 void draw();
 void draw_cshape(sf::CircleShape shape);
 void rotation();
private:
	float elapsed;
	sf::RenderWindow *window;
	sf::CircleShape middle;
	sf::CircleShape middlem;
	sf::CircleShape petal;
	sf::CircleShape petal2;
	sf::CircleShape petal3;
	sf::RectangleShape stem;
	sf::CircleShape leaf;
	sf::CircleShape leaf2;
	sf::Clock clock;
};

