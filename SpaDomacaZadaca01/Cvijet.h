#include "Hydrangea.h"
#pragma once

class Cvijet
{
private:
	sf::RenderWindow* window;

	std::vector<Hydrangea> hydrangeas;

	sf::Vector2f offset_sepal;
	sf::Color hydrangea_color;

	sf::Vector2f bottom;

	sf::Clock clock;

	float r_center;
	float global_scale;

public:	
	Cvijet(sf::RenderWindow* window, sf::Color color, sf::Vector2f pos, float r_center, float global_scale);

	sf::Color get_color() const;

	void set_color(const sf::Color color);

	sf::Vector2f get_offset_sepal() const;
	float get_r_center() const;

	void init_hydrangeas(std::vector<Hydrangea>* hydrangeas);
	void draw();
};

