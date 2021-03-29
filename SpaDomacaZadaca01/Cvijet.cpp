#include "Cvijet.h"


//Konstruktor
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	set_all_position(0.f, 0.f);
}

//Draw
void Cvijet::draw()
{
	set_all_position(x, y);

	(*window).draw(grancica);
	(*window).draw(list1);
	(*window).draw(list2);
	(*window).draw(sredina);
	
	for (int i = 0; i < 8; i++)
	{
		latice[i].rotate(angle);
		(*window).draw(latice[i]);
	}

	time = clock.restart();

	x += pps_x * time.asSeconds();
	y += pps_y * time.asSeconds();

	if (pps_x >= 5000 || pps_y >= 5000)
	{
		pps_x = 100.f;
		pps_y = 100.f;
	}

	if (x >= x_upper_limit || x <= x_lower_limit)
	{
		pps_x *= -1.0f;
	}
	if (y >= y_upper_limit || y <= y_lower_limit)
	{
		pps_y *= -1.0f;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		pps_x *= 1.05;
		pps_y *= 1.05;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		pps_x *= 0.97f;
		pps_y *= 0.97f;
	}

}


//Setteri
void Cvijet::set_all_position(const float x, const float y) 
{
	set_sredina(x, y);
	set_grancica(x, y);
	set_latice(x, y);
	set_list1(x, y);
	set_list2(x, y);
}
void Cvijet::set_sredina(const float x, const float y)
{
	sredina.setRadius(80.f);
	sredina.setOrigin(80.f, 80.f);
	sredina.setPosition(x + 0.f, y + -100.f);
	sredina.setFillColor(sf::Color::Yellow);
}
void Cvijet::set_latice(const float x, const float y)
{
	latice[0].setOrigin(-20.f, -20.f);
	latice[1].setOrigin(90.f, -20.f);
	latice[2].setOrigin(-20.f, 90.f);
	latice[3].setOrigin(90.f, 90.f);
	latice[4].setOrigin(35.f, -40.f);
	latice[5].setOrigin(110.f, 35.f);
	latice[6].setOrigin(35.f, 110.f);
	latice[7].setOrigin(-40.f, 35.f);

	for (int i = 0; i < 8; i++)
	{
		latice[i].setRadius(35.f);
		latice[i].setFillColor(sf::Color::Red);
		latice[i].setPosition(0.f, -100.f);
		latice[i].move(x, y);
	}

}
void Cvijet::set_grancica(const float x, const float y)
{
	grancica.setSize(sf::Vector2f(15.f, 200.f));
	grancica.setOrigin(4.f, 0.f);
	grancica.setPosition(x + 0.f, y + -50.f);
	grancica.setFillColor(sf::Color::Green);
}
void Cvijet::set_list1(const float x, const float y)
{
	list1.setPointCount(4);
	list1.setPoint(0, sf::Vector2f(x + 0.f, y + 100.f));
	list1.setPoint(1, sf::Vector2f(x + 100.f, y + 50.f));
	list1.setPoint(2, sf::Vector2f(x + 150.f, y + 100.f));
	list1.setPoint(3, sf::Vector2f(x + 100.f, y + 130.f));

	list1.setFillColor(sf::Color::Green);
}
void Cvijet::set_list2(const float x, const float y)
{
	list2.setPointCount(4);
	list2.setPoint(0, sf::Vector2f(x + 0.f, y + 80.f));
	list2.setPoint(1, sf::Vector2f(x + -100.f, y + 30.f));
	list2.setPoint(2, sf::Vector2f(x + -150.f, y + 80.f));
	list2.setPoint(3, sf::Vector2f(x + -100.f, y + 110.f));

	list2.setFillColor(sf::Color::Green);
}