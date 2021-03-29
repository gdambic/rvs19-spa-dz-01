#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Flower
{
public:
	Flower();
	void set_flower(const std::string texture);
	Sprite get_flower_sprite();
private:
	Texture flowerTexture;
	Sprite flowerSprite;
	IntRect flowerIntRect;
	Clock flowerClock;
};

