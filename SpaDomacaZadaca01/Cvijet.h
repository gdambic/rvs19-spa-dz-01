#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Color sredinaColor;
	sf::Color laticeColor;
	sf::Color sunceColor;
	sf::Color stabljikaColor;
	sf::VertexArray zrake_sunca;
	sf::CircleShape sunce;
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
	void setColor(const int dio, const sf::Color &rgb_boja);
	void update(float deltatime);
};

