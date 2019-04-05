#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nightflower", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	sf::View view(sf::FloatRect(0.f, 359.f, 1280.f, 720.f));
	window.setView(view);

	World world(&window, "Night", 2);
	Cvijet cvijet(&window, 600.f, 930.f);
	sf::Clock clock;

	bool WFlag = false;
	bool AFlag = false;
	bool SFlag = false;
	bool DFlag = false;
	bool SpaceFlag = false;
	bool lastDirection;

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::W: WFlag = true; break;
				case sf::Keyboard::S: SFlag = true; break;
				case sf::Keyboard::A: AFlag = true; lastDirection = true; break;
				case sf::Keyboard::D: DFlag = true; lastDirection = false; break;
				case sf::Keyboard::Space: SpaceFlag = true; break;
				case sf::Keyboard::Escape: window.close(); break;
				default: break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::W: WFlag = false; break;
				case sf::Keyboard::S: SFlag = false; break;
				case sf::Keyboard::A: AFlag = false; break;
				case sf::Keyboard::D: DFlag = false; break;
				case sf::Keyboard::Space: SpaceFlag = false; break;
				default: break;
				}
				break;
			default:
				break;
			}
		}

		//key handlers
		if (DFlag && AFlag) {
			cvijet.changeAnimation("Still", lastDirection);
		}
		if (DFlag && !AFlag) {
			if (!SpaceFlag) {
				if (cvijet.get_currentAnimation() != "Walk")
				{
					cvijet.changeAnimation("Walk", false);
				}
			}
			else {
				cvijet.changeAnimation("Jump", false);
			}
			cvijet.moveForward();
		}
		if (AFlag && !DFlag) {
			if (cvijet.get_worldPosition()->get_x() > 0) {
				if (!SpaceFlag) {
					if (cvijet.get_currentAnimation() != "Walk")
					{
						cvijet.changeAnimation("Walk", true);
					}
				}
				else {
					cvijet.changeAnimation("Jump", true);					
				}
				cvijet.moveBackward();
			}
			else {
				cvijet.changeAnimation("Still", true);
			}
		}
		if (!AFlag && !DFlag && SpaceFlag) {
			cvijet.changeAnimation("Jump", false);
		}
		if (!AFlag && !DFlag && cvijet.get_currentAnimation() != "Still") {
			cvijet.changeAnimation("Still", lastDirection);
		}

		cvijet.updateFactory(deltaTime);
		window.clear();
		world.draw(cvijet.get_worldPosition());
		cvijet.draw();
		window.display();
	}

	return 0;
}