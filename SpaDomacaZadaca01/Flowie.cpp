#include "Flowie.h"

#include <SFML/Graphics.hpp>
#include "SFML/System/Vector2.hpp"

#include <vector>
#include <random>
#include <cmath>

#include <iostream>;

Flowie::Flowie(sf::Color _petal_color, sf::RenderWindow& window)
{
	std::random_device rd;
	random_gen = std::mt19937{ rd() };
	//std::cout << dist(random_gen) << std::endl;

	petal_color = _petal_color;

	generate_frames();
	generate_background(window);
	if (!enemy_texture.loadFromFile("yellow-jacket.png")) {
		std::cout << "ERROR: enemy texture not located." << std::endl;
		exit(1);
	}

	//We use these sprites to switch between frames since they're very lightweight.
	//They also allow us to scale the flowerhead, giving us a "rotating upwards" effect.
	head.setTexture(frames[current_frame]);
	head.setOrigin(head.getTexture()->getSize().x / 2.f, head.getTexture()->getSize().y / 2.f);
	head.setPosition(window.getSize().x / 2.f, window.getSize().y / 1.5);
	orig_x = head.getPosition().x;
	orig_y = head.getPosition().y;

	other.setTexture(background);
	enemy.setTexture(enemy_texture);
	enemy.setOrigin(enemy_texture.getSize().x / 2.f, enemy_texture.getSize().y / 2.f);
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

	//Now draw things closer to the front
	{
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
	}

	render_target.display();
	background = render_target.getTexture();
}

//I should really segment this one but I have no time
//Ideally we would pass time difference and be frame-independent
//but that would be overcomplicating it more than it already is
///This is basically a monster function that does all the work
void Flowie::process(sf::RenderWindow& window)
{
	++frames_animate_tracker;
	while (frames_animate_tracker >= 1 / degrees_per_frame) {
		current_frame++;
		if (current_frame + 1 > frames.size()) {
			current_frame = 0;
		}
		frames_animate_tracker -= 1 / degrees_per_frame;
	}
	head.setTexture(frames[current_frame]);

	float scale_y = 1 - (log(degrees_per_frame + 1) / 2.5);
	if (scale_y < 0.15) {
		scale_y = 0.15;
	}
	head.setScale(1, scale_y);
	
	std::cout << degrees_per_frame << std::endl;

	if (!ready) {
		if (degrees_per_frame < 9.8) {
			return;
		}
		ready = true;
	}

	//gradual difficulty increase
	enemies_per_frame += enemy_spawn_difficulty;
	//Spawn the hostiles
	++frames_enemy_tracker;
	while (frames_enemy_tracker >= 1 / enemies_per_frame) {
		frames_enemy_tracker -= 1 / enemies_per_frame;

		Enemy hostile;
		hostile.direction = random_gen() % 2;
		if (hostile.direction == false) {
			hostile.x = window.getSize().x;
		}
		std::uniform_int_distribution<int> dist{ 0, int(window.getSize().y)};
		hostile.y = dist(random_gen);
		hostile.speed -= dist(random_gen) % 2;
		enemy_list.push_back(hostile);
	}

	//Process the hostiles
	if(!enemy_list.empty()){
		for (auto it = enemy_list.begin(); it != enemy_list.end();)
		{
			std::uniform_int_distribution<int> dist{ -2, 2 };
			it->y += dist(random_gen);
			if (it->direction) {
				it->x += it->speed;
			}
			else {
				it->x -= it->speed;
			}

			if (sqrt(pow(abs(it->x - head.getPosition().x), 2) + (pow(abs(it->y - head.getPosition().y), 2)))
				<= enemy_collision_dist) {

				std::cout << "X" << it->x << std::endl;
				std::cout << "Y" << it->y << std::endl;
				reset(window);
				//I used to be an adventurer like you, but then I took an
				//[ERROR:cannot dereference value-initialized list iterator]
				//to the knee.
				break;
			}

			if (it->x > window.getSize().x + enemy_texture.getSize().x * enemy_default_scale ||
				it->x < 0 - enemy_texture.getSize().x * enemy_default_scale ||
				it->y > window.getSize().y + enemy_texture.getSize().y * enemy_default_scale ||
				it->y < 0 - enemy_texture.getSize().y * enemy_default_scale) {

				it = enemy_list.erase(it);
			}
			else {
				++it;
			}
		}
	}

	float rotation = head.getRotation() + 90;
	float move = degrees_per_frame;
	//Expects radians
	velocity_x += - move * cos(rotation / 180 * 3.14159);
	velocity_y += -move * sin(rotation / 180 * 3.14159) + 9.8;
	velocity_x *= air_resistance_factor;
	velocity_y *= air_resistance_factor;

	if (head.getPosition().x < 0 && velocity_x < 0) {
		velocity_x *= -1;
	}
	if (head.getPosition().x > window.getSize().x && velocity_x > 0) {
		velocity_x *= -1;
	}
	if (head.getPosition().y < 0 && velocity_y < 0) {
		velocity_y *= -1;
	}
	if (head.getPosition().y > window.getSize().y - 20 && velocity_y > 0) {
		velocity_y = 0;
	}
	if (head.getPosition().y > orig_y && head.getPosition().y < orig_y + 10 &&
		head.getPosition().x > orig_x - 10 && head.getPosition().x < orig_x + 10 && velocity_y > 0) {
		velocity_y = 0;
		velocity_x = 0;
	}

	head.move(velocity_x, velocity_y);
}

void Flowie::draw(sf::RenderWindow& window)
{
	window.draw(other);
	window.draw(head);


	if (!enemy_list.empty()) {
		for (auto it = enemy_list.begin(); it != enemy_list.end(); it++) {
			enemy_default_scale;
			enemy.setPosition(it->x, it->y);
			if (it->direction) {
				enemy.setScale(enemy_default_scale, enemy_default_scale);
			}
			else {
				enemy.setScale(-enemy_default_scale, enemy_default_scale);
			}
			window.draw(enemy);
		}
	}
}

void Flowie::reset(sf::RenderWindow& window)
{
	ready = false;
	head.setPosition(window.getSize().x / 2.f, window.getSize().y / 1.5);
	degrees_per_frame = 0;
	enemies_per_frame = 0;
	head.setRotation(0);
	current_frame = 0;
	enemy_list.clear();
	velocity_x = 0;
	velocity_y = 0;
}

void Flowie::rotate_left()
{
	if (!ready)
		return;
	head.rotate(-rotation_speed);
}

void Flowie::rotate_right()
{
	if (!ready)
		return;
	head.rotate(rotation_speed);
}

void Flowie::RPM_UP()
{
	degrees_per_frame += RPM_change;
}

void Flowie::RPM_DOWN()
{
	degrees_per_frame -= RPM_change;
	if (degrees_per_frame < 0) {
		degrees_per_frame *= -1;
	}
}
