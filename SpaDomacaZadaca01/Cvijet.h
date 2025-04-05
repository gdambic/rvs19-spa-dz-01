#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Cvijet
{
private:
	sf::Texture texture;
	sf::RenderWindow* window;
	int CurrentAnimation;
	int FramesPerAnimation = 6;
	int FramesSinceUpdate = 0;
	std::vector<std::vector<sf::Vector2f>> rhombusi;
	sf::Clock clock;
	float targetFPS = 24;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

