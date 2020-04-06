#include "Kisa.h"

Kisa::Kisa()
{
	this->x = rand() % 800;
	this->y = rand() % (100 - 200);
	this->z = rand() % (10 + 1);
	this->yspeed = rand() % 7;
	this->setSize(Vector2f(5, 22.55));
	this->setPosition(this->x, this->y);
	this->setFillColor(Color(0, 0, 15, 30));
}

void Kisa::pada()
{
	this->move(Vector2f(-1, this->yspeed));

	if (this->getPosition().y > 450)
	{
		this->x = rand() % 800;
		this->y = rand() % (150 - 250);
		this->z = rand() % (10 + 1);
		this->yspeed = rand() % 7;
		this->setPosition(this->x, this->y);
	}
}