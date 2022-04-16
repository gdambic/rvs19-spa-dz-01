#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window, int screen_width, int screen_height);
	void draw();
	void draw_row(std::vector<int>, sf::Vector2f w);
	void draw_coin(sf::Vector2f w);
	void draw_floor(sf::Vector2f w);
	void draw_wall(sf::Vector2f w);
	void draw_character();
	void move_character(char direction);
	void draw_environment();
	void scene_animation();
	void character_animation();
	bool collision(char direction);
	void gravity();
	unsigned int W = 800;
private:
	sf::RenderWindow *window;
	// screen/window resolution in px
	int X_WIDTH = 800;
	int Y_HEIGHT = 600;
	// clock is started for the scene
	sf::Clock clock;
	// clock for character animation
	sf::Clock frame;
	sf::Texture wall_texture;
	sf::Texture floor_texture;
	sf::Texture coin_texture;
	sf::Texture character_texture;
	// character position
	float X = 0.f;
	float Y = 344.f;
	// check if the character is able to jumping
	bool JUMP = true;
	// character speed
	float SPEED = 4.f;
	// character sheet is 512x64
    // create the sprite
	sf::Sprite character_sprite;
	// tile size is 64x64
	float TILE = 64.f;
	// size of array of tiles, i.e. row of tiles
	int COLUMN = 13;
	// level design, each arry represents the line
	// environment "flags": 0->empty, 1->brick; 2->top
	std::vector<int> row_9{ 0,0,0,0,0,0,0,0,0,0,0,0,0 }; //size = 13, (-40.f, 0.f)=> row_9 [0]...
	std::vector<int> row_8{ 0,0,0,0,0,0,0,0,0,0,0,0,0 }; //size = 13,  (24.f, 0.f)=> row_8 [0]...
	std::vector<int> row_7{ 0,0,0,0,0,0,0,0,0,0,0,0,0 }; //size = 13,  (88.f, 0.f)=> row_7 [0]...
	std::vector<int> row_6{ 0,0,0,0,0,0,0,0,0,3,3,0,0 }; //size = 13, (152.f, 0.f)=> row_6 [0]...
	std::vector<int> row_5{ 0,0,0,0,0,0,0,0,0,2,2,0,0 }; //size = 13, (216.f, 0.f)=> row_5 [0]...
	std::vector<int> row_4{ 0,0,0,0,0,0,0,0,0,0,0,0,1 }; //size = 13, (280.f, 0.f)=> row_4 [0]...
	std::vector<int> row_3{ 0,0,0,1,0,0,0,0,0,0,0,3,1 }; //size = 13, (344.f, 0.f)=> row_3 [0]...
	std::vector<int> row_2{ 1,0,0,1,1,1,0,0,0,0,0,1,1 }; //size = 13, (408.f, 0.f)=> row_2 [0]...
	std::vector<int> row_1{ 1,1,1,1,1,1,0,1,0,1,0,1,1 }; //size = 13, (472.f, 0.f)=> row_1 [0]...
	std::vector<int> row_0{ 1,1,1,1,1,1,0,1,0,1,0,1,1 }; //size = 13, (536.f, 0.f)=> row_0 [0]...
	// all rows
	std::vector<std::vector<int>> rows{ row_0,row_1,row_2,row_3,row_4,row_5,row_6,row_7,row_8,row_9 };
};

