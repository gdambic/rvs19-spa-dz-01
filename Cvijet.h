#pragma once
#include <SFML/Graphics.hpp>

using  namespace std;
class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw(sf::RenderWindow *window);
private:
	sf::RenderWindow *window;
};

