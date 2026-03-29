#pragma once
#include <SFML/Graphics.hpp>


class Petal
{

public:

	Petal();
	void set_position(float x, float y);
	void set_rotation(float r);
	void draw(sf::RenderWindow& window);
		
private:

	sf::ConvexShape one_petal;


};

