#include <SFML/Graphics.hpp>
#include <string>
#include "Cvijet.h"
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	sf::Clock clock;
	sf::Time vr;

	CircleShape krug(50.f);
	krug.setPosition(400.f,200.f);
	krug.setFillColor(sf::Color(500, 200, 50));
	krug.setOutlineThickness(50.f);
	krug.setOutlineColor(sf::Color::Red);

	sf::RectangleShape stabljika(sf::Vector2f(10.f, 250.f));
	stabljika.setPosition(450.f, 350.f);
	stabljika.setFillColor(sf::Color(300, 150, 50));
	
	sf::CircleShape sunce(30.f);
	sunce.setFillColor(sf::Color(500, 250, 150));	

	sf::ConvexShape listic;

	listic.setPointCount(4);

	listic.setPoint(0, sf::Vector2f(450.f, 500.f));
	listic.setPoint(1, sf::Vector2f(530.f, 470.f));
	listic.setPoint(2, sf::Vector2f(580.f, 480.f));
	listic.setPoint(3, sf::Vector2f(450.f, 500.f));
	listic.setFillColor(sf::Color(300, 150, 50));

	sf::RectangleShape pozadina(sf::Vector2f(800.f,600.f));
	pozadina.setFillColor(sf::Color(100,150,200));
	
	sf::RectangleShape pod(sf::Vector2f(800.f,100.f));
	pod.setFillColor(sf::Color(300, 150, 50));
	pod.setPosition(0,550);

	Cvijet cvijet(&window);
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
		
	


		window.clear();
		window.draw(pozadina);
		window.draw(pod);
		cvijet.draw_krug(krug);
		window.draw(krug);
		window.draw(stabljika);
		window.draw(sunce);
		
		window.draw(listic);
		window.display();
	}

	return 0;
}