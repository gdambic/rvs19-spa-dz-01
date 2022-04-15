#pragma once
#include <SFML/Graphics.hpp>
class Flower
{
private:
	sf::RenderWindow *window;
	int width = 0;
	int height = 0;
	sf::Clock clock;
public:
	Flower(sf::RenderWindow *windows);
	void getInsideDraw(sf::CircleShape* shape, int xPosition, int yPosition, int thickness, float scale);
	void ConfigureStem(sf::RectangleShape* shape, int xPosition, int yPosition);
	void ConfigureLeaf(sf::ConvexShape* shape, int xPosition, int yPosition);
	void draw();
};

