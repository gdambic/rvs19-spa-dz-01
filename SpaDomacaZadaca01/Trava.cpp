#include "Trava.h"
#include <cmath>
#include <iostream>
#include <random>
#include <functional>

Trava::Trava(sf::RenderWindow* window)
{
	this->window = window;

	auto gen = std::bind(std::uniform_int_distribution<>(0, 100), std::default_random_engine());
	auto gen2 = std::bind(std::uniform_real_distribution<>(-5, 5), std::default_random_engine());
	height = rand() % 300 + 500;

	for (int i = 0; i < 800; i++)
	{
		color[i] = sf::Color(gen(), gen() + 100, 0);
		rotation[i] = rand() % 6 - 3;
		target_Rotation[i] = gen2();
	}
}

void Trava::draw()
{
	sf::VertexArray va(sf::Lines);
	sf::Clock clock;

	auto gen2 = std::bind(std::uniform_real_distribution<>(-1, 1), std::default_random_engine());

	va.clear();
	srand(5);
	int prosly;
	float prosla = 0;
	for (int k = 0; k < 800; k++)
	{

		if (target_Rotation[k] < 0 and rotation[k] <= target_Rotation[k])
		{
			target_Rotation[k] = target_Rotation[k] * -1;
		
		}
		else if (target_Rotation[k] > 0 and rotation[k] >= target_Rotation[k])
		{
			target_Rotation[k] = target_Rotation[k] * -1;
		}
		rotation[k] += 0.005 * target_Rotation[k];
		prosla = 0;
		prosly = rand() % 10;
		for (int i = 0, j = 9; i < 8; i++, j--)
		{

			auto prvi = sf::Vector2f(k * 2 + rotation[k] * pow(i, 1.3), j * 10 + 810 - prosly);
			auto drugi = sf::Vector2f(k * 2 + prosla, (j + 1) * 10 + 810 - prosly);
			sf::Vertex v1(prvi, color[k]);
			sf::Vertex v2(drugi, color[k]);
			va.append(v1);
			va.append(v2);
			prosla = rotation[k] * pow(i, 1.3);
		}
	}
	window->draw(va);
}
