#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>



Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;

}

void Cvijet::draw() const
{
	//Cvijet

	sf::CircleShape oblik(20.f, 20);
	oblik.setFillColor(sf::Color::White);
	oblik.setPosition(71.f, 365.f);
	oblik.setRotation(45.f);

	oblik.setOutlineThickness(30.f);
	oblik.setOutlineColor(sf::Color::Yellow);
	
	window->draw(oblik);

	sf::RectangleShape linija(sf::Vector2f(90.f, 5.f));
	linija.setPosition(72.f, 440.f);
	linija.rotate(90.f);
	linija.setFillColor(sf::Color::Green);

	window->draw(linija);

	sf::CircleShape list(21.f, 3);
	list.setFillColor(sf::Color::Green);
	list.setPosition(90.f, 500.f);
	list.setRotation(510.f);

	window->draw(list);

	sf::RectangleShape trava(sf::Vector2f(120.f, 50.f));
	trava.setSize(sf::Vector2f(150.f, 10.f));
	trava.setFillColor(sf::Color::Green);
	trava.setPosition(1.f, 525.f);

	window->draw(trava);

	sf::Texture oblak;
	if (!oblak.loadFromFile("Oblak.png"))
	{
		cout << "Ne radi" << endl;
	}
	
	sf::Sprite sprite;
	sprite.setTexture(oblak);
	sprite.setColor(sf::Color::Cyan);
	
	

	window->draw(sprite);
	
	
	//Animacija
	

	srand(time(0));
	int promjenaBoje1 = rand() % (620 - 150 + 1) + 1;
	int promjenaBoje2 = rand() % (620 - 150 + 1) + 1;
	int promjenaBoje3 = rand() % (620 - 150 + 1) + 1;

	oblik.setFillColor(sf::Color(promjenaBoje1, promjenaBoje2, promjenaBoje3));
	window->draw(oblik);
	
	
	list.setFillColor(sf::Color(promjenaBoje1, promjenaBoje2, promjenaBoje3));
	window->draw(list);

	sprite.setColor(sf::Color(promjenaBoje1, promjenaBoje2, promjenaBoje3));
	window->draw(sprite);

	srand(time(0));
	int promjenaPozicije1 = rand() % (400 - 250 + 1) + 250;
	
	sprite.setPosition(promjenaPozicije1,50.f);

	window->draw(sprite);



	

	






}
