#include "Bee.h"

Bee::Bee() : RectangleShape(sf::Vector2f(50, 50))
{
	if (!texture.loadFromFile("bee.png")) {
		std::cout << "Failed to open file 'bee.png'" << std::endl;
		return;
	}
	setTexture(&texture);

	clock = sf::Clock();
	last_animation_update = clock.getElapsedTime();

	update();
}

#include <ctime>
void Bee::animation(sf::RenderWindow* window)
{
	sf::Time elapsed_time = clock.getElapsedTime();
	if (elapsed_time.asMilliseconds() < last_animation_update.asMilliseconds()) {
		return;
	}

	float x = 225 + x_counter;
	float y = 200 + 100 * cos(x / 100);

	if (animation_direction_to_a) {
		x_counter++;

		// We allow it to go a bit more off screen
		if (x - 50 >= window->getSize().x) {
			animation_direction_to_a = false;
			setScale(sf::Vector2f(-1, 1));
		}
	}
	else {
		x_counter--;

		if (x_counter <= 1) {
			animation_direction_to_a = true;
			setScale(sf::Vector2f(1, 1));
		}
	}

	setPosition(sf::Vector2f(x, y));

	last_animation_update = elapsed_time;
}