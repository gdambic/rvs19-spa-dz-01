#include <SFML/Graphics.hpp>
#include "Flower.h"
using namespace sf;

int main(){


	RenderWindow window(VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Flower flower (&window);
	
	int x = 30; //x coordinate for sun animation
	int direction = 1;
	
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
	

		window.clear();
		flower.draw(x);
		window.display();

	}

	return 0;
}