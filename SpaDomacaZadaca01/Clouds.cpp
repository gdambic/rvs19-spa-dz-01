#include "Clouds.h"
#include <iostream>

Clouds::Clouds()
{
    // default constructor
}

void Clouds::set_clouds(const std::string texture)
{
    cloudsTexture.loadFromFile(texture);
    cloudsSprite.setTexture(cloudsTexture);
    cloudsIntRect = IntRect(0, 0, 1600, 200);
    cloudsSprite.setTextureRect(cloudsIntRect);
    cloudsSprite.setPosition(-800, 0);
}

Sprite Clouds::get_clouds_sprite()
{
    return cloudsSprite;
}

Sprite Clouds::animate()
{
	if (cloudsClock.getElapsedTime().asMilliseconds() > 20) {

		if (cloudsSprite.getPosition().x == 0)
			cloudsSprite.setPosition(-800, 0);
		else
			cloudsSprite.setPosition(cloudsSprite.getPosition().x + 1, 0);


		cloudsClock.restart();
	}

	return get_clouds_sprite();
}
