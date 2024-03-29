#include "Cvijet.h"
#include <iostream>

const int height = 256;
const int head_size = 32;

Cvijet::Cvijet(sf::RenderWindow& window, int segments) : render_window(window)
{
	sf::Vector2u window_size = window.getSize();

	int base_x = window_size.x / 2;
	int base_y = window_size.y / 2;

	this->base_pos = sf::Vector2i(base_x, base_y);
	this->head_pos = sf::Vector2i(base_x, base_y - height);

	for (size_t i = 1; i <= segments; i++)
		this->segments.push_back(sf::Vector2i(base_x, base_y - i * height / segments));

	this->window_pos = window.getPosition();
}

sf::RenderWindow& Cvijet::getRenderWindow()
{
	return this->render_window;
}

void Cvijet::draw()
{
	sf::Vector2i new_window_pos = this->render_window.getPosition();
	sf::Vector2i delta_window_pos = new_window_pos - this->window_pos;

	this->head_pos += delta_window_pos;

	sf::CircleShape head(head_size);
	head.setPosition(this->head_pos.x - head_size, this->head_pos.y - head_size);
	this->render_window.draw(head);

	int segments = this->segments.size();
	sf::VertexArray vertices(sf::Lines, segments);
	for (size_t i = 0; i < segments; i++) {
		sf::Vector2i segment = this->segments[i];
		vertices[i].position = sf::Vector2f(segment.x, segment.y);
	}

	this->render_window.draw(vertices);

	this->window_pos = new_window_pos;
}
