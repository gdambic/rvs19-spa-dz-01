#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape flower, sun;
	sf::RectangleShape line;
	sf::ConvexShape leaf;
	double sun_x, sun_y, flower_x, flower_y, line_x, line_y, leaf_x, leaf_y;
public:
	Cvijet(sf::RenderWindow* window);
	void draw_screen();
	void animate_the_sun();
	void set_sun_x(const double sun_x);
	void set_sun_y(const double sun_y);
	double get_sun_x() const;
	double get_sun_y() const;
	void set_flower_x(const double flower_x);
	void set_flower_y(const double flower_y);
	double get_flower_x() const;
	double get_flower_y() const;
	void set_line_x(const double line_x);
	void set_line_y(const double line_y);
	double get_line_x() const;
	double get_line_y() const;
	void set_leaf_x(const double leaf_x);
	void set_leaf_y(const double leaf_y);
	double get_leaf_x() const;
	double get_leaf_y() const;
};
