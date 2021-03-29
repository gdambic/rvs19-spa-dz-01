#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Sky
{
public:
	Sky();
	void set_sky(const std::string texture);
	Sprite get_sky_sprite();
private:
	Texture skyTexture;
	Sprite skySprite;
	IntRect skyIntRect;
	Clock skyClock;
};

