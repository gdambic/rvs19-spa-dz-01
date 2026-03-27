#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	/*set_latica01(latica01);
	set_latica02(latica02);
	set_latica03(latica03);
	set_latica04(latica04);
	set_latica05(latica05);
	set_latica06(latica06);*/
	set_tucak01(tucak01);
	set_tucak02(tucak02);

	sf::CircleShape temp_latica;

	int broj_latica = 6;
	float rotation = 20;
	for (size_t i = 0; i < broj_latica; i++)
	{
		temp_latica.setFillColor(sf::Color(242, 214, 83));
		temp_latica.setRadius(45.f);
		temp_latica.setPointCount(3);
		temp_latica.setRotation(rotation);
		temp_latica.setPosition(200, 150);
		temp_latica.setOrigin(45, 90);

		latice.push_back(temp_latica);
		rotation += 60;
	}
	set_stabljika(stabljika);
	set_list01(list01);
	set_list02(list02);
}

void Cvijet::set_tucak01(sf::CircleShape& tucak01)
{
	this->tucak01.setFillColor(sf::Color(235, 140, 30));
	this->tucak01.setRadius(30.f);
	this->tucak01.setPosition(170, 120);
}

sf::CircleShape Cvijet::get_tucak01()
{
	return tucak01;
}

void Cvijet::set_tucak02(sf::CircleShape& tucak02)
{
	this->tucak02.setFillColor(sf::Color(255, 180, 60));
	this->tucak02.setRadius(20.f);
	this->tucak02.setPosition(180, 130);
}

sf::CircleShape Cvijet::get_tucak02()
{
	return tucak02;
}

void Cvijet::set_stabljika(sf::RectangleShape& stabljika)
{
	this->stabljika.setFillColor(sf::Color(85, 140, 60));
	this->stabljika.setSize(sf::Vector2f(10.f, 200.f));
	this->stabljika.setPosition(200.f, 200.f);
}

sf::RectangleShape Cvijet::get_stabljika()
{
	return stabljika;
}

void Cvijet::set_list01(sf::CircleShape& list01)
{
	this->list01.setFillColor(sf::Color(85, 140, 60));
	this->list01.setRadius(30.f);
	this->list01.setPointCount(4);
	this->list01.setScale(1.f, 2.f);
	this->list01.setRotation(-30.f);
	this->list01.setPosition(120.f, 315.f);
}

sf::CircleShape Cvijet::get_list01()
{
	return list01;
}

void Cvijet::set_list02(sf::CircleShape& list02)
{
	this->list02.setFillColor(sf::Color(85, 140, 60));
	this->list02.setRadius(30.f);
	this->list02.setPointCount(4);
	this->list02.setScale(1.f, 2.f);
	this->list02.setRotation(30.f);
	this->list02.setPosition(235.f, 285.f);
}

sf::CircleShape Cvijet::get_list02()
{
	return list02;
}

void Cvijet::update()
{
	float time = clock.getElapsedTime().asSeconds();

	float offsetX = sin(time * 2.f) * 50.f;
	float noviX = baseX + offsetX;

	for (int i = 0; i < latice.size(); i++)
	{
		latice[i].rotate(0.5f);
		latice[i].setPosition(noviX, 150);
	}

	tucak01.setPosition(noviX - 30, 120);
	tucak02.setPosition(noviX - 20, 130);
	stabljika.setPosition(noviX, 200);
	list01.setPosition(noviX - 80, 315);
	list02.setPosition(noviX + 35, 285);
}

void Cvijet::draw()
{
	update();

	/*window->draw(latica01);
	window->draw(latica02);
	window->draw(latica03);
	window->draw(latica04);
	window->draw(latica05);
	window->draw(latica06);*/

	window->draw(stabljika);

	for (int i = 0; i < latice.size(); i++)
	{
		window->draw(latice[i]);
	}

	window->draw(tucak01);
	window->draw(tucak02);
	window->draw(list01);
	window->draw(list02);
}