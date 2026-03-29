#include "Petal.h"

Petal::Petal()
{

	one_petal.setPointCount(4);
	one_petal.setPoint(0, sf::Vector2f(0, 0));
	one_petal.setPoint(1, sf::Vector2f(20, 0));
	one_petal.setPoint(2, sf::Vector2f(20, 80));
	one_petal.setPoint(3, sf::Vector2f(0, 80));
	
	
}

void Petal::set_position(float x, float y)
{
	one_petal.setPosition(x, y);

}

void Petal::set_rotation(float r)
{
	one_petal.setRotation(r);
}

void Petal::draw(sf::RenderWindow& window)
{

	window.draw(one_petal);
}
