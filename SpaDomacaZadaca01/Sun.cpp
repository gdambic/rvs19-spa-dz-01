#include "Sun.h"

Sun::Sun()
{
    // default constructor
}

void Sun::set_sun(const std::string texture)
{
    sunTexture.loadFromFile(texture);
    sunSprite.setTexture(sunTexture);
    sunIntRect = IntRect(0, 0, 225, 225);
    sunSprite.setTextureRect(sunIntRect);
    sunSprite.setPosition(-100, -100);
}

Sprite Sun::get_sun_sprite()
{
    return sunSprite;
}
