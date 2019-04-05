#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}


void Cvijet::draw(sf::RenderWindow *window)
{
	


	sf::RectangleShape rectangle(sf::Vector2f(15, 200));
	rectangle.setPosition(240, 350);
	rectangle.setFillColor(sf::Color(10, 50, 7));
	sf::Texture texture;
	texture.loadFromFile("stem.jpg");
	rectangle.setTexture(&texture);
	window->draw(rectangle);




	sf::Texture fl_texture;
	fl_texture.loadFromFile("yflower.jpg");

	sf::CircleShape circle1(111, 9);
	circle1.setFillColor(sf::Color(51, 0, 25));
	circle1.setPosition(140, 140);
	circle1.setTexture(&fl_texture);
	window->draw(circle1);

	sf::CircleShape circle2(91, 9);
	circle2.setFillColor(sf::Color(102, 0, 51));
	circle2.setPosition(160, 160);
	circle2.setTexture(&fl_texture);

	window->draw(circle2);


	sf::CircleShape circle3(71, 9);
	circle3.setFillColor(sf::Color(153, 0, 76));
	circle3.setPosition(180, 180);
	circle3.setTexture(&fl_texture);

	window->draw(circle3);

	sf::CircleShape circle4(51, 9);
	circle4.setFillColor(sf::Color(204, 0, 102));
	circle4.setPosition(200, 200);
	circle4.setTexture(&fl_texture);

	window->draw(circle4);


	sf::CircleShape circle5(31, 9);
	circle5.setFillColor(sf::Color(255, 0, 127));
	circle5.setPosition(220, 220);
	circle5.setTexture(&fl_texture);

	window->draw(circle5);

	sf::CircleShape circle6(11, 9);
	circle6.setFillColor(sf::Color(255, 51, 153));
	circle6.setPosition(240, 240);
	circle6.setTexture(&fl_texture);

	window->draw(circle6);

	

}
