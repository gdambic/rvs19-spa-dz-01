#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <cmath>


// Private Functions
 
void Cvijet::updateHeads()
{
	if (this->time % 9  == 0)
	{
		for (auto& h : this->heads)
		{
			h.setFillColor(sf::Color(255, rand() % 100, rand() % 255));
		}
	}

	for (int i = 0; i < 2000; i++)
	{
			if (time < 250)
			{
				stem1Complete[i].position += sf::Vector2f(sin(i) / 50, cos(i) / 50);
			}
			else if (time > 500)
			{
				this->time = 0;
			}
			else
			{
				stem1Complete[i].position -= sf::Vector2f(sin(i) / 50, cos(i) / 50);
			}
				
	}
	if (this->time % 9 == 0)
	{

		list.setFillColor(sf::Color(0.f, 100 + (rand() % 155), 0.f));

	}
	this->time += 1;
}

void Cvijet::initList()
{
	list.setOutlineColor(sf::Color(0.f, 200.f, 50.f));
	list.setOutlineThickness(12.f);
	list.setFillColor(sf::Color(0.f, 255.f, 0.f));
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(198.f, 425.f));
	list.setPoint(1, sf::Vector2f(300.f, 400.f));
	list.setPoint(2, sf::Vector2f(400.f, 425.f));
	list.setPoint(3, sf::Vector2f(300.f, 475.f));
}

void Cvijet::initStem1Complete()
{
	stem1Complete.setPrimitiveType(sf::Quads);
	stem1Complete.resize(1000);

	for (float i = 0.f; i <= 1000.f; i += 0.5f)
	{
		stem1Complete.append(sf::Vertex(sf::Vector2f(-sin(i) * 15 + 440, i + 150 )));
	}

	for (int i = 0; i < 2000; i++)
	{
		stem1Complete[i].color = sf::Color::Green;
	}
}

void Cvijet::initVariables()
{
	//set circle position
	double a = 0;

	for (int i = 0; i < 30; i++)
	{
		a += 12;
		this->angle[i] = a;
	}

	
}

void Cvijet::initHeads()
{
	for (int i = 0; i < 30; i++)
	{
		this->head.setRadius(40.f);
		this->head.setScale(sf::Vector2f(0.5f, 2.0f));
		this->head.setPosition(sf::Vector2f(420 + 50 * sin(this->angle[i] + i), 50 * cos(this->angle[i] + i + 2) - 10));
		this->head.setOutlineThickness(6.f);
		this->head.setOutlineColor(sf::Color(100, 0, 0));
		this->head.setFillColor(sf::Color(255, rand() % 100, rand() % 255));
		this->head.setPointCount(120);

		this->heads.push_back(this->head);
	}
}

//Constructor
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->initVariables();
	this->window = window;
	this->initHeads();
	this->initStem1Complete();
	this->initList();

}

//Deconstructor
Cvijet::~Cvijet()
{
	delete this->window;
}

//Functions
void Cvijet::draw()
{
	sf::Transform t1	(1.0f, 0.0f, 0.0f, 
						0.4f, 1.0f, 0.f, 
						0.0f, 0.f, 1.f);

	this->window->draw(stem1Complete);

	for (auto &h : this->heads)
	{
		this->window->draw(h, t1);
	}

	this->window->draw(list);

	

}
