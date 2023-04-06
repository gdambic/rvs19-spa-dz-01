#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cvijet.h"

using namespace std;

int main()
{
	

	sf::Texture bTexture;
	sf::Sprite backgroundImage;
	if (!bTexture.loadFromFile("fifi.jpg"))
	{
		cout << "Couldn't load image." << endl;
	}
	//bTexture.setRepeated(true);

	backgroundImage.setTexture(bTexture);

	//backgroundImage.setTextureRect(sf::IntRect(0, 0, 600, 600));

	//backgroundImage.setColor(sf::Color(255, 255, 255, 64));


	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(window);
	cvijet.set_ran(false);
	sf::Clock clock;
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		cvijet.anim(clock);
		std::cout << clock.getElapsedTime().asSeconds() << "\n";

		window.clear();

		window.draw(cvijet.get_stabljika());
		for (int i = 0; i < 5; i++)
		{
			window.draw(cvijet.get_latice().at(i));
		}
		window.draw(cvijet.get_list());
		window.draw(cvijet.get_tucak());

		window.draw(backgroundImage);
		window.display();
	}


	return 0;
}