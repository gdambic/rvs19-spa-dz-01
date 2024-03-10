#include <SFML/Graphics.hpp>
#include "Flower.h"
using namespace sf;

int main(){


	RenderWindow window(VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Flower flower (&window);
	//Flower flower = Flower(&window);
	
	int x = 30; //x coordinate for sun animation
	int direction = 1;
	int angle = 0; //for rotating petals
	while (window.isOpen()){

		Event event;
		while (window.pollEvent(event)){

			if (event.type == Event::Closed)
				window.close();
		}

		if (x == 800) {
			direction = -1;
		}
		else if (x == 30) {
			direction = 1;
		}
		x = x + direction;
		angle = angle + 1;

		window.clear();
		flower.draw(x,angle);
		window.display();

	}

	return 0;
}