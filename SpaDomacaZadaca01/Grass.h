#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Grass
{
public:
	Grass();
	void set_grass(const std::string texture);
	Sprite get_grass_sprite();
private:
	Texture grassTexture;
	Sprite grassSprite;
	IntRect grassIntRect;
	Clock grassClock;
};

