#include<iostream>
#include<SFML/Graphics.hpp>
#include "Cvijet.h"

using namespace std;

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;


	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!", sf::Style::Close, settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				cout << "\nKRAJ PROGRAMA";
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					cout << "\nKRAJ PROGRAMA";
					window.close();
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					cvijet.desno();
					cout << "desno" << endl;
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					cvijet.lijevo();
					cout << "lijevo" << endl;
				}
			}

		}


		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}