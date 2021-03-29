#include "Grass.h"

Grass::Grass()
{
	// default constructor
}

void Grass::set_grass(const std::string texture)
{
	grassTexture.loadFromFile(texture);
	grassSprite.setTexture(grassTexture);
	grassIntRect = IntRect(0, 0, 800, 200);
	grassSprite.setTextureRect(grassIntRect);
	grassSprite.setPosition(0, 400);
}

Sprite Grass::get_grass_sprite()
{
    return grassSprite;
}
