#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <functional>
#include "Trava.h"
#include "Cvijet.h"
#include "Planina.h"
#include "Pozadina.h"
#include "Kisa.h"

#define PI   3.14159265358979323846264338327950288
#define degToRad(input) ((input) * PI / 180.0)

template<typename tVal>
tVal map_value(std::pair<tVal, tVal> a, std::pair<tVal, tVal> b, tVal inVal)
{
	tVal inValNorm = inVal - a.first;
	tVal aUpperNorm = a.second - a.first;
	tVal normPosition = inValNorm / aUpperNorm;

	tVal bUpperNorm = b.second - b.first;
	tVal bValNorm = normPosition * bUpperNorm;
	tVal outVal = b.first + bValNorm;

	return outVal;
}

int main()
{
	srand(time(nullptr));

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Patrik Percinic Cvijet", sf::Style::Default, settings);
	window.setFramerateLimit(144);
	Cvijet cvijet(&window);
	Trava trava(&window);
	Planina planina(&window);
	Pozadina pozadina(&window);
	Kisa kisa(&window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		pozadina.draw();
		planina.draw();
		kisa.draw(pozadina.getNoc());
		cvijet.draw();
		trava.draw();
		window.display();
	}

	return 0;
}