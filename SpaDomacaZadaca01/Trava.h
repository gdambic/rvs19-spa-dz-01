#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Trava
{
public:

	Trava(sf::RenderWindow* window);

	void draw();

	//Trava
	sf::RectangleShape get_trava()const;
	void set_trava(const sf::RectangleShape trava);

private:

	sf::RectangleShape trava;
	sf::RenderWindow* window;
};

