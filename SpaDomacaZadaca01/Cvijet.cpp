#include "Cvijet.h"
#include <vector>
#include <iostream>
#include <cmath>

// LICENSE - i don't care copy all you want
// Borna Popovic 2024

const int y_offset = 512;

const float petal_scale = 0.5f;
const int height = 512;
const int pistil_size = 32;

const float F_PI = atan(1) * 4.0f;

sf::VertexArray Cvijet::petal;
sf::VertexArray Cvijet::centered_circle;

// Couldn't I do this in a static constructor?
void Cvijet::init_vertices(int definition) {
	int radius = 100;
	Cvijet::petal = sf::VertexArray(sf::TriangleFan, definition + 1);
	Cvijet::centered_circle = sf::VertexArray(sf::TriangleFan, definition + 1);

	petal[0].position = sf::Vector2f(0, 0);

	for (int i = 0; i < definition; ++i) {
		float theta = i * (F_PI / (definition - 1));
		float x = radius * cos(theta);
		float y = radius * sin(theta) + radius;
		Cvijet::petal[i + 1].position = sf::Vector2f(x, y);
	}

	centered_circle[0].position = sf::Vector2f(0, 0);

	for (int i = 0; i < definition; ++i) {
		float theta = i * (F_PI * 2 / (definition - 1));
		float x = radius * cos(theta);
		float y = radius * sin(theta);
		Cvijet::centered_circle[i].color = sf::Color(140, 120, 50, 255);
		Cvijet::centered_circle[i].position = sf::Vector2f(x, y);
	}
}

Cvijet::Cvijet(sf::RenderWindow& window, int segments, int petals) : render_window(window)
{
	Cvijet::lifetime = 0;

	Cvijet::total_petals = petals;
	Cvijet::half_petals = petals / 2 - 1; // convoluted evil for loop garbage

	Cvijet::head_rotation = 45.0f;

	for (size_t i = 0; i < petals; i++) {
		Cvijet::petal_rotations.push_back(0.0f);
		Cvijet::petal_rotation_phase.push_back((float)(rand() % 360));
	}

	sf::Vector2u window_size = window.getSize();

	int base_x = window_size.x / 2;
	int base_y = window_size.y / 2 + y_offset;

	this->base_pos = sf::Vector2i(base_x, base_y);
	this->base_head_pos = this->head_pos = sf::Vector2i(base_x, base_y - height);

	for (size_t i = 1; i <= segments; i++)
		this->segments.push_back(sf::Vector2i(base_x, base_y - i * height / segments));

	this->window_pos = window.getPosition();
}

void Cvijet::update(float delta)
{
	Cvijet::lifetime += delta;

	for (size_t i = 0; i < petal_rotations.size(); i++)
		petal_rotations[i] += sin( (lifetime + petal_rotation_phase[i]) * 15) / 5.0f;

	head_rotation = sin(lifetime * 2.0f) * 20.0f - 30.0f;

	// Can't be done with -= and += because it veers off the original position
	// Maybe due to floating point inaccuracies? Don't care enough to find out
	head_pos.x = base_head_pos.x - (int)(sin(lifetime * 3.0f) * 20.0f);
	head_pos.y = base_head_pos.y + (int)(cos(lifetime * 2.0f) * 15.0f);
}

sf::Vector2f calculateBezierPoint(float t, sf::Vector2f P0, sf::Vector2f P1, sf::Vector2f P2, sf::Vector2f P3) {
	float u = 1 - t;
	float tt = t * t;
	float uu = u * u;
	float uuu = uu * u;
	float ttt = tt * t;

	sf::Vector2f B = uuu * P0; // (1-t)^3 * P0
	B += 3 * uu * t * P1; // 3(1-t)^2 * t * P1
	B += 3 * u * tt * P2; // 3(1-t) * t^2 * P2
	B += ttt * P3; // t^3 * P3

	return B;
}

void Cvijet::draw()
{
	// Preprocess
	sf::Vector2i new_window_pos = this->render_window.getPosition();
	sf::Vector2i delta_window_pos = new_window_pos - this->window_pos;

	this->head_pos += delta_window_pos;

	// Render stalk (Bezier curve)
	segments.back() = head_pos;
	sf::Vector2f start = sf::Vector2f(segments[0]);
	sf::Vector2f control_point = sf::Vector2f(head_pos + sf::Vector2i(100 - sin(lifetime * 2) * 50, 130 + sin(lifetime * 2) * 50));
	sf::Vector2f end = sf::Vector2f(segments.back());

	sf::VertexArray curve(sf::LinesStrip, segments.size());
	for (size_t i = 0; i < segments.size(); ++i) {
		float t = static_cast<float>(i) / (segments.size() - 1);
		sf::Vector2f point = calculateBezierPoint(t, start, control_point, control_point, end);
		curve[i].position = point;
		curve[i].color = sf::Color(55 - i, 180 - i * 3, 80 - i * 2, 255);
	}
	this->render_window.draw(curve);

	// Render back petals
	float middle_index = half_petals / 2.0f;
	float index = 0.0f;
	for (int i = 0; i <= half_petals; i++)
	{
		// Bouncing index, which ensures the petals are layered correctly
		if (i % 2 == 0)
			index = (float)i / 2.0f;
		else
			index = half_petals - ((float)i / 2.0f) + 0.5f;

		float distance_from_cam = 1.0f - abs(sin(F_PI * index / half_petals)) * 0.5f;

		sf::Transform transform;
		transform.translate(this->head_pos.x, this->head_pos.y - 2 * (1.0f - distance_from_cam) * 10);
		transform.rotate(head_rotation);
		// Global scaling
		transform.scale(
			sf::Vector2f(
				1.0f,
				distance_from_cam
			)
		);
		transform.rotate(270.0f - (index / half_petals) * 180.0f + petal_rotations[i]);
		// Local scaling
		transform.scale(sf::Vector2f(0.3f, 1.0f));

		for (size_t j = 0; j < petal.getVertexCount(); j++)
			petal[j].color = sf::Color(60 + distance_from_cam * 30, 60 + distance_from_cam * 30, 60 + distance_from_cam * 30);

		transform.scale(petal_scale, petal_scale);
		this->render_window.draw(petal, transform);
	}

	// Render head
	sf::Transform transform;
	transform.translate(this->head_pos.x, this->head_pos.y);
	transform.rotate(head_rotation);
	transform.scale(sf::Vector2f(0.3f, 0.25f));
	this->render_window.draw(centered_circle, transform);

	// Render front petals
	for (int i = 0; i <= half_petals; i++)
	{
		// Bouncing index, which ensures the petals are layered correctly
		if (i % 2 == 0)
			index = (float)i / 2.0f;
		else
			index = half_petals - ((float)i / 2.0f) + 0.5f;

		float distance_from_cam = 1.0f - abs(sin(F_PI * index / half_petals)) * 0.5f;

		sf::Transform transform;
		transform.translate(this->head_pos.x, this->head_pos.y - 5);
		transform.rotate(head_rotation);
		// Global scaling
		transform.scale(
			sf::Vector2f(
				1.0f,
				distance_from_cam
			)
		);
		transform.rotate(90.0f - (index / half_petals) * 180.0f + petal_rotations[half_petals + 1 + i]);
		// Local scaling
		transform.scale(sf::Vector2f(0.3f, 1.0f));

		for (size_t j = 0; j < petal.getVertexCount(); j++)
			petal[j].color = sf::Color(200 - distance_from_cam * 100, 200 - distance_from_cam * 100, 200 - distance_from_cam * 100);

		transform.scale(petal_scale, petal_scale);
		this->render_window.draw(petal, transform);
	}

	// Postprocess
	this->window_pos = new_window_pos;
}

sf::RenderWindow& Cvijet::getRenderWindow()
{
	return this->render_window;
}