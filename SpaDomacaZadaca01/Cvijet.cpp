#include "Cvijet.h"
#include<iostream>
#include<sstream>

Cvijet::Cvijet(sf::RenderWindow& window, float size, sf::Vector2f pos)
	: classWindow(window),
	headSize(size * 2.4f, size * 2.2f),
	bodySize(size * 2.4f, size * 3.3f)
{
	head.setSize(headSize);
	body.setSize(bodySize);

	head.setOrigin(head.getSize().x / 2, head.getSize().y / 2);
	body.setOrigin(body.getSize().x / 2, 0.0f);

	head.setPosition(pos);
	body.setPosition(pos);

	if (!headTexture.loadFromFile(defaultHeadTexture) || !bodyTexture.loadFromFile(defaultBodyTexture))
	{
		std::stringstream ss;
		ss << "ERROR: " << defaultHeadTexture << " OR " << defaultBodyTexture << " FAILED TO LOAD";
		throw std::exception(ss.str().c_str());
	}
	head.setTexture(&headTexture);
	body.setTexture(&bodyTexture);
}

void Cvijet::set_angleStep(float angleStep)
{
	this->angleStep = angleStep;
}

void Cvijet::set_textures(std::string headFileName, std::string bodyFileName)
{
	if (!headTexture.loadFromFile(headFileName) || !bodyTexture.loadFromFile(bodyFileName))
	{
		std::stringstream ss;
		ss << "ERROR: " << headFileName << " OR " << bodyFileName << " FAILED TO LOAD";
		throw std::exception(ss.str().c_str());
	}
	head.setTexture(&headTexture);
	body.setTexture(&bodyTexture);
}

void Cvijet::draw(float deltaTime, float& speed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		speed += 3.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		speed -= 3.0f;

	float angle = angleStep * deltaTime * speed;

	head.rotate(angle);

	classWindow.draw(body);
	classWindow.draw(head);
}