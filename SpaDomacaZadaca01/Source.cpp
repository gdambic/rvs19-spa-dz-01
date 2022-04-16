#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Trava.h"
#include "Nebo.h"
#include "Zivotinja.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	Trava trava(&window);
	Nebo nebo(&window);
	Zivotinja zivotinja(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		nebo.draw();
		cvijet.draw();
		trava.draw();
		zivotinja.draw();


		window.display();
	}

	return 0;
}