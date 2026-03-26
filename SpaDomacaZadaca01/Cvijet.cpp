#include "Cvijet.h"
#include <ctime>

Cvijet::Cvijet(sf::RenderWindow* window, sf::Color color, sf::Vector2f offset_sepal, float r_center, float global_scale)
{
	srand(time(nullptr));

	this->window = window;
	this->hydrangea_color = color;
	this->offset_sepal = offset_sepal;
	this->r_center = r_center;
	this->global_scale = global_scale;

	float flower_height = r_center * 2.f * global_scale;
	sf::Vector2f pos(offset_sepal.x, offset_sepal.y + r_center);

	bottom = pos + sf::Vector2f(0.f, flower_height);
	init_hydrangeas(&hydrangeas);
}

sf::Color Cvijet::get_color() const
{
    return hydrangea_color;
}

void Cvijet::set_color(const sf::Color color)
{
	this->hydrangea_color = color;
}

sf::Vector2f Cvijet::get_offset_sepal() const
{
	return this->offset_sepal;
}

float Cvijet::get_r_center() const
{
	return this->r_center;
}


void Cvijet::init_hydrangeas(std::vector<Hydrangea>* hydrangeas)
{
	auto clamp = [](int val) { return val < 0 ? 0 : (val > 255 ? 255 : val); };
	auto gen_rnd = [](int min, int max) { return rand() % (max - min + 1) + min; };
	auto gen_float = []() { return static_cast<float>(rand()) / static_cast<float>(RAND_MAX); };

	auto color_gradient = [gen_rnd, clamp](sf::Color color) {
		color.r = clamp((int)color.r + gen_rnd(-30, 30));
		color.g = clamp((int)color.g + gen_rnd(-30, 30));
		color.b = clamp((int)color.b + gen_rnd(-30, 30));
		return color;
		};

	int nb_hydrangeas = gen_rnd(100, 120);
	sf::Color flower_color = get_color();
	sf::Vector2f offset = get_offset_sepal();
	float r_center = get_r_center();

	for (size_t i = 0; i < nb_hydrangeas; i++) {
		Hydrangea hydrangea;
		hydrangea.color = color_gradient(flower_color);

		float angle = gen_float() * 2.f * 3.14159265f;
		float radius = gen_float() * r_center * global_scale;
		sf::Vector2f pos;
		pos.x = offset.x + radius * cos(angle);
		pos.y = offset.y + radius * sin(angle);

		float dx = bottom.x - pos.x;
		float dy = bottom.y - pos.y;
		float length = sqrt(dx * dx + dy * dy);
		float angle_deg = atan2(dy, dx) * 180.f / 3.14159265f;

		float stem_thickness = 0.2f * global_scale;
		hydrangea.stem.setSize(sf::Vector2f(length, stem_thickness));
		hydrangea.stem.setFillColor(sf::Color(0, 40, 0));

		hydrangea.stem.setOrigin(0.f, stem_thickness / 2.f);
		hydrangea.stem.setPosition(bottom);
		hydrangea.stem_rotation = angle_deg;
		hydrangea.stem.setRotation(angle_deg);

		float center_radius = r_center * 0.05f * (0.8f + gen_float() * 0.4f) * global_scale;
		hydrangea.center.setRadius(center_radius);
		hydrangea.center.setOrigin(center_radius, center_radius);
		hydrangea.center.setPosition(pos);
		hydrangea.center.setFillColor(color_gradient(hydrangea.color));
		hydrangea.pos = pos;

		int nb_sepals = 4;
		for (int j = 0; j < nb_sepals; ++j)
		{
			float phi = j * 3.14159265f / 2.f + gen_float() * 0.2f - 0.1f;
			float sepal_radius = r_center * 0.03f * (0.8f + gen_float() * 0.4f) * global_scale;
			float sepal_offset = sepal_radius * (0.8f + gen_float() * 0.4f);

			sf::Vector2f sepal_pos;
			sepal_pos.x = pos.x + sepal_offset * cos(phi);
			sepal_pos.y = pos.y + sepal_offset * sin(phi);

			sf::CircleShape sepal(sepal_radius);
			sepal.setOrigin(sepal_radius, sepal_radius);
			sepal.setPosition(sepal_pos);
			sepal.setFillColor(color_gradient(hydrangea.color));

			hydrangea.sepals.push_back(sepal);
			hydrangea.sepal_pos.push_back(sepal_pos);
		}

		hydrangeas->push_back(hydrangea);
	}
}

void Cvijet::draw()
{
	float time = clock.getElapsedTime().asSeconds();

	for (Hydrangea& h : hydrangeas) {
		float stem_wind = 4.f * sin(0.5f * time + h.pos.x * 0.1f);
		float angle = h.stem_rotation + 180.f + stem_wind;

		float rad = angle * 3.14159265f / 180.f;
		float length = h.stem.getSize().x;
		sf::Vector2f topOffset(length * cos(rad), length * sin(rad));

		h.stem.setRotation(angle);

		h.center.setPosition(h.stem.getPosition() + topOffset);

		for (size_t i = 0; i < h.sepals.size(); ++i) {
			float sepal_wind = 4.f * sin(0.5f * time * (1.f + 0.2f * i) + i);
			h.sepals[i].setPosition(h.center.getPosition().x + sepal_wind, h.center.getPosition().y);
		}

		window->draw(h.stem);
		window->draw(h.center);
		for (const sf::CircleShape& shape : h.sepals)
			window->draw(shape);
	}
}