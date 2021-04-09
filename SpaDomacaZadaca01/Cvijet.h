#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <memory>

class Cvijet {
private:
	sf::CircleShape circ_;
	sf::RectangleShape rect_;
	sf::ConvexShape conv_;

	float growth_dir;
	float growth_rate;
	float max_size;
	float min_size;
	sf::CircleShape growable_;

	void _InitCircle();
	void _InitRectangle();
	void _InitConvexShape();
	void _InitGrowable();

public:
	Cvijet();
	
	void Update(sf::Clock&);
	void Render(std::shared_ptr<sf::RenderTarget>);

};

