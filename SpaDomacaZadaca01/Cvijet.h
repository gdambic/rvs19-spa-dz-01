#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw();


private:
	sf::RenderWindow *windows;
	sf::Time vrijeme;
	sf::Time vrijeme2 = sf::seconds(2.0f);
	sf::Time vrijeme3 = sf::seconds(4.0f);
	sf::Time vrijemekraja = sf::seconds(0.0f);
	sf::Clock clock;

};

