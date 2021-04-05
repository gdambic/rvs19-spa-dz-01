#include "kisa.h"

kisa::kisa()
{
	texture.loadFromFile("kap.png");
	

}

void kisa::prozor(sf::RenderWindow* window)
{
	this->window = window;
}

sf::Sprite kisa::crtaj(int x, int y)
{
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(0.03f, 0.03f);
	sprite.setPosition(x, y);
	// Draw it
	return sprite;

}
