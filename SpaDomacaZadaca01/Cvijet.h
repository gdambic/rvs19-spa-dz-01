#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* adresa);
	void draw();
	

	

private:

	sf::RenderWindow* adresa;

	sf::RectangleShape nebo;
	sf::Texture neboTexture;
	sf::RectangleShape livada;
	sf::Texture livadaTexture;
	sf::RectangleShape stabljika;
	sf::RectangleShape stabljika1;
	sf::CircleShape cvijetic;
	sf::Texture cvijeticTexture;
	sf::CircleShape cvijetic1;
	sf::Texture cvijetic1Texture;




};