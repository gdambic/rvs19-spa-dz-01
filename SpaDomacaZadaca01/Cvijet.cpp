#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow *window, int WIDTH, int HEIGHT)
{
	this->window = window;
	this->WIDTH = WIDTH;
	this->HEIGHT = HEIGHT;
	this->clock = clock;
}

void Cvijet::draw()
{
	sf::Texture flowerImage;
	sf::Sprite flowerSprite;

	if (!flowerImage.loadFromFile("Matej_is_cute.png"))
	{
		throw std::exception("No image detected");
	}

	flowerSprite.setScale(0.35f, 0.35f);
	flowerSprite.setOrigin(WIDTH / 2.0, HEIGHT);

	int time = clock.getElapsedTime().asMilliseconds();
	float newHeight = 0;

	float timeElapsed = (HEIGHT / 2.0) + (time / 100);

	if (time <= 5000)
	{
		flowerSprite.setPosition(WIDTH / 2.0, (HEIGHT / 2.0) + (time / 100));

		newHeight = (HEIGHT / 2.0) + (time / 100);
	}

	else
	{
		flowerSprite.setPosition(WIDTH / 2.0, (HEIGHT / 2.0) - newHeight - (time / 100));
	}

	flowerSprite.setTexture(flowerImage);

	std::cout << newHeight << std::endl;

	window->draw(flowerSprite);
}
