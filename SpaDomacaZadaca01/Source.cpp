#include <SFML/Graphics.hpp>

int main()	
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet - by vanjavk", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		sf::CircleShape shape(50.f);

		// set the shape color to green
		shape.setFillColor(sf::Color(100, 250, 50));
		window.draw(shape);
		sf::CircleShape shape1(30.f);
		shape1.setFillColor(sf::Color(100, 200, 50));
		window.draw(shape1);
		//cvijet.draw();
		window.display();
	}

	return 0;
}