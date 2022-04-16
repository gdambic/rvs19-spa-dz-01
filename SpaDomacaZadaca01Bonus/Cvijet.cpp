#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window, int screen_width, int screen_height)
{
	this->window = window;
	sf::Clock clock = this->clock;
	// load the wall texture (64x64)
	sf::Texture wall_texture;
	if (!wall_texture.loadFromFile("stone_wall.png"))
	{
		std::cout << "Something went wrong while opening the file: \"stone_wall.png\"" << std::endl;
	}
	this->wall_texture = wall_texture;
	// load the floor texture (64x64)
	sf::Texture floor_texture;
	if (!floor_texture.loadFromFile("stone_floor.png"))
	{
		std::cout << "Something went wrong while opening the file: \"stone_floor.png\"" << std::endl;
	}
	this->floor_texture = floor_texture;
	// load the coin texture
	sf::Texture coin_texture;
	if (!coin_texture.loadFromFile("Coin.gif"))
	{
		std::cout << "Something went wrong while opening the file: \"Coin.gif\"" << std::endl;
	}
	this->coin_texture = coin_texture;
	// load the character texture sheet
	sf::Texture character_texture;
	if (!character_texture.loadFromFile("character_sheet.png"))
	{
		std::cout << "Something went wrong while opening the file: \"character_sheet.png\"" << std::endl;
	}
	this->character_texture = character_texture;
	// character initial position and frame
	character_sprite.setPosition(X, Y);
	character_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	// screen resolution
	X_WIDTH = screen_width;
	Y_HEIGHT = screen_height;
}

void Cvijet::draw()
{
	scene_animation();
	draw_environment();
}

void Cvijet::draw_wall(sf::Vector2f w)
{
	// create the sprite
	sf::Sprite wall_sprite;
	wall_sprite.setTexture(wall_texture);
	// sprite position
	wall_sprite.setPosition(w.x, w.y);
	// draw the sprite
	window->draw(wall_sprite);
}

void Cvijet::draw_floor(sf::Vector2f w)
{
	// create the sprite
	sf::Sprite floor_sprite;
	floor_sprite.setTexture(floor_texture);
	// sprite position
	floor_sprite.setPosition(w.x, w.y);
	// draw the sprite
	window->draw(floor_sprite);
}

void Cvijet::draw_coin(sf::Vector2f w)
{
	// create the sprite
	sf::Sprite coin_sprite;
	coin_sprite.setTexture(coin_texture);
	// sprite position
	coin_sprite.setPosition(w.x, w.y);
	// draw the sprite
	window->draw(coin_sprite);
}

void Cvijet::draw_character()
{
	character_sprite.setTexture(character_texture);
	// draw the sprite
	window->draw(character_sprite);
}

void Cvijet::move_character(char direction)
{
	character_animation();
	switch (direction)
	{
	case 'W': // JUMP
		if (JUMP)
		{
			Y -= TILE * 2;
			character_sprite.setPosition(X, Y);
		}
		break;
	case 'A': // move left
		X -= SPEED;
		if (collision('n'))
		{
			X += SPEED;
		}
		character_sprite.setPosition(X, Y);
		break;
	case 'D': // move right
		X += SPEED;
		if (collision('n'))
		{
			X -= SPEED;
		}
		character_sprite.setPosition(X, Y);
		break;
	}
}

void Cvijet::character_animation()
{
	// when arrow (up, down, left, right) is pressed character animation is updated
	sf::Time elapsed = frame.getElapsedTime();
	float sec = elapsed.asSeconds();

	if (sec < 0.25)
	{
		character_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 0.5)
	{
		character_sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 0.75)
	{
		character_sprite.setTextureRect(sf::IntRect(128, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 1)
	{
		character_sprite.setTextureRect(sf::IntRect(192, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 1.25)
	{
		character_sprite.setTextureRect(sf::IntRect(256, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 1.5)
	{
		character_sprite.setTextureRect(sf::IntRect(320, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 1.75)
	{
		character_sprite.setTextureRect(sf::IntRect(384, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else if (sec < 2)
	{
		character_sprite.setTextureRect(sf::IntRect(448, 0, 64, 64));
		character_sprite.setTexture(character_texture);
	}
	else
	{
		frame.restart();
	}
}

void Cvijet::draw_row(std::vector<int> row, sf::Vector2f w)
{
	for (int i = 0; i < COLUMN; i++)
	{
		if (row[i] == 0)
		{
			w.x += TILE;
			continue;
		}
		else if (row[i] == 1)
		{
			draw_wall(w);
			w.x += TILE;
		}
		else if (row[i] == 2)
		{
			draw_floor(w);
			w.x += TILE;
		}
		else if (row[i] == 3)
		{
			draw_coin(w);
			w.x += TILE;
		}
	}
}

void Cvijet::draw_environment()
{	
	// initial position of a wall
	sf::Vector2f w;
	w.x = 0.f;
	w.y = Y_HEIGHT - TILE;

	// draw row by row
	for (int i = 0; i < rows.size(); i++)
	{
		draw_row(rows[i], w);
		w.y -= TILE;
	}
}

void Cvijet::scene_animation()
{	
	sf::Time elapsed = clock.getElapsedTime();
	float sec = elapsed.asSeconds();

	// create background color
	sf::ConvexShape back;
	back.setPointCount(8);
	back.setPoint(0, sf::Vector2f(0.f, 0.f));
	back.setPoint(1, sf::Vector2f(X_WIDTH, 0.f));
	back.setPoint(2, sf::Vector2f(X_WIDTH, Y_HEIGHT));
	back.setPoint(3, sf::Vector2f(0.f, 600.f));

	//create the Sun
	sf::CircleShape sun(90.f);

	if (sec >= 24.f)
	{
		clock.restart();
	}
	else
	{
		// update background color
		back.setFillColor(sf::Color(58, 59, 139));
		int red_b = 18 + (8 * sec);
		int green_b = 19 + (8 * sec);
		int blue_b = 39 + (8 * sec);
		back.setFillColor(sf::Color(red_b, green_b, blue_b));
		// drawing the background
		window->draw(back);

		// update Sun color
		int red_s = 226 + sec;
		int green_s = 101 + (6 * sec);
		sun.setFillColor(sf::Color(red_s, green_s, 60));
		// update Sun position
		int speed = 12;
		float move_x = 450.f - (12.f + (sec * speed));
		float move_y = 480.f - (sec * speed * 2);
		sun.setPosition(move_x, move_y);
		// update Sun size
		float size = 90.f - (sec * 2);
		sun.setRadius(size);
		// drawing the Sun
		window->draw(sun);
	}
}

bool Cvijet::collision(char direction)
{	
	// Character collision coordinates
	float col_x = X;
	float col_y = Y;	
	switch (direction)
	{
	case 'n':
		//do (n)othing
		break;
	case 'S':
		col_y += TILE - SPEED;
		break;
	}
	// world speed index
	int q = TILE / SPEED;
	// TILES collision detection
	for (int i = 0; i < rows.size() * q; i++)
	{
		for (int j = 0; j < COLUMN * q; j++)
		{
			// world collision coordinates
			float world_x = (-TILE / 2) + (SPEED * j);
			float world_y = (Y_HEIGHT - SPEED) - (SPEED * i);
			if (world_x == col_x && world_y == col_y)
			{
				if (rows[i / q][j / q] == 1 || rows[i / q][j / q] == 2)
				{
					return true;
				}
			}
		}
	}
	// screen collision detection
	if (X < 0.f)
	{	//left end of the screen
		X = 0.f;
	}
	if (X > X_WIDTH)
	{	//right end of the screen
		X = X_WIDTH - TILE;
	}
	if (Y > Y_HEIGHT)
	{	// Game Over, i.e. player position is restarted
		X = 0.f;
		Y = 344.f;
	}
	return false;	
}

void Cvijet::gravity()
{	
	if (!collision('S'))
	{
		Y += SPEED * 2;
		// jumping not possieble in the air
		JUMP = false;
		character_sprite.setPosition(X, Y);
		if (collision('S'))
		{
			Y -= SPEED * 2;
			character_sprite.setPosition(X, Y);
			// jumping allowed when character is on the ground
			JUMP = true; 
		}
	}
}

