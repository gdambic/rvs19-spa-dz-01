#include <SFML/Graphics.hpp>
#include "SFML\OpenGL.hpp"
#include <iostream>
#include <ctime>
#include <vector>

#include "Cvijet.h"
#include "Cloud.h"


const int screenX = 800;
const int screenY = 600;

int main()
{

	//AA
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	//Window Settings
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "You can stand under my umbrella", sf::Style::Default, settings);
	

	//Vsync
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120);

	//FPS
	sf::Clock fps;

	Cvijet cvijet(&window);
	Cloud cloud(&window, 20);

	//Rain
	float spd = 5; //rain speed
	std::vector<float> speed;
	std::vector<sf::RectangleShape> raindrops;
	std::srand(std::time(0));

	//Init raindrops
	for (int i = 0; i < 100; i++)
	{
		raindrops.push_back(sf::RectangleShape(sf::Vector2f(rand() % 15 / 10.f + 1, (rand() % 500) / 10.f + 3))); //rand push
		raindrops[i].setPosition(sf::Vector2f(rand() % screenX, rand() % screenY)); //rand drop on coords
		speed.push_back((raindrops[i].getSize().x) * raindrops[i].getSize().x); //speed based on thickness
	}


	//Game (Main) loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				glViewport(0, 0, event.size.width, event.size.height);
				break;
			case sf::Event::KeyPressed:
				//Rainfall controls : UP = Increase rainfall speed | DOWN = Decrease rainfall speed (Arrow Keys)
				if (event.key.code == sf::Keyboard::Up)
				{
					spd++;
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					if (spd > 0)
					{
						spd--;
					}
				}
				break;
			}
		
		}

		window.clear();

		//Rainfall Optimisation
		for (int i = 0; i < raindrops.size(); i++)
		{
			//if onscreen
			if (raindrops[i].getPosition().y <= screenY)
			{
				raindrops[i].setPosition(raindrops[i].getPosition().x, raindrops[i].getPosition().y + speed[i] + spd);
			}
			//if ofscreen (to reduce stress)
			else
			{
				raindrops[i].setPosition(raindrops[i].getPosition().x, -40);
			}
		}

		//Draw rainfall
		for (int i = 0; i < raindrops.size(); i++)
		{
			window.draw(raindrops[i]);
		}

		//Drawing shapes
		cvijet.draw();
		cloud.draw();

		//FPS Dipsplay
		sf::Time time = fps.getElapsedTime();
		std::cout << 1.0f / time.asSeconds() << " FPS" << std::endl;
		fps.restart().asSeconds();

		//Display
		window.display();
	}

	return 0;
}