#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class Cvijet
{
private:
	sf::RenderWindow *window; // pointer to window
	sf::CircleShape flower, sun; // flower
	sf::CircleShape pet1, pet2, pet3, pet4; // peteljke
	sf::CircleShape *pet1p, *pet2p, *pet3p, *pet4p; // pointeri na peteljke
	sf::RectangleShape line; // line
	sf::ConvexShape convex; // leaf
	double sun_x, sun_y, flower_x, flower_y, pet1_x, pet1_y, pet2_x, pet2_y, pet3_x, pet3_y, pet4_x, pet4_y, line_x, line_y, convex_x, convex_y; // coordinates
public:
	Cvijet(sf::RenderWindow* window);
	void update_screen();
	void draw_flower();
	void draw_sun();
	void draw_leaf();
	void animate_sun();
	void animate_leaf();
	void animate_petals(sf::CircleShape* pet1p, sf::CircleShape* pet2p, sf::CircleShape* pet3p, sf::CircleShape* pet4p);
	void set_sun_x(const double sun_x);
	void set_sun_y(const double sun_y);
	double get_sun_x() const;
	double get_sun_y() const;
	void set_flower_x(const double flower_x);
	void set_flower_y(const double flower_y);
	double get_flower_x() const;
	double get_flower_y() const;

	void set_pet1_x(const double pet1_x);
	void set_pet1_y(const double pet1_y);
	double get_pet1_x() const;
	double get_pet1_y() const;
	void set_pet2_x(const double pet2_x);
	void set_pet2_y(const double pet2_y);
	double get_pet2_x() const;
	double get_pet2_y() const;
	void set_pet3_x(const double pet3_x);
	void set_pet3_y(const double pet3_y);
	double get_pet3_x() const;
	double get_pet3_y() const;
	void set_pet4_x(const double pet4_x);
	void set_pet4_y(const double pet4_y);
	double get_pet4_x() const;
	double get_pet4_y() const;

	void set_line_x(const double line_x);
	void set_line_y(const double line_y);
	double get_line_x() const;
	double get_line_y() const;
	void set_convex_x(const double convex_x);
	void set_convex_y(const double convex_y);
	double get_convex_x() const;
	double get_convex_y() const;

	sf::CircleShape* get_pet1p();
	sf::CircleShape* get_pet2p();
	sf::CircleShape* get_pet3p();
	sf::CircleShape* get_pet4p();
};

