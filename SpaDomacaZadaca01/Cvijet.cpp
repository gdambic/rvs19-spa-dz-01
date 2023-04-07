#include "Cvijet.h"

Cvijet::Cvijet (sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color::Yellow);

	// Creating the flower head
	sf::CircleShape flowerhead(40);
	flowerhead.setFillColor(sf::Color::Yellow);
	flowerhead.setOutlineThickness(30);
	flowerhead.setOutlineColor(sf::Color::Red);
	flowerhead.setPosition(50, 50);

	window->draw(flowerhead);

	//Creating the rectangle stem
	sf::RectangleShape stem(sf::Vector2f(10, 140));
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(85, 160);

	window->draw(stem);

	//Creating a leaf shape

	sf::Vector2f branchPosition(85, 160);
	sf::Vector2f branchEnd(190, 210);
	sf::Vertex branch[] =
	{
		sf::Vertex(branchPosition, sf::Color::Green),
		sf::Vertex(branchEnd, sf::Color::Green)

	};
	double stemSin = 0.0;
	double stemAngle = 0.0;
	double branchAngle = 0.0;



	//Start animation
	stemSin += 0.05;
	float stemOffset = std::sin(stemSin);
	stem.setRotation(stemAngle);
	stem.setPosition(85, 160 + stemOffset * 10);
	stemAngle = std::cos(stemSin) * 20;



	branchAngle += 0.1;
	sf::Transform rotateTransform;
	rotateTransform.rotate(branchAngle, branchPosition);
	branchEnd = rotateTransform.transformPoint(branchEnd);
	branch[1].position = branchEnd;

	window->draw(branch, 2, sf::Lines);

	//Create a circle for the center of the flower
	sf::CircleShape center(10.f);
	center.setFillColor(sf::Color::Yellow);
	center.setPosition(0, 0);

	window->draw(center);


	
	

}
