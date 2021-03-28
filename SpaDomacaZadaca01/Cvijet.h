#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow *window);

	void draw();

private:
	RenderWindow *renderWindow;
	Texture textureGrass;
	Sprite spriteGrass;
	IntRect rectSpriteGrass;
	Texture textureSky;
	Sprite spriteSky;
	Texture textureFlower;
	Sprite spriteFlower;
	Texture textureButterfly;
	Sprite spriteButterfly;
	IntRect rectSpriteButterfly;
	Clock butterflyClock;
	Texture textureSun;
	Sprite spriteSun;
	IntRect rectSpriteSun;

	void setSky(const std::string skyTexture);
	void animateSky();
	void setGrass(const std::string grassTexture);
	void animateGrass();
	void setFlower(const std::string flowerTexture);
	void animateFlower();
	void setButterfly(const std::string butterflyTexture);
	void animateButterfly();
	void setSun(const std::string sunTexture);
	void animateSun();
};