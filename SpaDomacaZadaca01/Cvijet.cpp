#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow& window)
	: _window(window)
{
	set_num_of_peatles(24);
	init_petal(0);
	set_origin(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	set_font("OCRAEXT.TTF");
	set_text("Click and hold on window \nto do stuff...");
}

void Cvijet::clock_time()
{
	time_passed = clock.getElapsedTime();
}

sf::ConvexShape Cvijet::petal()
{
	sf::ConvexShape pt;
	pt.setPointCount(10);
	pt.setFillColor(sf::Color(255, 255, 255));

	pt.setPoint(0, sf::Vector2f(pt.getOrigin().x, pt.getOrigin().y));
	pt.setPoint(1, sf::Vector2f(pt.getOrigin().x - 20, pt.getOrigin().y - 10));
	pt.setPoint(2, sf::Vector2f(pt.getOrigin().x - 25, pt.getOrigin().y - 30));
	pt.setPoint(3, sf::Vector2f(pt.getOrigin().x - 27, pt.getOrigin().y - 50));
	pt.setPoint(4, sf::Vector2f(pt.getOrigin().x - 20, pt.getOrigin().y - 70));
	pt.setPoint(5, sf::Vector2f(pt.getOrigin().x, pt.getOrigin().y - 100));
	pt.setPoint(6, sf::Vector2f(pt.getOrigin().x + 20, pt.getOrigin().y - 70));
	pt.setPoint(7, sf::Vector2f(pt.getOrigin().x + 27, pt.getOrigin().y - 50));
	pt.setPoint(8, sf::Vector2f(pt.getOrigin().x + 25, pt.getOrigin().y - 30));
	pt.setPoint(9, sf::Vector2f(pt.getOrigin().x + 20, pt.getOrigin().y - 10));

	return pt;
}

void Cvijet::init_petal(int index)
{
	for (int i = 0; i < num_of_peatles; i++)
	{
		ptl.push_back(petal());
	}
}

void Cvijet::set_num_of_peatles(int num)
{
	this->num_of_peatles = num;
}

void Cvijet::circular_array(sf::RenderWindow& window, int index, sf::Vector2f origin, double angle_offset)
{
	double angle = 360 / num_of_peatles;
	double normal = angle;

	for (int i = 0; i < num_of_peatles; i++)
	{
		ptl[i].setFillColor(sf::Color(abs(sin(ptl[i].getRotation())) * 100, 0, 200));
		ptl[i].setScale(0.7, 1.5);

		ptl[i].setPosition(sf::Vector2f(origin.x + cos(normal) * 0.1, origin.y + sin(normal) * 0.1));
		ptl[i].setRotation(normal + angle_offset);
		window.draw(ptl[i]);
		normal += angle;
	}
}

void Cvijet::background(sf::RenderWindow& window)
{
	sf::RectangleShape sky;
	sky.setFillColor(sf::Color(52, 198, 235));
	sky.setSize(sf::Vector2f(800, 600));

	sf::CircleShape floor(50);
	floor.setFillColor(sf::Color(68, 237, 52));
	floor.setOrigin(sf::Vector2f(floor.getRadius(), floor.getRadius()));
	floor.setPosition(sf::Vector2f(400, 600));
	floor.setScale(sf::Vector2f(10, 2));


	window.draw(sky);

	draw_hill(window, sf::Vector2f(175, 100), 70, sf::Color(31, 201, 6));
	draw_hill(window, sf::Vector2f(300, 350), 80, sf::Color(51, 168, 34));
	draw_hill(window, sf::Vector2f(500, 100), 50, sf::Color(24, 107, 12));
	draw_hill(window, sf::Vector2f(550, 250), 60, sf::Color(51, 168, 34));
	draw_hill(window, sf::Vector2f(750, 300), 70, sf::Color(24, 107, 12));

	window.draw(floor);
}

void Cvijet::draw_hill(sf::RenderWindow& window, sf::Vector2f pos, double radius, sf::Color color)
{
	sf::CircleShape tip(radius);
	sf::RectangleShape base(sf::Vector2f(tip.getRadius() * 2, window.getSize().y + 200));

	base.setFillColor(color);
	tip.setFillColor(color);

	base.setPosition(sf::Vector2f(0, tip.getRadius()));
	base.setOrigin(tip.getOrigin());
	tip.setOrigin(sf::Vector2f(tip.getRadius(), tip.getRadius()));

	tip.setPosition(sf::Vector2f(pos));
	base.setPosition(sf::Vector2f(tip.getPosition()) + sf::Vector2f(tip.getRadius() * -1, 0));

	window.draw(base);
	window.draw(tip);
}

void Cvijet::draw_stem(sf::RenderWindow& window)
{
	sf::ConvexShape s;
	s.setPointCount(4);

	s.setPoint(0, sf::Vector2f((window.getSize().x / 2) + 2, window.getSize().y + 10));
	s.setPoint(1, lerp_pos + sf::Vector2f(2, movement));
	s.setPoint(2, lerp_pos + sf::Vector2f(-2, movement));
	s.setPoint(3, sf::Vector2f((window.getSize().x / 2) - 2, window.getSize().y + 10));


	s.setOutlineColor(sf::Color(0, 115, 10));
	s.setOutlineThickness(10);
	s.setFillColor(s.getOutlineColor());

	window.draw(s);
}

void Cvijet::get_input(sf::RenderWindow& window)
{
	mouse_pos = sf::Mouse::getPosition(window);
}

void Cvijet::move_flower(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		lerp_pos = lerp(origin_pos, sf::Vector2f(mouse_pos), pow(clamp(0, 1, button_press_time += 0.1), 3));
		circular_array(window, 0, lerp_pos + sf::Vector2f(0, movement), time_passed.asSeconds() * 10);
	}
	else
	{
		lerp_pos = lerp(origin_pos, sf::Vector2f(mouse_pos), pow(clamp(0, 1, button_press_time -= 0.01), 5));
		circular_array(window, 0, lerp_pos + sf::Vector2f(0, movement), time_passed.asSeconds() * 10);
	}
}

void Cvijet::set_origin(sf::Vector2f pos)
{
	this->origin_pos = pos;
}

void Cvijet::draw_center(sf::RenderWindow& window)
{
	sf::CircleShape c(40);
	c.setOrigin(sf::Vector2f(c.getRadius(), c.getRadius()));
	c.setPosition(lerp_pos + sf::Vector2f(0, movement));
	c.setFillColor(sf::Color(255, 200, 0));
	c.setOutlineColor(sf::Color(255, 153, 0));
	c.setOutlineThickness(10);
	window.draw(c);
}

void Cvijet::draw_leaf(sf::RenderWindow& window, double pos, double rot, sf::Vector2f scale, sf::Color color)
{
	sf::ConvexShape l;

	l = petal();
	l.setPosition(lerp(lerp_pos, sf::Vector2f(window.getSize().x / 2, window.getSize().y), pos));
	l.setRotation(rot);
	l.setScale(scale);
	l.setFillColor(color);

	window.draw(l);
}

float Cvijet::clamp(float min, float max, float& value)
{
	if (value >= max)
	{
		value = max;
		return max;
	}
	else if (value <= min)
	{
		value = min;
		return min;
	}
	else
	{
		return value;
	}
}

void Cvijet::calculate_dis()
{
	this->dis = sqrt(pow(lerp_pos.x - origin_pos.x, 2) + pow(lerp_pos.y - origin_pos.y, 2));
}

void Cvijet::calculate_movement()
{
	this->movement = sin(time_passed.asSeconds() * (dis / 20 + 1)) * 10;
}

void Cvijet::set_text(string text)
{
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setPosition(sf::Vector2f(0, 500));
	this->text.setCharacterSize(48);
	this->text.setFillColor(sf::Color(0, 0, 0));
}

void Cvijet::set_font(string font)
{
	this->font.loadFromFile(font);
}

sf::Vector2f Cvijet::lerp(sf::Vector2f pos_a, sf::Vector2f pos_b, float translate)
{
	if (translate > 1.f)
	{
		return pos_b;
	}
	else if (translate < 0.f)
	{
		return pos_a;
	}
	else
	{
		return sf::Vector2f() = pos_a * (1 - translate) + translate * pos_b;
	}
}

void Cvijet::draw()
{
	clock_time();
	calculate_dis();
	calculate_movement();
	background(_window);

	draw_leaf(_window, 0.7, 60 + movement, sf::Vector2f(1.2, 2), sf::Color(0, 143, 14));
	draw_leaf(_window, 0.6, -70 - movement, sf::Vector2f(1, 2.2), sf::Color(0, 143, 14));
	draw_stem(_window);

	get_input(_window);
	move_flower(_window);

	draw_center(_window);
	_window.draw(text);
}
