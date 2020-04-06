#ifndef ENTITY_H
#define ENTITY_H


#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

class Entity
{


protected:
	sf::RectangleShape shape;
	float movementSpeed;

private:


public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt, const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget &target);
};

#endif // !ENTITY_H

