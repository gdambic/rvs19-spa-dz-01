#include <SFML/Graphics.hpp>
#include "Flower.h"
#include "vector"
#include "iostream"
using namespace std;

int main()
{

	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Procedural Flower Generator");
	window.setFramerateLimit(60);
	
	Flower flower;

	int userin; // Dynamic user input variable

	cout << "Enter the diameter of center: ";
	cin >> userin;
	flower.setCenterSize(userin);

	cout << "Enter the number of petals: ";
	cin >> userin;
	flower.setPetalNum(userin);

	cout << "Enter the diameter of petals: ";
	cin >> userin;
	flower.setPetalSize(userin);

	cout << "Enter the diameter of stem: ";
	cin >> userin;
	flower.setStemSize(userin);

	cout << "Enter the number of leaves: ";
	cin >> userin;
	flower.setLeavesNum(userin);

	cout << "Enter the diameter of leaves: ";
	cin >> userin;
	flower.setLeafSize(userin);

	cout << "Enter the number of flowers: ";
	cin >> userin;
	flower.setFlowerNum(userin);

	cout << "Enter the season (0 for summer, 1 for winter, 2 for spring): ";
	cin >> userin;
	flower.setSeason(userin);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		flower.draw(window); // Draw the flower
		window.display();
	}

	return 0;
}