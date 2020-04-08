#include <SFML/Graphics.hpp>
#include "Okolina.h"
#include "Tlo.h"
#include "Trava.h"
#include <time.h>

int main()
{

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Pino Roglic-domaca zadaca");
	window.setFramerateLimit(60);
	Okolina okolina(&window);
	Tlo tlo(&window, 1000);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(Color(100, 100, 255));
		
		tlo.draw();
		okolina.draw();
		window.display();

	}

	return 0;
}