#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::Clock Clock;
	sf::Time elapsed1 = Clock.getElapsedTime();

	void Petal2(sf::Color color, int position);
	void Petal();
	void Print();
	void set();
	void higher();

	sf::RenderWindow* window;
	sf::RectangleShape stem1;
	sf::ConvexShape petal[36];
	sf::CircleShape circle1;

	int number[4] = { 0,1,2,3 };
	int i = 500;
	int j = 600;
	float rotation = 0.f;
public:
	Cvijet(sf::RenderWindow* window);
	
	
	void draw();
};

