#include "Cvijet.h"
using namespace std;
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	set_krug(krug);
	set_sunce(sunce);
	set_stapka(stapka);
	set_list(list);
	set_background(spriteBackground);
	set_krug2(krug2);
}
void Cvijet::set_background(sf::Sprite& spriteBackground)
{
	textureBackground.loadFromFile("IYYPby.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	spriteBackground.setScale(0.55, 0.55);
}
void Cvijet::set_krug(sf::CircleShape &krug)
{
	krug.setRadius(70);
	krug.setPointCount(6);
	if (!texture.loadFromFile("Elements_20-256x256.png"))
	{
		cout << "404" << endl;
	}
	krug.setTexture(&texture);
	krug.setPosition(100.f, 100.f);
}

void Cvijet::set_krug2(sf::CircleShape& krug2)
{
	krug2.setRadius(70);
	krug2.setPointCount(6);
	if (!texturep.loadFromFile("Leaves.png"))
	{
		cout << "404" << endl;
	}
	krug2.setTexture(&texturep);
	krug2.setPosition(100.f, 100.f);
}

void Cvijet::set_sunce(sf::CircleShape& sunce)
{
	sunce.setRadius(15.0f);
	sunce.setFillColor(sf::Color::Yellow);
	if (!texture1.loadFromFile("Plaster_18-256x256.png"))
	{
		cout << 404 << endl;
	}
	sunce.setTexture(&texture1);
	sunce.setPosition(krug.getPosition() + sf::Vector2f(200, -80));
}

void Cvijet::set_stapka(sf::RectangleShape& stapka)
{
	stapka.setSize(sf::Vector2f(135.f, 20.f));
	if (!texture2.loadFromFile("Grass.png"))
	{
		cout << "404" << endl;
	}
	stapka.setTexture(&texture2);
	stapka.setRotation(90);
	stapka.setPosition(krug.getPosition() + sf::Vector2f(75, 140));
}

void Cvijet::set_list(sf::ConvexShape& list)
{
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(140.f, 140.f));
	list.setPoint(1, sf::Vector2f(50.f, 10.f));
	list.setPoint(2, sf::Vector2f(0.f, 0.f));
	list.setPoint(3, sf::Vector2f(10.f, 50.f));
	list.setFillColor(sf::Color::Green);
	if (!texture3.loadFromFile("Leaf.png"))
	{
		cout << "404" << endl;
	}
	list.setTexture(&texture3);
	list.setRotation(280);
	list.setPosition(stapka.getPosition() + sf::Vector2f(0, 80));
}

sf::CircleShape Cvijet::get_krug()
{
	return krug;
}

sf::CircleShape Cvijet::get_krug2()
{
	return krug2;
}

sf::CircleShape Cvijet::get_sunce()
{
	return sunce;
}

sf::RectangleShape Cvijet::get_stapka()
{
	return stapka;
}

sf::ConvexShape Cvijet::get_list()
{
	return list;
}

sf::Sprite Cvijet::get_spriteBackground()
{
	return spriteBackground;
}

void Cvijet::draw()
{
	window->draw(get_spriteBackground());
	window->draw(get_krug2());
	window->draw(get_krug());
	window->draw(get_stapka());
	window->draw(get_list());

	if (sunce.getRadius() == 15.0f)
	{
		sunce_malo = true;
	}
	if (sunce.getRadius() >= 20.0f)
	{
		sunce_malo = false;
	}

	if (krug.getRadius() == 1)
	{
		krug1 = true;
	}
	if (krug.getRadius() == 70)
	{
		krug1 = false;
	}

	
	if (frameClock.getElapsedTime().asMicroseconds() > 850.0f) {

		if (sunce_malo)
		{
			sunce.setRadius(sunce.getRadius() + 0.1f);
		}
		if (!sunce_malo)
		{
			sunce.setRadius(sunce.getRadius() - 0.1f);
		}
		if (krug1)
		{
			krug.setRadius(krug.getRadius() + 1);
			krug2.move(1.0f, 1.0f);
		}
		if (!krug1)
		{
			krug.setRadius(krug.getRadius() - 1);
			krug2.move(-1.0f, -1.0f);
		}
		frameClock.restart();
	}
	window->draw(get_sunce());
}


