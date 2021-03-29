#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Sun
{
public:
	Sun();
	void set_sun(const std::string texture);
	Sprite get_sun_sprite();
private:
	Texture sunTexture;
	Sprite sunSprite;
	IntRect sunIntRect;
	Clock sunClock;
};

