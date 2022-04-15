#include "Cvijet.h"
#include <iostream>
#include <exception>

Cvijet::Cvijet(sf::RenderWindow* window)
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
}

void Cvijet::draw()
{
	scene_animation();
	draw_environment();
	//draw_flower(545.f, 365.f);
}

void Cvijet::draw_flower(float x, float y)
{
	// the root position "rt"
	sf::Vector2f rt(x, y);	
	// peduncle
	sf::RectangleShape peduncle(sf::Vector2f(200.f, 10.f));
	peduncle.setFillColor(sf::Color(123, 130, 53));
	peduncle.setOutlineThickness(2.f);
	peduncle.setOutlineColor(sf::Color(27, 27, 27));
	peduncle.setPosition(rt.x, rt.y);
	peduncle.rotate(90.f);
	// blossom
	sf::CircleShape petal(90.f, 10);
	petal.setFillColor(sf::Color(251, 169, 20));
	petal.setOutlineThickness(2.f);
	petal.setOutlineColor(sf::Color(27, 27, 27));
	petal.setPosition(rt.x - 95.f, rt.y - 170.f); //position relative to the root
	sf::CircleShape stamen(40.f);
	stamen.setFillColor(sf::Color(50, 36, 19));
	stamen.setOutlineThickness(10.f);
	stamen.setOutlineColor(sf::Color(223, 109, 38));
	stamen.setPosition(rt.x - 45.f, rt.y - 120.f); //position relative to the root
	// drawing all flower parts
	window->draw(peduncle);
	window->draw(petal);
	window->draw(stamen);
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
	case 'W': // move up
		Y -= TILE*2;
		character_sprite.setPosition(X, Y);
		break;
	case 'A': // move left
		X -= TILE;
		character_sprite.setPosition(X, Y);
		if (collision())
		{
			X += TILE;
			character_sprite.setPosition(X, Y);
		}
		break;
	case 'D': // move right
		X += TILE;
		character_sprite.setPosition(X, Y);
		if (collision())
		{
			X -= TILE;
			character_sprite.setPosition(X, Y);
		}
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
	for (int i = 0; i < ROW; i++)
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
	w.y = 536.f;

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
	back.setPoint(1, sf::Vector2f(800.f, 0.f));
	back.setPoint(2, sf::Vector2f(800.f, 600.f));
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

bool Cvijet::collision()
{
	// collision detection
	for (int i = 0; i < rows.size(); i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			float world_x = 0.f + TILE * j;
			float world_y = 536.f - TILE * i;
			if (world_x == X && world_y == Y)
			{
				if (rows[i][j] == 1 || rows[i][j] == 2)
				{
					return true;
				}
			}
		}
	}
	return false;	
}

void Cvijet::gravity()
{	
	try
	{
		while (!collision())
		{
			Y += TILE;
			character_sprite.setPosition(X, Y);
			if (collision())
			{
				Y -= TILE;
				character_sprite.setPosition(X, Y);
				break;
			}
		}
		throw 505;
	}
	catch (...)
	{
		std::cout << "\"gravity()\" method have some issues!" << std::endl;
	}
}

