#include <iostream>
#include "Cvijet.h"

using namespace sf;

Cvijet::Cvijet(RenderWindow *window) : renderWindow(window)
{
	setSky("assets/sky.jpg");
	setFlower("assets/flower.png");
	setButterfly("assets/butterfly.png");
	setGrass("assets/grass.png");
	setSun("assets/sun.png");
}


void Cvijet::draw()
{
	animateSky();
	animateFlower();
	animateButterfly();
	animateGrass();
	animateSun();
}

void Cvijet::setSky(const std::string skyTexture)
{
	textureSky.loadFromFile(skyTexture);
	spriteSky.setTexture(textureSky);
	spriteSky.setTextureRect(IntRect(0, 0, 800, 600));
	spriteSky.setPosition(0, 0);
}

void Cvijet::animateSky()
{
	renderWindow->draw(spriteSky);
}

void Cvijet::setGrass(const std::string grassTexture)
{
	textureGrass.loadFromFile(grassTexture);
	spriteGrass.setTexture(textureGrass);
	spriteGrass.setTextureRect(IntRect(0, 0, 800, 200));
	spriteGrass.setPosition(0, 400);
}

void Cvijet::animateGrass()
{
	renderWindow->draw(spriteGrass);

}

void Cvijet::setFlower(const std::string flowerTexture)
{
	textureFlower.loadFromFile(flowerTexture);
	spriteFlower.setTexture(textureFlower);
	spriteFlower.setTextureRect(IntRect(0, 0, 220, 368));
	spriteFlower.setPosition(300, 200);
}

void Cvijet::animateFlower()
{
	renderWindow->draw(spriteFlower);
}

void Cvijet::setButterfly(const std::string butterflyTexture)
{
	textureButterfly.loadFromFile(butterflyTexture);
	spriteButterfly.setTexture(textureButterfly);
	rectSpriteButterfly = IntRect(0, 0, 120, 100);
	spriteButterfly.setTextureRect(rectSpriteButterfly);
	spriteButterfly.setPosition(340, 240);
}

void Cvijet::animateButterfly()
{
	if (butterflyClock.getElapsedTime().asMilliseconds() > 100) {
		if (rectSpriteButterfly.top == 300)
			rectSpriteButterfly.top = 0;
		else
			rectSpriteButterfly.top += 100;

		spriteButterfly.setTextureRect(rectSpriteButterfly);
		butterflyClock.restart();
	}

	renderWindow->draw(spriteButterfly);
}

void Cvijet::setSun(const std::string sunTexture)
{
	textureSun.loadFromFile(sunTexture);
	spriteSun.setTexture(textureSun);
	spriteSun.setTextureRect(IntRect(0, 0, 225, 225));
	spriteSun.setPosition(-100, -100);
}

void Cvijet::animateSun()
{
	renderWindow->draw(spriteSun);
}
