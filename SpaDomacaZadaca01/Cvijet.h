#include <SFML/Graphics.hpp>

#pragma once
class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw(sf::RenderWindow& window);
private:
	void scale_leaf(sf::ConvexShape& leaf, float scaleFactor);
	void set_point_leaf(sf::ConvexShape& leaf);
	void set_leaf(sf::ConvexShape& leaf, sf::Color color, float x, float y, float angle, float scaleFactor);

};

