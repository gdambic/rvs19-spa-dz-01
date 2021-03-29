#include "Cvijet.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijetic");
	window.setFramerateLimit(60);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1200.f, 1000.f));
	window.setView(view);
	
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		std::cout << "Error loading fonts." << std::endl;
		return 1;
	}
	text.setFont(font);
	text.setString("Click the left mouse button to go faster \nClick the right mouse button to go slower \n(Dont go too fast) :)");
	text.setFillColor(sf::Color::White);
	text.setPosition(-600.f, -500.f);
	text.setCharacterSize(40);

	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		window.draw(text);
		cvijet.draw();
		
		window.display();
	}
	

	return 0;
}