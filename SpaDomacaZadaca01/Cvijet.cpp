#include "Cvijet.h"
#include <iostream>
using namespace std;

void Cvijet::draw()
{
	//Drawing the petals
	int flowerPosx = 400;   //the coordinates I chose for the flower
	int flowerPosy = 300;

	//creating the first petal
	sf::ConvexShape petal;
	
	// define the points of the shape of a petal that will be a hexagon
	petal.setPointCount(6); 
	petal.setPoint(0, sf::Vector2f(0, 0));
	petal.setPoint(1, sf::Vector2f(80, 40));
	petal.setPoint(2, sf::Vector2f(120, 40));
	petal.setPoint(3, sf::Vector2f(160, 0));
	petal.setPoint(4, sf::Vector2f(120, -40));
	petal.setPoint(5, sf::Vector2f(80, -40));

	// set petal color to red
	petal.setFillColor(sf::Color(0, 255, 0)); 
	petal.setPosition(flowerPosx, flowerPosy); //moves the petal to the position of the flower 
											   //so I can rotate the petals around the center of the flower

	//creation of other petals by copying the original then rotate them to get a flower
	sf::ConvexShape petal2 = petal;
	petal2.setRotation(60);
	petal2.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal3 = petal;
	petal3.setRotation(120);
	petal3.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal4 = petal;
	petal4.setRotation(180);
	petal4.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal5 = petal;
	petal5.setRotation(240);
	petal5.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal6 = petal;
	petal6.setRotation(300);
	petal6.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal7 = petal;
	petal7.setFillColor(sf::Color(255, 0, 0));
	petal7.setRotation(30);
	petal7.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal8 = petal7;
	petal8.setRotation(90);
	petal8.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal9 = petal7;
	petal9.setRotation(150);
	petal9.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal10 = petal7;
	petal10.setRotation(210);
	petal10.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal11 = petal7;
	petal11.setRotation(270);
	petal11.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petal12 = petal7;
	petal12.setRotation(330);
	petal12.setPosition(flowerPosx, flowerPosy);

	sf::ConvexShape petals[12] = {petal,petal2,petal3,petal4,petal5,petal6,petal7,petal8,petal9,petal10,petal11,petal12}
	int petalsSize = 12;

	//here is defined the flower button positioned at the center of the petals
	int radius = 40;
	sf::CircleShape flower(radius);
	flower.setFillColor(sf::Color(255, 255, 0));
	flower.setPosition(flowerPosx - radius, flowerPosy - radius);

	//start of animation
	sf::Time pastTime = Cvijet::m_timer.restart();
	while (Cvijet::m_window->isOpen())
	{
		//calculate an angle depending on how much time has passed by
		float RrotateAngle = 2.f * pastTime.asSeconds();
		float GrotateAngle = -RrotateAngle;
		sf::Color Gtint = sf::Color(0, 255, 0);
		sf::Color Rtint = sf::Color(255, 0, 0);

		//rotate every petal
		for (int i; i < petalsSize; ++i)
		{
			sf::Color tint = sf::Color(0, 0, 0);
			//according to if my petal is red or green, I give it different parmeters
			if (i < 7)
			{
				tint = Gtint;
				float rotateangle = GrotateAngle;
			}
			else 
			{
				tint = Rtint;
				float rotateangle = RrotateAngle;
			}
			//petal is rotated
			petals[i].rotate(rotateAngle);
			//petal is drawn in its new position
			Cvijet::m_window->draw(petals[i]);
			//come back to previous position
			petals[i].rotate(-2 * rotateAngle);
			//petals are set black and drawn
			petals[i].setFillColor(sf::Color(0, 0, 0));
			//the black coloring only leaves a small colored arc
			Cvijet::m_window->draw(petals[i]);
			//petals are brought back to where they were on the first step and redrawn
			petals[i].rotate(2 * rotateAngle);
			petals[i]..setFillColor(tint);
			Cvijet::m_window->draw(petals[i]);	
		}
		//flower button is drawn so it appears above the petals 
		Cvijet::m_window->draw(flower);
		Cvijet::m_window->display();
	}	
}
