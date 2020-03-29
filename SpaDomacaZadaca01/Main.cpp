#include <SFML/Graphics.hpp>
#include"Animation.h"

#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML World! by Lovrinjo Beninjino ");
	window.setFramerateLimit(60);
	sf::CircleShape sun(80.f);
	sun.setPosition(50.0f, 50.0f);
	sf::Texture sunTexture;
	sunTexture.loadFromFile("Texture/sun.jpg");
	sun.setTexture(&sunTexture);


	sf::CircleShape glow(84.f);
	sf::Texture glowTexture;
	glow.setPosition(52.0f, 49.0f);
	glowTexture.loadFromFile("Texture/glow.jpg");
	glow.setTexture(&glowTexture);

	sf::RectangleShape background(sf::Vector2f(800, 600));
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Texture/backgroung.png");
	background.setTexture(&backgroundTexture);


	sf::RectangleShape flower(sf::Vector2f(200.0f, 250.0f));
	flower.setPosition(200.0f, 200.0f);
	sf::Texture flowerTexture;
    flowerTexture.loadFromFile("Texture/flower.png");
	flower.setTexture(&flowerTexture);
	
	Animation flowerAnimation(&flowerTexture, sf::Vector2u(6, 3), 0.35f);
	Animation sunAnimation(&sunTexture, sf::Vector2u(1, 1), 0.01f);
	Animation glowAnimation(&glowTexture, sf::Vector2u(4, 4), 0.25f);
	float deltaTime = 0.0f;
	sf::Clock clock;



	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				break;
		}
		flowerAnimation.Update(0, deltaTime);
		flower.setTextureRect(flowerAnimation.uvRect);
		sunAnimation.Update(0, deltaTime);
		sun.setTextureRect(sunAnimation.uvRect);
		glowAnimation.Update(0, deltaTime);
		glow.setTextureRect(glowAnimation.uvRect);
		window.clear();
		window.draw(background);
		window.draw(flower);
		
		window.draw(glow);
		window.draw(sun);
		window.display();
	}

	return 0;
}