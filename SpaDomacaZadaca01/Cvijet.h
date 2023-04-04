#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::CircleShape petals;
	sf::RectangleShape stem;
	sf::ConvexShape leaf;
	sf::RectangleShape grass;

	void initPetals(sf::RenderWindow* window);
	void initStem(sf::RenderWindow* window);
	void initLeaf(sf::RenderWindow* window);
	void initGrass(sf::RenderWindow* window);
	void initFlower(sf::RenderWindow* window);

	sf::Clock timer;
	float AverageScale;
	float ScaleVariance;
	float OscilationFrequency;
	float CosFactor;
	sf::CircleShape sun;

	void initAnimation(sf::RenderWindow* window);
public:
	Cvijet(sf::RenderWindow* window);
	void updateFlower(sf::RenderWindow* window);
	void setAnimation(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
};
