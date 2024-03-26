#include "Cvijet.h"
#include <vector>
#include <ctime>
#include <random>
#include <iostream>

RectangleShape Cvijet::drawBg(Color color, Vector2f size)
{
	RectangleShape bg(size);
	bg.setFillColor(color);
	return bg;
}

CircleShape Cvijet::drawPetal(Color color, float size, Vector2f position, Vector2f scale)
{

	CircleShape petal(size);
	petal.setFillColor(color);
	petal.scale(scale);
	petal.move(position);


	return petal;
}

CircleShape Cvijet::drawCloud(Color color, Vector2f position, Vector2f scale)
{
	srand(9);
	CircleShape cloud(10.f);
	cloud.setFillColor(color);
	cloud.setPosition(position);
	cloud.setScale(scale);


	return cloud;
}

CircleShape Cvijet::drawSunRay(Color color, float size, Vector2f position, Vector2f scale, float rotation)
{
	CircleShape ray(size, 3);
	ray.setFillColor(color);
	ray.scale(scale);
	ray.move(position);
	ray.setRotation(rotation);
	return ray;
}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}


void Cvijet::draw()
{
	//time initiation
	Time time = clock.getElapsedTime();
	std::cout << (time.asSeconds()) << std::endl;

	//time restart
	if (time.asSeconds() > 10)
	{
		clock.restart();
	}



	//draw field
	window->draw(drawBg({ 17,124,19 }, { 1000.f, 1000.f }));

	//draw sky
	window->draw(drawBg({ 135, 206, 235 }, { 1000.f, 250.f }));

	//draw first cloud
	//for (size_t i = 0; i < 30; i++)
	//{
	//	window->draw(drawCloud(
	//		{ 150,150,150 },
	//		{ 500.f, 50.f },
	//		{(float)(rand() % 8), (float)(rand() % 8)}
	//		));
	//}

	//draw stem
	RectangleShape stem(Vector2f(330.f, 12.f));
	stem.setFillColor(Color(50, 205, 50));
	stem.setPosition(Vector2f(200.f, 200.f));
	stem.rotate(91.f);
	stem.move({ 5.f,0.f });
	window->draw(stem);

	//draw petals
	for (size_t i = 0; i < 30; i++)
	{
		CircleShape petal = drawPetal(
			{ 250, 224, 5 },
			10.f,
			{ 200.f, 170.f },
			{ 1.f, 8.f }
		);
		// define rotaion in every iteration
		petal.rotate(3 * (4 * i));

		window->draw(petal);
	}

	//draw pistil
	CircleShape pistil(80.f);
	pistil.move(Vector2f(120.f, 90.f));
	pistil.setFillColor(Color(46, 41, 17));
	window->draw(pistil);

	//draw sun
	CircleShape sun(40.f);
	Color sunColor = { 255, 204, 51 };
	sun.setFillColor(sunColor);
	sun.setPosition(Vector2f(620.f, 40.f));
	window->draw(sun);

	//draw sun rays
	for (size_t i = 0; i < 15; i++)
	{
		CircleShape ray = drawSunRay(
			sunColor,
			3.f,
			{ 660.f, 80.f },
			{ 13.f, 3.f },
			-90.f
		);
		// define rotaion in every iteration
		ray.rotate(3 * (10 * i));
		ray.rotate(21 * time.asSeconds());

		window->draw(ray);
	}
}

