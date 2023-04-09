#include "Flowie.h"

#include <SFML/Graphics.hpp>
#include "SFML/System/Vector2.hpp"

#include <vector>
#include <random>
#include <math.h>

#include <iostream>;

Flowie::Flowie(sf::Color _petal_color, sf::RenderWindow& window)
{
	std::random_device rd;
	random_gen = std::mt19937{ rd() };
	//std::cout << dist(random_gen) << std::endl;

	petal_color = _petal_color;

	generate_frames();
	generate_background(window);

	head.setTexture(frames[current_frame]);
	head.setOrigin(head.getTexture()->getSize().x / 2.f, head.getTexture()->getSize().y / 2.f);
	head.setPosition(window.getSize().x / 2.f, window.getSize().y / 1.5);

	other.setTexture(background);
	//We use sprites to switch between frames since they're very lightweight.
	//They also allow us to scale the flowerhead, giving us a rotating upwards effect.
}

//generates a frame for every degree we'll need 
void Flowie::generate_frames()
{
	int render_texture_size = 400;
	int radius = 50;

	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPosition(render_texture_size / 2.f, render_texture_size / 2.f);

	for (int index = 0; index < 18; index++)
	{
		sf::RenderTexture render_target;
		render_target.create(render_texture_size, render_texture_size);

		//Abuses bad centre-of-object logic to lazily create flower petals
		circle.setOrigin(0.f, 0.f);
		circle.setScale(0.2, 1);
		circle.setOutlineThickness(-4);
		circle.setOutlineColor(sf::Color::Black);
		circle.setRotation(-index);//Rotate it counter-clockwise

		circle.setFillColor(petal_color);
		render_target.draw(circle);
		for (size_t i = 0; i <= 18; i++)
		{
			circle.rotate(18);
			render_target.draw(circle);
		}

		//Now the centre
		circle.setOutlineThickness(1);
		circle.setFillColor(sf::Color::Yellow);
		circle.setScale(0.8, 0.8);
		circle.setOrigin(radius, radius);
		render_target.draw(circle);

		render_target.display();

		frames.emplace_back(render_target.getTexture());
	}
}

//Run after generate_frames()
void Flowie::generate_background(sf::RenderWindow& window)
{
	sf::Color foreground_green = { 34, 139, 34 };
	sf::Color background_green = { 50, 205, 50 };
	sf::Color sky = { 254, 177, 37 };
	sf::Color sun = { 252, 225, 61 };

	sf::RenderTexture render_target;
	sf::Vector2f size;
	size.x = window.getSize().x;
	size.y = window.getSize().y;

	render_target.create(size.x, size.y);

	sf::RectangleShape rectangle;
	rectangle.setSize(size);
	rectangle.setFillColor(sky);
	render_target.draw(rectangle);

	sf::CircleShape circle;

	circle.setFillColor(sun);
	circle.setScale(1, 1);
	circle.setRadius(size.x / 15);
	circle.setPosition(size.x / 8, size.y / 1.6);
	circle.setOrigin(0, 0);
	render_target.draw(circle);

	//Prepare(admittably really ugly) clouds
	{
		sf::RenderTexture cloud_create;
		cloud_create.create(size.x / 4, size.y / 4);

		circle.setOrigin(0, 0);
		circle.setRadius(size.x / 40);
		circle.setFillColor(sf::Color::White);
		circle.setScale(1, 1);

		circle.setPosition(size.x / 60, size.y / 60);
		cloud_create.draw(circle);
		circle.move(size.x / 40, -size.y / 150);
		cloud_create.draw(circle);
		circle.move(size.x / 40, size.y / 150);
		cloud_create.draw(circle);
		circle.move(size.x / 100, size.y / 60);
		cloud_create.draw(circle);
		circle.move(-size.x / 100, size.y / 60);
		cloud_create.draw(circle);
		circle.move(-size.x / 40, size.y / 150);
		cloud_create.draw(circle);
		circle.move(-size.x / 40, -size.y / 150);
		cloud_create.draw(circle);
		circle.move(-size.x / 100, -size.y / 60);
		cloud_create.draw(circle);

		cloud_create.display();
		sf::Sprite cloud(cloud_create.getTexture());
		//Now we place them
		cloud.setPosition(size.x / 8, size.y / 1.9);
		cloud.setScale(0.5, 0.3);
		render_target.draw(cloud);

		cloud.setPosition(size.x / 3, size.y / 2);
		cloud.setScale(0.6, 0.4);
		render_target.draw(cloud);

		cloud.setPosition(size.x / 1.3, size.y / 1.95);
		cloud.setScale(0.5, 0.4);
		render_target.draw(cloud);

		cloud.setPosition(size.x / 1.7, size.y / 2.5);
		cloud.setScale(1, 0.7);
		render_target.draw(cloud);

		cloud.setPosition(size.x / 5, size.y / 4.5);
		cloud.setScale(2.5, 1.7);
		render_target.draw(cloud);

		cloud.setPosition(size.x / 1.8, -size.y / 10);
		cloud.setScale(5, 3);
		render_target.draw(cloud);

		cloud.setPosition(-size.x / 20, -size.y / 6);
		cloud.setScale(4.7, 2.8);
		render_target.draw(cloud);
	}

	//Now things closer to the front
	circle.setFillColor(foreground_green);
	circle.setRadius(size.x);
	circle.setScale(1, 0.3);
	circle.setOrigin(circle.getOrigin().x, circle.getRadius());
	circle.setPosition(-size.x / 5, size.y);
	render_target.draw(circle);

	circle.setFillColor(background_green);
	circle.move(-size.x / 2, size.y / 6);
	render_target.draw(circle);

	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setOrigin(0, -size.y / 2 - size.y / 6);
	rectangle.setPosition(head.getPosition().x, head.getPosition().y);
	rectangle.move(size.x / 2.05, 0);
	rectangle.setScale(0.02, 1);
	render_target.draw(rectangle);

	render_target.display();
	background = render_target.getTexture();
}

//Ideally we would pass time difference and be frame-independent
//but that would be overcomplicating it more than it already is
void Flowie::process()
{
	if (degrees_per_frame > 0) {
		++curr_frames;
		while (curr_frames >= 1 / degrees_per_frame) {
			current_frame++;
			if (current_frame + 1 > frames.size()) {
				current_frame = 0;
			}
			curr_frames -= 1 / degrees_per_frame;
		}
		head.setTexture(frames[current_frame]);

		float scale_y = 1 - (log(degrees_per_frame + 1) / 2.5);
		if (scale_y < 0.15) {
			scale_y = 0.15;
		}
		head.setScale(1, scale_y);
	}
	degrees_per_frame += 0.01;
	std::cout << degrees_per_frame << std::endl;

	if (degrees_per_frame > 9.8) {
		float move = degrees_per_frame - 9.8;
		head.setPosition(head.getPosition().x + 1 / (degrees_per_frame / 3), head.getPosition().y - move);
	}
}

void Flowie::draw(sf::RenderWindow& window)
{
	window.draw(other);
	window.draw(head);
}

void Flowie::reset(sf::RenderWindow& window)
{
	head.setPosition(window.getSize().x / 2.f, window.getSize().y / 1.5);
	degrees_per_frame = 0;
	current_frame = 0;
}
