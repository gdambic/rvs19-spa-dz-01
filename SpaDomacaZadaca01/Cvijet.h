#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;

	float maxRadius = 30.0;
	float minRadius = 15.0;
	float speed = 30.0;
	float currentRadius = 15.0;
	bool growing = true;

	sf::Clock frameClock;
	sf::Time elapsedTime;



public:
	Cvijet(sf::RenderWindow* window);
	void draw();

	void set_currentRadius(const float currentRadius);
	void set_growing(const bool growing);

	float get_currentRadius() const;
	bool get_growing() const;
};

