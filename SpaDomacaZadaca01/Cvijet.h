#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
using namespace std;

class Cvijet
{
private:
	sf::RenderWindow& _window;
	sf::Time time_passed;
	sf::Clock clock;
	vector<sf::ConvexShape> ptl;

	int _index;
	int num_of_peatles; // for multiple layers of petales

	sf::Vector2i mouse_pos;
	sf::Vector2f origin_pos;
	float button_press_time;

	sf::Vector2f lerp_pos;
	float dis = 0;

	float movement;

	sf::Text text;
	sf::Font font;

public:
	Cvijet(sf::RenderWindow& window);
	void clock_time();

	sf::ConvexShape petal();
	void init_petal(int index);

	void set_num_of_peatles(int num);
	void circular_array(sf::RenderWindow& window, int index, sf::Vector2f origin, double angle_offset);

	void background(sf::RenderWindow& window);
	void draw_hill(sf::RenderWindow& window, sf::Vector2f pos, double radius, sf::Color color);

	void draw_stem(sf::RenderWindow& window);

	void get_input(sf::RenderWindow& window);
	void move_flower(sf::RenderWindow& window);
	void set_origin(sf::Vector2f pos);
	void draw_center(sf::RenderWindow& window);

	void draw_leaf(sf::RenderWindow& window, double pos, double rot, sf::Vector2f scale, sf::Color color);

	float clamp(float min, float max, float& value);
	void calculate_dis();
	void calculate_movement();

	void set_text(string text);
	void set_font(string font);

	sf::Vector2f lerp(sf::Vector2f pos_a, sf::Vector2f pos_b, float translate);

	void draw();
};

