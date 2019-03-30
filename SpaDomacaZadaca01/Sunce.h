#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Sunce
{
private:
	sf::RenderWindow *prozor;
	sf::Clock animacijaObjekta;
	sf::Time prosloVrijeme = animacijaObjekta.getElapsedTime();
	float velicinaKruga;

public:
	Sunce(sf::RenderWindow *prozor, float velicinaKruga);
	~Sunce();
	void draw();
	void animirajSunce();
	sf::CircleShape oblikKruga();
};

