#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void animacija();
};

