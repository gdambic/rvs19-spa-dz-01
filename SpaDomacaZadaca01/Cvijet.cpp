#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

sf::Color Cvijet::randColor(float x)
{
	srand(time(nullptr));
	int randInt0 = rand() % (255 - 1 + 1) + 1;
	int randInt1 = rand() % (255 - 1 + 1) + 1;
	int randInt2 = rand() % (255 - 1 + 1) + 1;

	sf::sleep(sf::seconds(x));
	return sf::Color(randInt0, randInt1, randInt2);
}

void Cvijet::set_tekstura(std::string file)
{
	try
	{
		tekstura.loadFromFile(file);
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}

void Cvijet::set_krug(float velicina, float x, float y, float outlineThickness)
{
	krug.setRadius(velicina);
	krug.setOrigin(x, y);
	krug.setOutlineThickness(outlineThickness);
}

void Cvijet::set_latice(float velicina, int listovi, sf::Color boja, float x, float y)
{
	latice.setRadius(velicina);
	latice.setPointCount(listovi);
	latice.setFillColor(boja);
	latice.setOrigin(x, y);
}

void Cvijet::set_sunce()
{
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setSize(sf::Vector2f(90, 90));
	sunce.setOrigin(-50, -20);
	sunce.setTexture(nullptr);
}

void Cvijet::set_trava(float visina)
{
	trava.setSize(sf::Vector2f(800.f, visina));
	trava.setTexture(&tekstura);
	trava.setOrigin(0, -600 + visina);
}

sf::RectangleShape Cvijet::background(sf::Vector2u& prozorDim, const sf::Color boja)
{
	float f_x = static_cast<float>(prozorDim.x);
	float f_y = static_cast<float>(prozorDim.y);
	sf::RectangleShape pozadina(sf::Vector2f(f_x, f_y));
	pozadina.setFillColor(boja);

	return pozadina;
}

void Cvijet::draw()
{
	srand(time(nullptr));
	std::string slika = "trava.jpg";
	sf::Color bojaNeba = sf::Color::Cyan;
	sf::Texture wojak;
	if (!wojak.loadFromFile("pinkvojak.jpg"))
	{
		std::cout << "Pepe be sad!" << std::endl;
	}
	sf::Vector2u dimenzije = window->getSize();

	set_tekstura(slika);

	set_krug(30, -385, -200, 10);
	krug.setFillColor(randColor(0.9213f));
	krug.setOutlineColor(randColor(0.2213f));

	int randLatice = rand() % (16 - 3 + 1) + 3;
	set_latice(70, randLatice,
		sf::Color::Yellow, -345, -160);
	set_trava(350);
	set_sunce();

	// stabiljka
	sf::RectangleShape stabiljka(sf::Vector2f(250.f, 10.f));
	stabiljka.setPosition(sf::Vector2f(420, 290));
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.rotate(90.f);

	// listovi
	sf::ConvexShape list1;
	list1.setPointCount(5);
	list1.setPoint(0, sf::Vector2f(0.f, 0.f));
	list1.setPoint(1, sf::Vector2f(150.f, 10.f));
	list1.setPoint(2, sf::Vector2f(120.f, 90.f));
	list1.setPosition(sf::Vector2f(420, 290));
	list1.setFillColor(sf::Color::Red);

	sf::ConvexShape list2;
	list2.setPointCount(5);
	list2.setPoint(0, sf::Vector2f(0.f, 0.f));
	list2.setPoint(1, sf::Vector2f(150.f, 10.f));
	list2.setPoint(2, sf::Vector2f(120.f, 90.f));
	list2.setPosition(sf::Vector2f(420, 290));
	list2.setFillColor(sf::Color::Blue);
	list2.rotate(160);


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sunce.setTexture(&wojak);
		set_tekstura("pustinja.jpg");
		bojaNeba = sf::Color::Red;
	}

	window->draw(background(dimenzije, bojaNeba));
	window->draw(trava);
	window->draw(stabiljka);
	window->draw(latice);
	window->draw(list1);
	window->draw(list2);
	window->draw(krug);
	window->draw(sunce);
}