#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow& win;
	sf::Texture GrassTexture;
	sf::Texture ConcreteTexture;
	sf::Texture SkyTexture;
	sf::Texture SunTexture;
	sf::Texture SkateTexture;
	sf::Texture HouseTexture;
	sf::Texture FlowersTexture;
	sf::Clock frameClock;

	int skejticX = 530;
	int skejticY = 250;
	bool smjer = true;
public:
	Cvijet(sf::RenderWindow& window);
	void loadTextures();
	void draw();
};

