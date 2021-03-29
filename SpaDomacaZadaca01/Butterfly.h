#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Butterfly
{
public:
	Butterfly();
	void set_butterfly(const std::string texture);
	Sprite get_butterfly_sprite();
	Sprite animate();
private:
	Texture butterflyTexture;
	Sprite butterflySprite;
	IntRect butterflyIntRect;
	Clock butterflyClock;
};

