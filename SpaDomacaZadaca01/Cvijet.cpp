#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::Print() 
{
	window->draw(petal[number[0]]);
	window->draw(petal[number[1]]);
	window->draw(petal[number[2]]);
	window->draw(petal[number[3]]);
};


void Cvijet::Petal()
{
	for (int position = 0; position < 36; position++)
	{
		petal[position].setPointCount(4);
		petal[position].setPoint(3, sf::Vector2f(50.f, 0.f));
		petal[position].setPoint(2, sf::Vector2f(0.f, 0.f));
		petal[position].setPoint(1, sf::Vector2f(0.f, 50.f));
		petal[position].setPoint(0, sf::Vector2f(100.f, 100.f));
		petal[position].setOrigin(sf::Vector2f(100.f, 100.f));
		petal[position].setPosition(sf::Vector2f(400.f, 160.f));
		petal[position].setRotation(rotation);
		this->rotation += 10;
	}
	
}

void Cvijet::Petal2(sf::Color color, int position) 
{
	petal[position].setFillColor(color);
}

void Cvijet::set()
{
	Petal();

	for (int i = 0; i < 36; i+=3)
		Petal2(sf::Color(255, 0, 0, 255), i);

	for (int i = 1; i < 36; i += 3)
		Petal2(sf::Color(255, 100, 0, 255), i);

	for (int i = 2; i < 36; i += 3)
		Petal2(sf::Color(255, 0, 100, 255), i);
}

void Cvijet::higher() 
{
	if (number[3] == 36) {
		number[3] = 0;
		number[2] = 36;
		number[1] = 35;
		number[0] = 34;
	}
		
	else if (number[2] == 36) {
		number[3] = 1;
		number[2] = 0;
		number[1] = 36;
		number[0] = 35;
	}
	else if (number[1] == 36) {
		number[3] = 2;
		number[2] = 1;
		number[1] = 0;
		number[0] = 36;
	}
	else if (number[0] == 36) {
		for (int i = 0; i < 4; i++)
		{
			number[i] = i;
		}
	}
	else
	for (int i = 0; i < 4; i++)
	{
		number[i]++;
	}
}

void Cvijet::draw()
{
	stem1.setSize(sf::Vector2f(10.f, 400.f));
	stem1.setFillColor(sf::Color(0, 255, 0, 255));
	stem1.setOrigin(sf::Vector2f(5.f, 0.f));
	stem1.setPosition(sf::Vector2f(400, 160));

	circle1.setRadius(30);
	circle1.setFillColor(sf::Color(255, 255, 0, 255));
	circle1.setOrigin(circle1.getRadius(), circle1.getRadius());
	circle1.setPosition(sf::Vector2f(400, 160));
	
	sf::Time elapsed1 = Clock.getElapsedTime();
	sf::Time t1 = sf::milliseconds(500);
	
	set();

	if (elapsed1.asMilliseconds() >= i && elapsed1.asMilliseconds() <= j)
	{
		higher();
		i += 200;
		j += 200;
	}
	

	
	window->draw(stem1);
	Print();
	window->draw(circle1);
	
}
