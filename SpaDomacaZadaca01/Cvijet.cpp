#include "Cvijet.h"
#include<string>
#include<sstream>
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	for (int i = 0; i < 18; i++) {
		zvjeri[i] = postavljanje(i);
	}
}

void Cvijet::draw()
{
	livada();
	vukovi();
	cvijet();
	mjesec();
}

void Cvijet::vukovi()
{
	sf::Texture texture;
	texture = raspored_slika();

	// Create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.5f, 0.5f));
	sprite.setPosition((800 + koordinataX), 390);
	// Draw it
	window->draw(sprite);

	koordinataX -= 14;
	koordinataX %= 1000;

}

void Cvijet::cvijet()
{

	sf::RectangleShape rectangle;

	// change the size to 100x100
	rectangle.setSize(sf::Vector2f(800, 90));
	rectangle.setPosition(0, 510);
	rectangle.setFillColor(sf::Color::Blue);
	window->draw(rectangle);
	sf::RectangleShape rectangle2;

	// change the size to 100x100
	rectangle2.setSize(sf::Vector2f(800, 10));
	rectangle2.setPosition(0, 590);
	rectangle2.setFillColor(sf::Color::Green);
	window->draw(rectangle2);

	sf::Texture texture;
	texture.loadFromFile("flowers.png");

	// Create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.15f, 0.15f));
	sprite.setPosition(0, 530);
	// Draw it
	window->draw(sprite);
	sf::Transform transform;



	for (int i = 0; i < 10; i++) {
		transform.translate(70, 0);
		window->draw(sprite, transform);
	}


}

void Cvijet::mjesec()
{
	sf::Texture texture;
	texture.loadFromFile("moon.png");

	// Create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.2f, 0.2f));
	sprite.setPosition(700, 40);
	// Draw it
	window->draw(sprite);
}

void Cvijet::livada()
{
	sf::Texture texture;
	texture.loadFromFile("livada.png");

	// Create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(0, 50);
	window->draw(sprite);
}

sf::Texture Cvijet::postavljanje(int i)
{
	sf::Texture texture;
	std::stringstream ss;
	ss << i << ".gif";
	texture.loadFromFile(ss.str());


	return texture;
}

sf::Texture Cvijet::raspored_slika()
{

	brojac++;
	brojac %= 18;

	return zvjeri[brojac];
}
