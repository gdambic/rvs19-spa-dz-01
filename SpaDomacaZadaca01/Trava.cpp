#include "Trava.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

Trava::Trava(sf::RenderWindow* window)
{
	this->window = window;
}

void Trava::draw()
{
	int counter = 0;
	int num_of_grass = 80;

	vector<sf::RectangleShape> trava_vec;
	for (int i = 0; i < num_of_grass; i++)
	{
		trava.setSize(sf::Vector2f(20.f, 5.f));
		trava.setFillColor(sf::Color(86,125,70));
		trava.setRotation(90);
		trava.setPosition(10 + counter, 250);
		counter += 10;
		trava_vec.push_back(trava);
	}

	for (int i = 0; i < num_of_grass; i++)
	{
		window->draw(trava_vec[i]);
	}
}

sf::RectangleShape Trava::get_trava() const
{
	return trava;
}

void Trava::set_trava(const sf::RectangleShape trava)
{
	this->trava = trava;
}
