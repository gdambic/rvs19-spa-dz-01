#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
private:
	sf::RenderWindow& render_window;
	
	sf::Vector2i base_pos, base_head_pos, head_pos, window_pos; // In px

	std::vector<sf::Vector2i> segments;

	float head_rotation;

	int total_petals;

	int half_petals;

	/// <summary>
	/// First half is back petals, second half is front.
	/// Stored in degrees.
	/// </summary>
	std::vector<float> petal_rotations;

	std::vector<float> petal_rotation_phase;

	static sf::VertexArray petal;

	static sf::VertexArray centered_circle;

	float lifetime;
public:
	Cvijet(sf::RenderWindow& window, int segments = 32, int petals = 18);
	sf::RenderWindow& getRenderWindow();
	void update(float delta);
	void draw();
	static void init_vertices(int definition);
};

