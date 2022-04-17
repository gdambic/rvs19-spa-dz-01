#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow *window, int WIDTH, int HEIGHT)
{
	this->window = window;
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->clock = clock;
}

void Cvijet::draw(int move)
{
	int height = HEIGHT;

	sf::Texture flowerImage;
	sf::Sprite flowerSprite;

	if (!flowerImage.loadFromFile("cute-flower.png"))
	{
		throw std::exception("No image found");
	}

	flowerSprite.setScale(0.35f, 0.35f);
	flowerSprite.setOrigin(WIDTH / 2.0, HEIGHT);

	int time = clock.getElapsedTime().asMilliseconds();

	float timeElapsed = (HEIGHT / 2.0) + (time / 100);

	flowerSprite.setPosition(WIDTH / 2.0, (HEIGHT / 2.0) + move);

	flowerSprite.setTexture(flowerImage);

	window->draw(flowerSprite);
}
