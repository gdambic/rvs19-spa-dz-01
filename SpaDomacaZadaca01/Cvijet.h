#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	// Outer circle position
	float x, y;
	float sizeOuter, sizeInner;
	float leafWidth, leafHeight;

	sf::RenderWindow* window;
	sf::CircleShape innerCircle, outerCircle;
	sf::RectangleShape stem;
	sf::ConvexShape leaf;

	sf::Color plantColor, innerFlowerColor, outerFlowerColor;

	void createInnerCircle();
	void createOuterCircle();

	void createStem();
	void createLeaf();
public:
	Cvijet(sf::RenderWindow* window);
	void draw();

	void setPosition(float x, float y);
	void setSize(float size);
	void setLeafSize(float width, float height);
	void setLeafPosition(float xl, float yl);
};

