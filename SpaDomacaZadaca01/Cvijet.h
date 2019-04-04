#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Cvijet
{
private:
	sf::RenderWindow *window_class;

public:
	Cvijet(sf::RenderWindow *window);
	void draw();
};

