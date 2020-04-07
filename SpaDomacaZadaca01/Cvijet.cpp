#include "Cvijet.h"
#include <SFML/Graphics.hpp>

void Cvijet::draw_petal(sf::Color boja, int cur_velicina, int br_latica, int max_velicina)
{
	int curr_petal =0;
	for (size_t i = 1; i <= br_latica; i++)
	{
		if (cur_velicina > max_velicina*i)
		{
			curr_petal++;
		}
	}
	this->shape.setFillColor(boja);
	for (int i = 0; i <= curr_petal; i++)
	{
		int frame_length = 0;
		if (i == curr_petal)
		{
			frame_length = cur_velicina - max_velicina * i;
		}
		else
		{
			frame_length = max_velicina;
		}
		this->shape.rotate(360 / br_latica);
		for (size_t i = 1; i < frame_length; i++)
		{
			this->shape.setRadius(i);
			this->window->draw(this->shape);
		}
	}
}

void Cvijet::draw_stem(int duljina)
{
	this->shape.setRadius(5.f);
	this->shape.setRotation(0);
	this->shape.setFillColor(sf::Color(100, 250, 50));
	for (size_t i = 0; i < duljina; i++)
	{
		int offset[2] = { 400,350 };
		double scalar = 50;
		this->shape.setPosition(scalar * sin(i / scalar / 2) + offset[1], -1 * i + offset[0]);
		this->window->draw(this->shape);
		//this->window->display();
	}
}


Cvijet::Cvijet(sf::RenderWindow* win)
{
	this->window = win;
	this->frame = 1;
}

void Cvijet::draw()
{
	int br_latica = 5;
	int dulj_linije = 300;
	int vel_rozog = 40;
	int vel_zutog = 10;

	sf::RectangleShape rec;
	rec.setFillColor(sf::Color(97, 182, 185));
	rec.setSize(sf::Vector2f(800.f, 600.f));
	this->window->draw(rec);
	rec.setFillColor(sf::Color(100, 250, 50));
	rec.setSize(sf::Vector2f(800.f, 300.f));
	rec.setPosition(0, 350);
	this->window->draw(rec);
	
	if (this->frame<= dulj_linije)
	{
		draw_stem(this->frame);
		this->frame++;
		return;
	}
	if (this->frame<=dulj_linije+vel_rozog*br_latica)
	{
		draw_stem(dulj_linije);
		draw_petal(sf::Color(218, 47, 166), this->frame - dulj_linije, br_latica, vel_rozog);
		this->frame++;
		return;
	}
	if (this->frame<=dulj_linije+vel_rozog*br_latica+vel_zutog*br_latica)
	{
		draw_stem(dulj_linije);
		draw_petal(sf::Color(218, 47, 166), vel_rozog*br_latica, br_latica, vel_rozog);
		draw_petal(sf::Color(201, 218, 47), this->frame - dulj_linije-(vel_rozog*br_latica) , br_latica, vel_zutog);
		this->frame++;
		return;
	}
	if (this->frame > dulj_linije + vel_rozog * br_latica + vel_zutog * br_latica)
	{
		sf::Time elapsed;
		sf::Time pauseTime=sf::seconds(1);
		sf::Clock pauseClock;
		while ( elapsed != pauseTime)
		{
			elapsed = pauseClock.getElapsedTime();
		}
		this->frame = 0;
	}
}