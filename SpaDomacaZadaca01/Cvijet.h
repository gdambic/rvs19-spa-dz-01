#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
//
class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	~Cvijet();
	void draw();
private:
	sf::RenderWindow *window;
	std::vector<sf::Shape*> shapes;
	void init_shapes();
	sf::Clock frameClock;
};

