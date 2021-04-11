#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	float radiusc;
	float radiuss;
	float pozcx;
	float pozcy;
	float pozsx;
	float pozsy;


	std::cout << "Unesite radius cvijeta: ";
	std::cin >> radiusc;
	std::cout << "Unesite radius sunca: ";
	std::cin >> radiuss;
	std::cout << "Unesite koordinate cvijeta (x y): ";
	std::cin >> pozcx >> pozcy;
	std::cout << "Unesite koordinate sunca (x y): ";
	std::cin >> pozsx >> pozsy;





	cvijet.RadiusCvijeta(radiusc);
	cvijet.pozicijaCvijeta(pozcx, pozsy);
	cvijet.RadiusSunca(radiuss);
	cvijet.pozicijaSunca(pozsx, pozsy);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}