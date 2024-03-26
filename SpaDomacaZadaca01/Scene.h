#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedElement.h"

class Scene {
private:
	sf::RenderWindow* window;
	sf::Color backgroundColor;
	std::vector<AnimatedElement*> animatedElements;

public:
	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;
	static const float PI;
	static const sf::Color NOON_COLOR;

	Scene(sf::RenderWindow* window);
	~Scene();
	void draw();
	void update(const sf::Time& deltaTime);
	sf::Color getSkyColorFromSun(float angle);
};
