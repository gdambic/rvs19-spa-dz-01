#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
	sf::Time elapsed;
	float scale = 1.f;
	float scaleSpeed = .5f;

	sf::RectangleShape sky;
	sf::RectangleShape upperLine;
	sf::RectangleShape lowerLine;
	sf::ConvexShape leaf;
	sf::CircleShape shape;
	sf::ConvexShape ground;
	sf::CircleShape sunce;
	sf::RectangleShape zraka;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void crtajNebo();
	void crtajStabljiku();
	void crtajList();
	void crtajLatice();
	void crtajShape();
	void crtajGround();
	void crtajSunce();
};

