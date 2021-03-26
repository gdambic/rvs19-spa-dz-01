#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Cvijet.h"
using namespace std;
using namespace sf;
using namespace std::chrono;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet("shrek-removebg-preview.png", "fiona.png", "donkie.png", &window);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			cvijet.moveShrek('w', 5.0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			cvijet.moveShrek('s', 5.0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A))
		{
			cvijet.moveShrek('a', 5.0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			cvijet.moveShrek('d', 5.0);
		}

		cvijet.moveDonkie();
		window.clear();
		cvijet.drawText("Raleway-Light.ttf");
		cvijet.drawCvijet();
		cvijet.drawFiona();
		cvijet.drawShrek();
		cvijet.drawDonkie();
		
		if (cvijet.get_xShrek() >= 1000 && cvijet.get_yShrek() >= 500)
		{
			window.close();
			ifstream fileReader("gameover.txt");
			if (!fileReader)
			{
				cerr << "Cannot open this file";
				return 1;
			}
			string line;
			while (getline(fileReader, line))
			{
				cout << line << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			return 0;
		}
		window.display();
	}
	return 0;
}