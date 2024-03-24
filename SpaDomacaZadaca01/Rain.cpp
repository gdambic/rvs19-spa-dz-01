#include "Rain.h"

const int Rain::RAIN_DENSITY = 5;

Rain::Rain(): AnimatedElement(sf::Vector2f(0, 0), sf::Vector2f(0, 0)) {}

Rain::~Rain() {
	for (auto& droplet : rain) {
		delete droplet;
	}
	rain.clear();
}

void Rain::addToRain() {
	std::uniform_int_distribution<int> dis(0, RAIN_DENSITY + 1);
	int density = dis(gen);
	for (int i = 0; i < density; ++i) {
		rain.push_back(new Droplet(gen));
	}
}

void Rain::draw(sf::RenderWindow& window) {
	for (auto& droplet : rain) {
		droplet->draw(window);
	}
}

void Rain::update(const sf::Time& deltaTime) {
	for (size_t i = 0; i < rain.size(); ++i) {
		Droplet* droplet = rain[i];
		if (droplet->hasFallen()) {
			rain.erase(rain.begin() + i);
			--i;
			delete droplet;
			continue;
		}

		droplet->update(deltaTime);
	}

	addToRain();
}
