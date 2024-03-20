#include "Cvijet.h"
#include <iostream>
using namespace std;

void Cvijet::draw()
{

	// FLOWER NUMBER ONE

	//Drawing the petals
	int flowerPosx = 400;   //the coordinates I chose for the flower
	int flowerPosy = 300;

	//creating the first petal
	sf::ConvexShape petal;
	
	petal.setPointCount(6); // define the points of the shape of a petal that will be a hexagon
	petal.setPoint(0, sf::Vector2f(0, 0));
	petal.setPoint(1, sf::Vector2f(80, 40));
	petal.setPoint(2, sf::Vector2f(120, 40));
	petal.setPoint(3, sf::Vector2f(160, 0));
	petal.setPoint(4, sf::Vector2f(120, -40));
	petal.setPoint(5, sf::Vector2f(80, -40));


	petal.setFillColor(sf::Color(0, 255, 0)); // set petal color to red
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

	//here is defined the flower button positioned at the center of the petals
	int radius = 40;
	sf::CircleShape flower(radius);
	flower.setFillColor(sf::Color(255, 255, 0));
	flower.setPosition(flowerPosx - radius, flowerPosy - radius);

	//draw every element 
	Cvijet::m_window->draw(petal);
	Cvijet::m_window->draw(petal2);
	Cvijet::m_window->draw(petal3);
	Cvijet::m_window->draw(petal4);
	Cvijet::m_window->draw(petal5);
	Cvijet::m_window->draw(petal6);
	Cvijet::m_window->draw(petal7);
	Cvijet::m_window->draw(petal8);
	Cvijet::m_window->draw(petal9);
	Cvijet::m_window->draw(petal10);
	Cvijet::m_window->draw(petal11);
	Cvijet::m_window->draw(petal12);

	Cvijet::m_window->draw(flower);

	

	//start of animation
	sf::Time pastTime = Cvijet::m_timer.restart();
	while (Cvijet::m_window->isOpen())
	{
		float rotateAngle = 2.f * pastTime.asSeconds();//calculate an angle depending on how much time has passed by
		float GrotateAngle = -rotateAngle;

		//rotate every petal
		petal.rotate(rotateAngle);
		petal2.rotate(rotateAngle);
		petal3.rotate(rotateAngle);
		petal4.rotate(rotateAngle);
		petal5.rotate(rotateAngle);
		petal6.rotate(rotateAngle);
		petal7.rotate(GrotateAngle);
		petal8.rotate(GrotateAngle);
		petal9.rotate(GrotateAngle);
		petal10.rotate(GrotateAngle);
		petal11.rotate(GrotateAngle);
		petal12.rotate(GrotateAngle);

		//draw the petals in their new position
		Cvijet::m_window->draw(petal);
		Cvijet::m_window->draw(petal2);
		Cvijet::m_window->draw(petal3);
		Cvijet::m_window->draw(petal4);
		Cvijet::m_window->draw(petal5);
		Cvijet::m_window->draw(petal6);
		Cvijet::m_window->draw(petal7);
		Cvijet::m_window->draw(petal8);
		Cvijet::m_window->draw(petal9);
		Cvijet::m_window->draw(petal10);
		Cvijet::m_window->draw(petal11);
		Cvijet::m_window->draw(petal12);
		//redraw the flower button so it's not under the petals
		Cvijet::m_window->draw(flower);

		//set the petals back 
		petal.rotate(-2*rotateAngle);
		petal2.rotate(-2*rotateAngle);
		petal3.rotate(-2*rotateAngle);
		petal4.rotate(-2*rotateAngle);
		petal5.rotate(-2*rotateAngle);
		petal6.rotate(-2*rotateAngle);
		petal7.rotate(-2 * GrotateAngle);
		petal8.rotate(-2 * GrotateAngle);
		petal9.rotate(-2 * GrotateAngle);
		petal10.rotate(-2 * GrotateAngle);
		petal11.rotate(-2 * GrotateAngle);
		petal12.rotate(-2 * GrotateAngle);

		//color the petals black, insures old petals will disappear
		petal.setFillColor(sf::Color(0, 0, 0));
		petal2.setFillColor(sf::Color(0, 0, 0));
		petal3.setFillColor(sf::Color(0, 0, 0));
		petal4.setFillColor(sf::Color(0, 0, 0));
		petal5.setFillColor(sf::Color(0, 0, 0));
		petal6.setFillColor(sf::Color(0, 0, 0));
		petal7.setFillColor(sf::Color(0, 0, 0));
		petal8.setFillColor(sf::Color(0, 0, 0));
		petal9.setFillColor(sf::Color(0, 0, 0));
		petal10.setFillColor(sf::Color(0, 0, 0));
		petal11.setFillColor(sf::Color(0, 0, 0));
		petal12.setFillColor(sf::Color(0, 0, 0));

		//draw the black petals to cover the old petals
		//this only leaves a little red outline because the petals were moved by a small degree

		Cvijet::m_window->draw(petal7);
		Cvijet::m_window->draw(petal8);
		Cvijet::m_window->draw(petal9);
		Cvijet::m_window->draw(petal10);
		Cvijet::m_window->draw(petal11);
		Cvijet::m_window->draw(petal12);
		Cvijet::m_window->draw(petal);
		Cvijet::m_window->draw(petal2);
		Cvijet::m_window->draw(petal3);
		Cvijet::m_window->draw(petal4);
		Cvijet::m_window->draw(petal5);
		Cvijet::m_window->draw(petal6);

		//bring the petals back to the position they should be in
		petal.rotate(2*rotateAngle);
		petal2.rotate(2*rotateAngle);
		petal3.rotate(2*rotateAngle);
		petal4.rotate(2*rotateAngle);
		petal5.rotate(2*rotateAngle);
		petal6.rotate(2*rotateAngle);
		petal7.rotate(2 * GrotateAngle);
		petal8.rotate(2 * GrotateAngle);
		petal9.rotate(2 * GrotateAngle);
		petal10.rotate(2 * GrotateAngle);
		petal11.rotate(2 * GrotateAngle);
		petal12.rotate(2 * GrotateAngle);

		//recolor the petals 
		petal.setFillColor(sf::Color(0, 255, 0));
		petal2.setFillColor(sf::Color(0, 255, 0));
		petal3.setFillColor(sf::Color(0, 255, 0));
		petal4.setFillColor(sf::Color(0, 255, 0));
		petal5.setFillColor(sf::Color(0, 255, 0));
		petal6.setFillColor(sf::Color(0, 255, 0));
		petal7.setFillColor(sf::Color(255, 0, 0));
		petal8.setFillColor(sf::Color(255, 0, 0));
		petal9.setFillColor(sf::Color(255, 0, 0));
		petal10.setFillColor(sf::Color(255, 0, 0));
		petal11.setFillColor(sf::Color(255, 0, 0));
		petal12.setFillColor(sf::Color(255, 0, 0));

		//redraw the petals to have the full
		Cvijet::m_window->draw(petal);
		Cvijet::m_window->draw(petal2);
		Cvijet::m_window->draw(petal3);
		Cvijet::m_window->draw(petal4);
		Cvijet::m_window->draw(petal5);
		Cvijet::m_window->draw(petal6);
		Cvijet::m_window->draw(petal7);
		Cvijet::m_window->draw(petal8);
		Cvijet::m_window->draw(petal9);
		Cvijet::m_window->draw(petal10);
		Cvijet::m_window->draw(petal11);
		Cvijet::m_window->draw(petal12);

		Cvijet::m_window->draw(flower);

		Cvijet::m_window->display();
	}
	
}
