#include "Butterfly.h"

Butterfly::Butterfly()
{
    // default constructor
}

void Butterfly::set_butterfly(const std::string texture)
{
	butterflyTexture.loadFromFile(texture);
	butterflySprite.setTexture(butterflyTexture);
	butterflyIntRect = IntRect(0, 0, 120, 100);
	butterflySprite.setTextureRect(butterflyIntRect);
	butterflySprite.setPosition(340, 240);
}

Sprite Butterfly::get_butterfly_sprite()
{
    return butterflySprite;
}

Sprite Butterfly::animate()
{
	if (butterflyClock.getElapsedTime().asMilliseconds() > 100) {
		if (butterflyIntRect.top == 300)
			butterflyIntRect.top = 0;
		else
			butterflyIntRect.top += 100;

		butterflySprite.setTextureRect(butterflyIntRect);
		butterflyClock.restart();
	}

	return get_butterfly_sprite();
}
