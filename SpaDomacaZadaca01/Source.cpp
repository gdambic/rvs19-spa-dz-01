#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
#include <iostream>

int main()
{
	unsigned int windowWidth{ 800 };
	unsigned int windowHeight{ 600 };
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pepega");
	window.setFramerateLimit(60);

	sf::Texture spritesheetRight;
	if (!spritesheetRight.loadFromFile("player-spritemap-v9 - right_facing.png"))
	{
		std::cout << "Failed to load player spritesheet right!" << std::endl;
		return 1;
	}
	sf::Texture spritesheetLeft;
	if (!spritesheetLeft.loadFromFile("player-spritemap-v9 - left_facing.png"))
	{
		std::cout << "Failed to load player spritesheet left!" << std::endl;
		return 1;
	}
	
	Animation standingAnimationRight;
	standingAnimationRight.setSpriteSheet(spritesheetRight);
	standingAnimationRight.addFrame(sf::IntRect(0, 0, 46, 50));

	Animation standingAnimationLeft;
	standingAnimationLeft.setSpriteSheet(spritesheetLeft);
	standingAnimationLeft.addFrame(sf::IntRect(322, 0, 46, 50));

	Animation walkingAnimationRight;
	walkingAnimationRight.setSpriteSheet(spritesheetRight);
	walkingAnimationRight.addFrame(sf::IntRect(0, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(46, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(92, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(138, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(184, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(230, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(276, 150, 46, 50));
	walkingAnimationRight.addFrame(sf::IntRect(322, 150, 46, 50));

	Animation walkingAnimationLeft;
	walkingAnimationLeft.setSpriteSheet(spritesheetLeft);
	walkingAnimationLeft.addFrame(sf::IntRect(322, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(276, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(230, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(184, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(138, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(92, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(46, 150, 46, 50));
	walkingAnimationLeft.addFrame(sf::IntRect(0, 150, 46, 50));

	Animation jumpingAnimationRight;
	jumpingAnimationRight.setSpriteSheet(spritesheetRight);
	jumpingAnimationRight.addFrame(sf::IntRect(276, 0, 46, 50));
	
	Animation jumpingAnimationLeft;
	jumpingAnimationLeft.setSpriteSheet(spritesheetLeft);
	jumpingAnimationLeft.addFrame(sf::IntRect(46, 0, 46, 50));

	Animation* currentAnimation = &standingAnimationRight;
	Animation* characterOrientation = &standingAnimationRight;

	AnimatedSprite animatedSprite(sf::seconds(0.1f), true, false);
	animatedSprite.setOrigin(0.f, 50.f);
	animatedSprite.setPosition(0.f, 550.f);

	sf::Clock frameClock;

	float speed = 80.f;
	float jump = 250.f;
	float gravity = 120.f;
	bool noKeyWasPressed = true;
	bool isJumping = false;


	Cvijet cvijet(&window);
	cvijet.setWindowWidthHeight(windowWidth, windowHeight);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Time frameTime = frameClock.restart();
		sf::Vector2f movement(0.f, 0.f);

		//MOVEMENT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentAnimation = &walkingAnimationRight;
			characterOrientation = &standingAnimationRight;
			movement.x += speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			currentAnimation = &walkingAnimationLeft;
			characterOrientation = &standingAnimationLeft;
			movement.x -= speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isJumping)
		{
			isJumping = true;
			movement.y -= sqrtf(7.0f * gravity * jump);
			if (characterOrientation == &standingAnimationRight)
			{
				currentAnimation = &jumpingAnimationRight;
			}
			
			if (characterOrientation == &standingAnimationLeft)
			{
				currentAnimation = &jumpingAnimationLeft;
			}
		}

		movement.y += gravity * 1.5f;
		//ground collision
		if (animatedSprite.getPosition().y >= 550)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 550.f);
			isJumping = false;
		}
		//platforma 1 collision
		if (animatedSprite.getPosition().x >= 75.f && animatedSprite.getPosition().x <= 130.f && animatedSprite.getPosition().y >= 450.f && animatedSprite.getPosition().y <= 460.f)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 450.f);
		}
		//platforma 2 collision
		if (animatedSprite.getPosition().x >= 175.f && animatedSprite.getPosition().x <= 225.f && animatedSprite.getPosition().y >= 375.f && animatedSprite.getPosition().y <= 385.f)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 375.f);
		}
		//platforma 3 collision
		if (animatedSprite.getPosition().x >= 275.f && animatedSprite.getPosition().x <= 325.f && animatedSprite.getPosition().y >= 400.f && animatedSprite.getPosition().y <= 410.f)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 400.f);
		}
		//platforma 4 collision
		if (animatedSprite.getPosition().x >= 375.f && animatedSprite.getPosition().x <= 425.f && animatedSprite.getPosition().y >= 450.f && animatedSprite.getPosition().y <= 460.f)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 450.f);
		}
		//platforma 5 collision
		if (animatedSprite.getPosition().x >= 475.f && animatedSprite.getPosition().x <= 525.f && animatedSprite.getPosition().y >= 375.f && animatedSprite.getPosition().y <= 385.f)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 375.f);
		}
		//platforma 6 collision
		if (animatedSprite.getPosition().x >= 600.f && animatedSprite.getPosition().x <= 650.f && animatedSprite.getPosition().y >= 400.f && animatedSprite.getPosition().y <= 410.f)
		{
			animatedSprite.setPosition(animatedSprite.getPosition().x, 400.f);
		}

		animatedSprite.play(*currentAnimation);
		animatedSprite.move(movement * frameTime.asSeconds());
		
		// if no key was pressed stop the animation
		if (noKeyWasPressed)
		{
			animatedSprite.stop();
			isJumping = false;
			currentAnimation = &(*characterOrientation);
		}
		noKeyWasPressed = true;

		// update AnimatedSprite
		animatedSprite.update(frameTime);

		window.clear(sf::Color(128, 164, 213));
		cvijet.draw();
		window.draw(animatedSprite);
		window.display();
	}

	return 0;
}