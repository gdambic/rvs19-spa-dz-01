#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <random>
//Bindly assume 60 fps
//Because we can
class Flowie
{
private:
	int orig_x = 0;
	int orig_y = 0;
	//Did the player reach 9.8 spin? If so, the game starts.
	bool ready = false;

	float velocity_x = 0;
	float velocity_y = 0;
	float air_resistance_factor = 0.9;
	float rotation_speed = 0.8;
	float RPM_change = 0.05;

	//The cooler random
	std::mt19937 random_gen;

	int frame_num_total = 0;
	float degrees_per_frame = 0;//we generated frames for every degree
	float frames_animate_tracker = 0;
	int current_frame = 0;

	float enemies_per_frame = 0;
	float frames_enemy_tracker = 0;
	int enemy_collision_dist = 40;
	float enemy_default_scale = 0.2;
	//How much does enemies_per_frame rise every frame?
	float enemy_spawn_difficulty = 0.00002;

	sf::Sprite head;
	sf::Sprite other;
	sf::Sprite enemy;

	sf::Color petal_color;
	sf::Texture background;
	sf::Texture enemy_texture;
	std::vector < sf::Texture > frames;

	void generate_frames();
	void generate_background(sf::RenderWindow& window);

	struct Enemy{
		int x = 0;
		int y = 0;
		float speed = 5;
		/// false is left, true is right
		bool direction = true;
	};
	std::list<Enemy>enemy_list;
public:
	Flowie(sf::Color _petal_color, sf::RenderWindow& window);
	void process(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void reset(sf::RenderWindow& window);

	void rotate_left();
	void rotate_right();
	void RPM_UP();
	void RPM_DOWN();
};