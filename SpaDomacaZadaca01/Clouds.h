#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Clouds
{
public:
	Clouds();
	void set_clouds(const std::string texture);
	Sprite get_clouds_sprite();
	Sprite animate();
private:
	Texture cloudsTexture;
	Sprite cloudsSprite;
	IntRect cloudsIntRect;
	Clock cloudsClock;
};

