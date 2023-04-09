#pragma once
#include <SFML/Graphics.hpp>

class Flower
{
private:
	sf::RenderWindow* window;
	//transparentnost shade objekta
	uint8_t darkness = 0;
	sf::CircleShape mound;
	sf::RectangleShape stem;
	sf::RectangleShape shade;
	sf::CircleShape sun;
	sf::CircleShape petal;
	sf::CircleShape flower;
	sf::CircleShape cloud;

	//funkcija koja poziva ostale seter-e
	void maker();
	void setMound();
	void setPetal();
	void setFlower();
	void setSun();
	void setStem();
	void setCloud();
	void setShade();

public:
	Flower(sf::RenderWindow &window);
	void draw();
};

