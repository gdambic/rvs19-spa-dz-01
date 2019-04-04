#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}
void Cvijet::draw()
{

	window->clear(sf::Color(102, 178, 255));

	sf::CircleShape flower(30.f);
	flower.setPosition(400, 300);
	flower.setFillColor(sf::Color(255, 153, 204));
	flower.setOutlineThickness(10.f);
	flower.setOutlineColor(sf::Color(255, 51, 153));
	window->draw(flower);

	sf::CircleShape sun(30.f);
	sun.setPosition(100, 100);
	sun.setFillColor(sf::Color::Yellow);
	window->draw(sun);

	sf::RectangleShape stalk(sf::Vector2f(150.f, 5.f));
	stalk.setPosition(429, 370);
	stalk.rotate(90.f);
	stalk.setFillColor(sf::Color(0, 153, 0));
	window->draw(stalk);

	sf::CircleShape leaf(30.f, 3);
	leaf.setPosition(485, 450);
	leaf.setFillColor(sf::Color(0, 102, 0));
	leaf.rotate(180.f);
	window->draw(leaf);

	sf::RectangleShape grass(sf::Vector2f(120.f, 50.f));
	grass.setSize(sf::Vector2f(800.f, 150.f));
	grass.setPosition(0, 520);
	grass.setFillColor(sf::Color(0, 153, 0));
	window->draw(grass);

	sf::CircleShape grass1(30.f, 3);
	grass1.setFillColor(sf::Color(0, 153, 0));
	grass1.setPosition(765, 500);
	window->draw(grass1);
	grass1.setPosition(745, 500);
	window->draw(grass1);
	grass1.setPosition(725, 500);
	window->draw(grass1);
	grass1.setPosition(705, 500);
	window->draw(grass1);
	grass1.setPosition(685, 500);
	window->draw(grass1);
	grass1.setPosition(665, 500);
	window->draw(grass1);
	grass1.setPosition(645, 500);
	window->draw(grass1);
	grass1.setPosition(625, 500);
	window->draw(grass1);
	grass1.setPosition(605, 500);
	window->draw(grass1);
	grass1.setPosition(585, 500);
	window->draw(grass1);
	grass1.setPosition(565, 500);
	window->draw(grass1);
	grass1.setPosition(545, 500);
	window->draw(grass1);
	grass1.setPosition(525, 500);
	window->draw(grass1);
	grass1.setPosition(505, 500);
	window->draw(grass1);
	grass1.setPosition(485, 500);
	window->draw(grass1);
	grass1.setPosition(465, 500);
	window->draw(grass1);
	grass1.setPosition(445, 500);
	window->draw(grass1);
	grass1.setPosition(425, 500);
	window->draw(grass1);
	grass1.setPosition(405, 500);
	window->draw(grass1);
	grass1.setPosition(385, 500);
	window->draw(grass1);
	grass1.setPosition(365, 500);
	window->draw(grass1);
	grass1.setPosition(345, 500);
	window->draw(grass1);
	grass1.setPosition(325, 500);
	window->draw(grass1);
	grass1.setPosition(305, 500);
	window->draw(grass1);
	grass1.setPosition(285, 500);
	window->draw(grass1);
	grass1.setPosition(265, 500);
	window->draw(grass1);
	grass1.setPosition(245, 500);
	window->draw(grass1);
	grass1.setPosition(225, 500);
	window->draw(grass1);
	grass1.setPosition(205, 500);
	window->draw(grass1);
	grass1.setPosition(185, 500);
	window->draw(grass1);
	grass1.setPosition(165, 500);
	window->draw(grass1);
	grass1.setPosition(145, 500);
	window->draw(grass1);
	grass1.setPosition(125, 500);
	window->draw(grass1);
	grass1.setPosition(105, 500);
	window->draw(grass1);
	grass1.setPosition(85, 500);
	window->draw(grass1);
	grass1.setPosition(65, 500);
	window->draw(grass1);
	grass1.setPosition(45, 500);
	window->draw(grass1);
	grass1.setPosition(25, 500);
	window->draw(grass1);
	grass1.setPosition(05, 500);
	window->draw(grass1);
	grass1.setPosition(-15, 500);
	window->draw(grass1);

	}

	
	

	

	

