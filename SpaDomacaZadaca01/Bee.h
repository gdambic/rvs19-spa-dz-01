#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

class Bee : public sf::RectangleShape
{
public:
	Bee();

	void animation(sf::RenderWindow *window);

private:
	const sf::Time ANIMATION_UPDATE_INTERVAL = sf::milliseconds(100);

	sf::Texture texture;
	sf::Clock clock;
	sf::Time last_animation_update;
	bool animation_direction_to_a = true;
	int x_counter = 0;
};

