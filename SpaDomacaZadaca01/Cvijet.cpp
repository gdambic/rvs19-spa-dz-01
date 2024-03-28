#include "Cvijet.h"
#include <vector>

CircleShape Cvijet::drawShape(float size, int points, Vector2f position, float rotation, Vector2f scale, Color colorFill, float outline, Color colorOutline)
{
	CircleShape shape(size, points);

	shape.setPosition(position);
	shape.setRotation(rotation);
	shape.setScale(scale);
	shape.setFillColor(colorFill);
	shape.setOutlineThickness(outline);
	shape.setOutlineColor(colorOutline);
	return shape;
}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::drawCanvas()
{
	//time initiation
	Time time = clock.getElapsedTime();

	//time restart
	if (time.asSeconds() > 10)
	{
		clock.restart();
	}

	//draw sky
	window->draw(drawShape(
		800.f,					//shape size
		4,						//shape point
		{ -600.f, -600.f },		//position x, y
		7.f,					//rotation
		{ 2.f, 1.f },			//scale x, y
		{ 135, 206, 235 }		//rgb color fill
	)
	);

	//draw grass field
	window->draw(drawShape(
		800.f,					//shape size
		4,						//shape point
		{ -300.f, -350.f },		//position x, y
		28.f,					//rotation
		{ 2.f, 1.f },			//scale x, y
		{ 17,124,19 },			//rgb color fill
		9.f,					//outline size
		{ 10,116,13 }			//rgb color outline
	)
	);


	//draw sun rays

	for (size_t i = 0; i < 24; i++)
	{
		CircleShape ray = drawShape(
			3.f,				//shape size
			3,					//shape point
			{ 610.f, 113.f },	//position x, y
			9.f * (2 * i),		//rotation in every iteration
			{ 13.f, 3.f },		//scale x, y
			{ 255, 204, 51 }	//rgb color fill
		);
		//rotation animation speed
		ray.rotate(19.7 * time.asSeconds());

		window->draw(ray);
		
	}

	//draw sun
	window->draw(drawShape(
		50.f,					//shape size
		100,					//shape point
		{ 565.f, 60.f },		//position x, y
		5.f,					//rotation
		{ 1.f, 1.f },			//scale
		{ 255, 204, 51 }		//rgb color fill
	)
	);

	//draw stem
	window->draw(drawShape(
		40.f,					//shape size
		3,						//shape point
		{ 162.f, 150.f },		//position x, y
		-1.f,					//rotation
		{ 1.f, 40.f },			//scale
		{ 50, 205, 50 }			//rgb color fill
	)
	);

	//draw leaf 1
	window->draw(drawShape(
		9.f,					//shape size
		3,						//shape point
		{ 104.f, 500.f },		//position x, y
		-76.f,					//rotation
		{ 1.f, 8.f },			//scale
		{ 50, 205, 50 }			//rgb color fill
	)	
	);

	//draw leaf 2
	window->draw(drawShape(
		9.f,					//shape size
		3,						//shape point
		{ 302.f, 350.f },		//position x, y
		66.f,					//rotation
		{ 1.f, 8.f },			//scale
		{ 50, 205, 50 }			//rgb color fill
	)
	);

	//draw petals
	for (size_t i = 0; i < 30; i++)
	{
		window->draw(drawShape(
			10.f,				//shape size
			4,					//shape point
			{ 200.f, 250.f },	//position x, y
			5.f * i * 5,		//rotation
			{ 1.f, 4.f },		//scale
			{ 250, 170, 200 },	//rgb color fill
			1.f,				//outline size
			{ 200, 170, 200 }	//rgb color outline
		)
		);
	}

	//draw pistil
	window->draw(drawShape(
		40.f,					//shape size
		100,					//shape point
		{ 165.f, 210.f },		//position x, y
		5.f,					//rotation
		{ 1.f, 1.f },			//scale
		{ 250, 224, 5 }			//rgb color fill
	)
	);
}