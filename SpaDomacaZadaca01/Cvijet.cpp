#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window) : window(window)
{
	boja = true;
	
	flower.setRadius(60);
	flower.setPointCount(50);
	flower.setPosition(145, 120);
	flower.setFillColor(sf::Color::Yellow);

	petal1.setRadius(80);
	petal1.setPointCount(50);
	petal1.setPosition(60, 50);
	petal1.setFillColor(sf::Color::Red);

	petal2.setRadius(80);
	petal2.setPointCount(50);
	petal2.setPosition(190, 50);
	petal2.setFillColor(sf::Color::Red);

	petal3.setRadius(80);
	petal3.setPointCount(50);
	petal3.setPosition(60, 150);
	petal3.setFillColor(sf::Color::Red);

	petal4.setRadius(80);
	petal4.setPointCount(50);
	petal4.setPosition(190, 150);
	petal4.setFillColor(sf::Color::Red);

	peteljka.setSize({ 10, 300 });
	peteljka.setPosition({ 200, 270 });
	peteljka.setFillColor({ sf::Color::Green });

	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(200, 450));
	list.setPoint(1, sf::Vector2f(370, 330));
	list.setPoint(2, sf::Vector2f(480, 350));
	list.setPoint(3, sf::Vector2f(400, 420));
	list.setFillColor(sf::Color::Green);

	flower2.setRadius(45);
	flower2.setPointCount(30);
	flower2.setPosition(585, 390);
	flower2.setFillColor(sf::Color::Yellow);

	petal10.setRadius(50);
	petal10.setPointCount(50);
	petal10.setPosition(550, 360);
	petal10.setFillColor(sf::Color::Blue);

	petal11.setRadius(60);
	petal11.setPointCount(50);
	petal11.setPosition(530, 340);
	petal11.setFillColor(sf::Color::Red);

	petal20.setRadius(50);
	petal20.setPointCount(50);
	petal20.setPosition(610, 360);
	petal20.setFillColor(sf::Color::Blue);

	petal22.setRadius(60);
	petal22.setPointCount(50);
	petal22.setPosition(610, 340);
	petal22.setFillColor(sf::Color::Red);

	petal30.setRadius(50);
	petal30.setPointCount(50);
	petal30.setPosition(550, 410);
	petal30.setFillColor(sf::Color::Blue);

	petal33.setRadius(60);
	petal33.setPointCount(50);
	petal33.setPosition(530, 410);
	petal33.setFillColor(sf::Color::Red);
	
	petal40.setRadius(50);
	petal40.setPointCount(50);
	petal40.setPosition(610, 410);
	petal40.setFillColor(sf::Color::Blue);

	petal44.setRadius(60);
	petal44.setPointCount(50);
	petal44.setPosition(610, 410);
	petal44.setFillColor(sf::Color::Red);
	
	peteljka2.setSize({ 10, 70 });
	peteljka2.setPosition({ 625, 500 });
	peteljka2.setFillColor({ sf::Color::Green });

	sunce.setRadius(60);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setOutlineThickness(15);
	sunce.setOutlineColor(sf::Color::Red);
	sunce.setPosition(600, 80);

}

void Cvijet::draw()
{
	window->draw(peteljka);
	window->draw(petal1);
	window->draw(petal2);
	window->draw(petal3);
	window->draw(petal4);
	window->draw(list);

	window->draw(flower);

	window->draw(peteljka2);
	window->draw(petal11);
	window->draw(petal22);
	window->draw(petal33);
	window->draw(petal44);

	window->draw(petal10);
	window->draw(petal20);
	window->draw(petal30);
	window->draw(petal40);

	window->draw(flower2);

	window->draw(sunce);

	sf::Time elapsed1 = clock.getElapsedTime();
	if (elapsed1.asSeconds() > 1)
	{
		if (boja)
		{
			petal1.setFillColor(sf::Color::Magenta);
			petal2.setFillColor(sf::Color::Magenta);
			petal3.setFillColor(sf::Color::Magenta);
			petal4.setFillColor(sf::Color::Magenta);
			
			petal10.setFillColor(sf::Color::Red);
			petal20.setFillColor(sf::Color::Red);
			petal30.setFillColor(sf::Color::Red);
			petal40.setFillColor(sf::Color::Red);
			petal11.setFillColor(sf::Color::Blue);
			petal22.setFillColor(sf::Color::Blue);
			petal33.setFillColor(sf::Color::Blue);
			petal44.setFillColor(sf::Color::Blue);

			sunce.setOutlineColor(sf::Color::Yellow);
			boja = false;
		}
		else
		{
			petal1.setFillColor(sf::Color::Red);
			petal2.setFillColor(sf::Color::Red);
			petal3.setFillColor(sf::Color::Red);
			petal4.setFillColor(sf::Color::Red);
			petal10.setFillColor(sf::Color::Blue);
			petal20.setFillColor(sf::Color::Blue);
			petal30.setFillColor(sf::Color::Blue);
			petal40.setFillColor(sf::Color::Blue);
			petal11.setFillColor(sf::Color::Red);
			petal22.setFillColor(sf::Color::Red);
			petal33.setFillColor(sf::Color::Red);
			petal44.setFillColor(sf::Color::Red);
			sunce.setOutlineColor(sf::Color::Red);

			boja = true;
		}
		clock.restart();
	}
}
