#include "Flower.h"
#include <iostream>
Flower::Flower(sf::RenderWindow* window)
{
	this->window = window;
	this->width = window->getSize().x;
	this->height = window->getSize().y;
	this->clock = clock;
}

void Flower::getInsideDraw(sf::CircleShape *shape, int xPosition, int yPosition, int thickness, float scale)
{
	
	shape->setOrigin(shape->getRadius() , shape->getRadius());

	shape->setPosition(sf::Vector2f(xPosition, yPosition));
	

	
	shape->setOutlineThickness(thickness);
	shape->setOutlineColor(sf::Color(250, 0, 0));
	if (1.f / 6.f > scale)
	{
		shape->setFillColor(sf::Color(255, scale * 255.f / (1.f / 6.f), 0));
	}
	else if (2.f / 6.f > scale)
	{
		shape->setFillColor(sf::Color(255 - (scale-1.f/6.f) * 255.f / (1.f / 6.f), 255 , 0));
	}
	else if (3.f / 6.f > scale)
	{
		shape->setFillColor(sf::Color(0, 255,(scale - 2.f / 6.f) * 255.f / (1.f / 6.f)));
	}
	else if (4.f / 6.f > scale)
	{
		shape->setFillColor(sf::Color(0, 255 - (scale - 3.f / 6.f) * 255.f / (1.f / 6.f), 255));
	}
	else if (5.f / 6.f >= scale)
	{
		shape->setFillColor(sf::Color((scale - 4.f / 6.f) * 255.f / (1.f / 6.f), 0, 255));
	}
	else
	{
		shape->setFillColor(sf::Color(255, 0, 255 - (scale - 5.f / 6.f) * 255.f / (1.f / 6.f)));
	}

	
	
	
}


void Flower::ConfigureStem(sf::RectangleShape* shape, int xPosition, int yPosition)
{
	shape->setOrigin(shape->getSize().x / 2 , shape->getOrigin().y / 2);
	
	shape->setPosition(sf::Vector2f(xPosition, yPosition));
	
	shape->setFillColor(sf::Color(0, 255, 0));

}


void Flower::ConfigureLeaf(sf::ConvexShape* shape, int xPosition, int yPosition)
{
	shape->setPointCount(4);
	shape->setPoint(0, sf::Vector2f(0, height/15));
	shape->setPoint(1, sf::Vector2f(width/5.3f, height / 60));
	shape->setPoint(2, sf::Vector2f(width/3.2f, height / 12));
	shape->setPoint(3, sf::Vector2f(width / 10, height / 6));

	shape->setFillColor(sf::Color(0,255,0));

	shape->setPosition(xPosition, yPosition);

}

void Flower::draw()
{
	sf::Time t1 = clock.getElapsedTime();
	float scale;
	if (t1.asMilliseconds() > sf::milliseconds(1020).asMilliseconds() )
	{
		
		scale = 0;
		clock.restart();
	}
	else
	{
		scale = t1.asMilliseconds() / 1020.f;
	}

	
	
	
	// draw middle of the flower
	int thickness = width/40;
	sf::CircleShape CenterFlower(width/13.3);
	getInsideDraw(&CenterFlower, width*0.2,height*0.4, thickness, scale);
	

	

	sf::RectangleShape StemFlower(sf::Vector2f(width*0.03, height * 0.4));
	ConfigureStem(&StemFlower, width * 0.2, height * 0.4 + CenterFlower.getRadius() + thickness);
	

	sf::ConvexShape LeafFlower;
	ConfigureLeaf(&LeafFlower, width * 0.2, height * 0.4 + CenterFlower.getRadius() + thickness);

	window->draw(CenterFlower);
	window->draw(StemFlower);
	window->draw(LeafFlower);
	sf::Time time1 = clock.getElapsedTime();

	
	
}