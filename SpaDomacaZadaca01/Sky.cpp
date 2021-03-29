#include "Sky.h"

Sky::Sky()
{
    // default constructor
}

void Sky::set_sky(const std::string texture)
{
    skyTexture.loadFromFile(texture);
    skySprite.setTexture(skyTexture);
    skyIntRect = IntRect(0, 0, 800, 600);
    skySprite.setTextureRect(skyIntRect);
    skySprite.setPosition(0, 0);
}

Sprite Sky::get_sky_sprite()
{
    return skySprite;
}
