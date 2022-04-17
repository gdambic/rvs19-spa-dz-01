#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Vertex.hpp>
using namespace sf;
using namespace std;
class Cvijet
{
public:
	Cvijet(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	float num1, num2;
	void animacija(Clock &clock, Clock& clock2, Clock& clock3);
private:
	RectangleShape rectangle, ground;
	CircleShape head, latica, sunce;

	CircleShape cc1, cc2, cc3, cc4, cc5, cc6, cc7, cc8;

};

