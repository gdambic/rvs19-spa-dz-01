#include "Flower.h"

Flower::Flower()
{
    // default constructor
}

void Flower::set_flower(const std::string texture)
{
    flowerTexture.loadFromFile(texture);
    flowerSprite.setTexture(flowerTexture);
    flowerIntRect = IntRect(0, 0, 220, 368);
    flowerSprite.setTextureRect(flowerIntRect);
    flowerSprite.setPosition(300, 200);
}

Sprite Flower::get_flower_sprite()
{
    return flowerSprite;
}
