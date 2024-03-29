#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow& render_window;
	
	sf::Vector2i base_pos, head_pos, window_pos; // In px

	std::vector<sf::Vector2i> segments;
public:
	Cvijet(sf::RenderWindow& window, int segments = 32);
	sf::RenderWindow& getRenderWindow();
	void draw();
};

