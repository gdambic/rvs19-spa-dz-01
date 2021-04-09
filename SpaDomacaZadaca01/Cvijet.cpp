#include "Cvijet.h"

constexpr float MODE_WIDTH_F = 800.F;
constexpr float MODE_HEIGHT_F = 800.F;
constexpr float CENTER = 400.F;

void Cvijet::_InitCircle() {
	float circ_radius{ 70.F };
	float circ_outline{ 70.F };
	circ_.setPosition(sf::Vector2f{ CENTER - circ_radius, CENTER - circ_radius });
	circ_.setRadius(circ_radius);
	circ_.setFillColor(sf::Color::Yellow);
	circ_.setOutlineThickness(circ_outline);
	circ_.setOutlineColor(sf::Color::Red);
}

void Cvijet::_InitRectangle() {
	float circ_size = circ_.getRadius() + circ_.getOutlineThickness();
	float rect_width = 20.f;
	float rect_height = CENTER - circ_size;
	rect_.setPosition(sf::Vector2f{ CENTER - (rect_width / 2), CENTER + circ_size });
	rect_.setSize(sf::Vector2f{ rect_width, rect_height });
	rect_.setFillColor(sf::Color::Green);
}

void Cvijet::_InitConvexShape() {
	float circ_size = circ_.getRadius() + circ_.getOutlineThickness();
	float rect_height = CENTER - circ_size;
	float starting_height = CENTER + circ_size + (rect_height / 2);
	conv_.setPointCount(4);
	conv_.setPoint(0, sf::Vector2f{ CENTER, starting_height });
	conv_.setPoint(1, sf::Vector2f{ CENTER + 100.F, starting_height - 70.F });
	conv_.setPoint(2, sf::Vector2f{ CENTER + 300.F, starting_height - 80.F });
	conv_.setPoint(3, sf::Vector2f{ CENTER + 110.F, starting_height + 20.F });
	conv_.setFillColor(sf::Color::Green);
}

void Cvijet::_InitGrowable() {
	growth_rate = 10.F;
	growth_dir = 1.F;
	max_size = 80.F;
	min_size = 40.F;
	growable_.setRadius(min_size);
	growable_.setPosition(sf::Vector2f{ 100.F, 100.F });
	growable_.setFillColor(sf::Color::Yellow);
}

Cvijet::Cvijet() {
	_InitCircle();
	_InitRectangle();
	_InitConvexShape();
	_InitGrowable();
}

void Cvijet::Update(sf::Clock& frame_clock) {
	float size = growable_.getRadius();
	if (size <= min_size) growth_dir = 1.F;
	if (size >= max_size) growth_dir = -1.F;
	size += growth_dir * growth_rate * frame_clock.restart().asSeconds();
	growable_.setRadius(size);
	growable_.setPosition(sf::Vector2f{ 100.F - size, 100.F - size });
}

void Cvijet::Render(std::shared_ptr<sf::RenderTarget> target) {
	target->draw(rect_);
	target->draw(circ_);
	target->draw(conv_);
	target->draw(growable_);
}
