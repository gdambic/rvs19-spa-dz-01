#pragma once
#include <SFML/Graphics.hpp>

class Kisa
{
private:
	sf::RenderWindow* window;
	std::vector<float> kapljicaSpeed;
	std::vector<sf::RectangleShape> kisa;
	float spd = 10;

public:
	Kisa(sf::RenderWindow* window);
	void draw(int noc);
};

