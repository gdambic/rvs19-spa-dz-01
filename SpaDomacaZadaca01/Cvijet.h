#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw() const;




private:
	sf::RenderWindow* window;
	sf::Clock clock;



};

