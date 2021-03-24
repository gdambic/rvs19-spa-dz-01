#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window,sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :m_window(window)
{
	
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.f;
	currentImage.x = 0;
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
	flower.setSize(sf::Vector2f(80.0f, 100.0f));
	flower.setPosition(206.0f, 206.0f);
	flower.setTexture(texture);
}



void Cvijet::update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0; 
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

void Cvijet::draw(sf::RenderWindow& window)
{
	flower.setTextureRect(uvRect);
	window.draw(flower);
}
