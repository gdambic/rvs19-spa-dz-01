#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
//Bindly assume 60 fps
//Because we can
class Flowie
{
private:
	int x = 0;
	int y = 0;

	//The cooler random
	std::mt19937 random_gen;
	std::uniform_int_distribution<int> dist{ 1, 5 };

	int frame_num_total = 0;
	float degrees_per_frame = 1;//we generated frames for every degree
	float curr_frames = 0;
	int current_frame = 0;

	sf::Sprite head;
	sf::Sprite other;

	sf::Color petal_color;
	sf::Texture background;
	std::vector < sf::Texture > frames;

	void generate_frames();
	void generate_background(sf::RenderWindow& window);
public:
	Flowie(sf::Color _petal_color, sf::RenderWindow& window);
	void process();
	void draw(sf::RenderWindow& window);
	void reset(sf::RenderWindow& window);
};