#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
private:
	sf::RenderWindow* drawWindow;
	sf::CircleShape centarCvijeta;
	std::vector<sf::CircleShape> krugLatica1;
	std::vector<sf::CircleShape> krugLatica2;
	sf::RectangleShape stabljika;
	sf::ConvexShape listic;
	sf::CircleShape sunce;
	sf::RectangleShape backgroundTrava;
	sf::RectangleShape backgroundNebo;

	float flowerCenterX;
	float flowerCenterY;
	float flowerCenterRadius;
	sf::Color flowerCenterColor;

	unsigned int petals1;
	float petal1Radius;
	sf::Color petal1Color;

	unsigned int petals2;
	float petal2Radius;
	sf::Color petal2Color;

	float stalkHeight;
	float stalkWidth;
	sf::Color stabljikaColor;

	sf::Color listicColor;

	float sunceRadius;
	sf::Color sunceColor;
	float suncePositionX = 20;
	float suncePositionY = 20;

	sf::Color travaColor;
	sf::Color neboColor;

	void centarCvijetaSet();
	void krugLatica1Set();
	void krugLatica2Set();
	void stabljikaSet();
	void listicSet();
	void sunceSet();
	void backgroundSet();

	sf::Clock clock;


public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};