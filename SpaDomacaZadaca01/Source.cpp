#include <SFML/Graphics.hpp>
#include <iostream>
#include"Cvijet.h"
int main()
{
	//Settings 
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Leon Kruslin 1RP1", sf::Style::Default, settings);
	window.setFramerateLimit(144);

	//Backgorund
	sf::RectangleShape backgorund;
	sf::Texture backgroundTexture;
	std::string backgroundTextureName = "AlgebraBAckground.jpg";
	if (!backgroundTexture.loadFromFile(backgroundTextureName))
	{
		std::cout << "ERROR: " << backgroundTextureName << " NOT FOUND" << std::endl;
		return 1;
	}
	backgorund.setSize({ (float)(window.getSize().x), (float)(window.getSize().y) });
	backgorund.setTexture(&backgroundTexture);
	backgorund.setPosition({ 0.0f,0.0f });

	//Basic Variables
	float rotatingSpeed = 50.0f;
	sf::Clock clock;

	//Flower class declarations (Texture setter optional, for custom textures)
	Cvijet cvijet1(window, 120.0f, { 400.0f, 1000.0f });
	Cvijet cvijet2(window, 80.0f, { 1000.0f, 650.0f });
	Cvijet cvijet3(window, 60.0f, { 1650.0f, 600.0f });
	Cvijet cvijet4(window, 45.0f, { 250.0f, 500.0f });

	cvijet1.set_tiltOffstet(10.0f);
	cvijet2.set_tiltOffstet(15.0f);
	cvijet3.set_tiltOffstet(-5.0f);

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		window.draw(backgorund);

		cvijet1.draw(deltaTime, rotatingSpeed);
		cvijet2.draw(deltaTime, rotatingSpeed);
		cvijet3.draw(deltaTime, rotatingSpeed);
		cvijet4.draw(deltaTime, rotatingSpeed);

		window.display();
	}
	return 0;
}