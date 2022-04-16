#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	void crtajSunce();
	void crtajCvijet();
	void crtajPeteljku();
	void crtajListu();
	sf::RenderWindow* window;
	sf::Clock clock;

public:

	Cvijet(sf::RenderWindow* window);

	void crtaj();

};

