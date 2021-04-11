#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Cvijet
{
private:
	sf::RenderWindow* mWindow;
public:
	Cvijet(sf::RenderWindow* mWindow);
	void draw();
	//	Animacija
	void animacija();
};

