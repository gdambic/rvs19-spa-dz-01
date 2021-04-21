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
	body.setOrigin(body.getSize().x / 2, body.getSize().y);

	body.setPosition(pos);
	head.setPosition(pos);

	head.move(0.0f, -(body.getSize().y));

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

void Cvijet::set_tiltOffstet(float angle)
{
	this->totalAngle = angle;
}

void Cvijet::draw(float deltaTime, float& speed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		speed += 3.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		speed -= 3.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		tiltSpeed += 3.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		tiltSpeed -= 3.0f;

	float angle = angleStep * deltaTime * speed;

	head.rotate(angle);

	if(totalAngle >= 10.0f)
		toRight = false;
	if(totalAngle <= -10.0f)
		toRight = true;
	if(toRight)
		totalAngle = totalAngle + 0.1f * tiltSpeed * deltaTime;
	if(!toRight)
		totalAngle = totalAngle + 0.1f * tiltSpeed * deltaTime * (-1.0f);
	
	sf::Transform bodyMove;
	bodyMove.rotate(totalAngle, body.getPosition());
	
	classWindow.draw(body, bodyMove);
	classWindow.draw(head, bodyMove);
}