#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}
void Cvijet::loadtexture(std::string name ,sf::CircleShape& shape, sf::Texture& texture) {
	if (!texture.loadFromFile(name))
	{
		throw std::exception("Texture load error"); // Extra
	}
	shape.setTexture(&texture);
}
void Cvijet::telemetry(sf::CircleShape& shape) { // Optional
	sf::Vector2f position = shape.getPosition();
	std::cout << "X: " << position.x << " Y: " << position.y << " Angle: " << shape.getRotation() << std::endl;
}
void Cvijet::drawbackground() {
	sf::Vector2f recsizebck(800, 600); //(this->window->getSize().x, this->window->getSize().y)
	rectanglebck.setSize(recsizebck);
	rectanglebck2.setSize(recsizebck);
	rectanglebck.setOrigin(recsizebck.x / 2, recsizebck.y / 2);
	rectanglebck.setPosition(400, 300);
	rectanglebck.setFillColor(sf::Color(31, 165, 255)); //sf::Color(31, 165, 255)
	rectanglebck2.setOrigin(recsizebck.x / 2, recsizebck.y / 2);
	rectanglebck2.setPosition(400, 800);
	rectanglebck2.setFillColor(sf::Color(32, 201, 55)); //sf::Color(41, 255, 69)
	window->draw(rectanglebck);
	window->draw(rectanglebck2);
}
void Cvijet::runclouds() {

	sf::CircleShape cloud1(cloudsize), cloud2(cloudsize), cloud3(cloudsize), cloud4(cloudsize), cloud5(cloudsize), cloud6(cloudsize), cloud7(cloudsize); // Easier
	cloud1.setOrigin(cloudsize, cloudsize);
	cloud2.setOrigin(cloudsize, cloudsize);
	cloud3.setOrigin(cloudsize, cloudsize);
	cloud4.setOrigin(cloudsize, cloudsize);
	cloud5.setOrigin(cloudsize, cloudsize);
	cloud6.setOrigin(cloudsize, cloudsize);
	cloud7.setOrigin(cloudsize, cloudsize);
	cloud1.setPosition(cloud[0]);
	cloud2.setPosition(cloud[1]);
	cloud3.setPosition(cloud[2]);
	cloud4.setPosition(cloud[3]);
	cloud5.setPosition(cloud[4]);
	cloud6.setPosition(cloud[5]);
	cloud7.setPosition(cloud[6]);
	window->draw(cloud1);
	window->draw(cloud2);
	window->draw(cloud3);
	window->draw(cloud4);
	window->draw(cloud5);
	window->draw(cloud6);
	window->draw(cloud7);
	cloudanimate3(2, cloud, initcloud);
}
void Cvijet::runclouds2() {

	sf::CircleShape cloud7(cloudsize), cloud8(cloudsize), cloud9(cloudsize), cloud10(cloudsize), cloud11(cloudsize), cloud12(cloudsize), cloud13(cloudsize); // Easier
	cloud7.setOrigin(cloudsize, cloudsize);
	cloud8.setOrigin(cloudsize, cloudsize);
	cloud9.setOrigin(cloudsize, cloudsize);
	cloud10.setOrigin(cloudsize, cloudsize);
	cloud11.setOrigin(cloudsize, cloudsize);
	cloud12.setOrigin(cloudsize, cloudsize);
	cloud13.setOrigin(cloudsize, cloudsize);
	cloud7.setPosition(cloud2[0]);
	cloud8.setPosition(cloud2[1]);
	cloud9.setPosition(cloud2[2]);
	cloud10.setPosition(cloud2[3]);
	cloud11.setPosition(cloud2[4]);
	cloud12.setPosition(cloud2[5]);
	cloud13.setPosition(cloud2[6]);
	window->draw(cloud7);
	window->draw(cloud8);
	window->draw(cloud9);
	window->draw(cloud10);
	window->draw(cloud11);
	window->draw(cloud12);
	window->draw(cloud13);
	cloudanimate3(1.75, cloud2, initcloud2);
}
void Cvijet::cloudanimate3(double clouddelta, sf::Vector2f cloud[7], sf::Vector2f initcloud[7])
{
	if (cloud[0].x >= 900) {
		for (int i = 0; i < 7; ++i) {
			cloud[i] = initcloud[i];
		}
	}
	else {
		for (int i = 0; i < 7; ++i) {
			cloud[i].x += clouddelta;
		}
	}
}
void Cvijet::sunanimate(double angledelta, sf::CircleShape& triangle) {
		triangle.rotate(angledelta);
		rayangledelta = rayangle + angledelta;
}
void Cvijet::runray() {
	rayangledelta = 0.5;

	trianglear[0] = { sf::CircleShape(25, 3) };
	trianglear[0].setOrigin(25,45);
	trianglear[0].setPosition(100,100);
	trianglear[0].setFillColor(sf::Color(255, 255, 51));;
	trianglear[0].setRotation(rayangleinit);
	trianglear[0].rotate(rayangledelta);
	//std::cout << "Rayangledelta: " << rayangledelta << " Rotation: " << trianglear[0].getRotation() << std::endl;
	for (int i = 1; i < 8; ++i) {
		trianglear[i] = trianglear[i-1];
		trianglear[i].rotate(45);
		rayangle += 45;
	}
	rayangleinit = trianglear[0].getRotation();
	window->draw(trianglear[0]);
	window->draw(trianglear[1]);
	window->draw(trianglear[2]);
	window->draw(trianglear[3]);
	window->draw(trianglear[4]);
	window->draw(trianglear[5]);
	window->draw(trianglear[6]);
	window->draw(trianglear[7]);
}
void Cvijet::setsun() {
	runray();
	sun.setRadius(sunsize);
	sun.setOrigin(sunsize, sunsize);
	sun.setPosition(100, 100);
	sun.setFillColor(sf::Color(255, 255, 51));
	if (attempttexture2 == true) {
		try {
			loadtexture("sun2.png", sun, texture2);
		}
		catch (const std::exception& err) {
			std::cout << err.what() << std::endl;
		}
		attempttexture2 = false;
	}
	//window->draw(sun);
	//sunanimate(); No

}
void Cvijet::drawclouds() {
	runclouds();
	runclouds2();
}
void Cvijet::draw()
{
	sf::Vector2f recsize(5, 150);
	shape.setRadius(size1);
	shape2.setRadius(size2);
	rectangle.setSize(recsize);
	sf::ConvexShape convex; //could be in private but this is for smoother animation
	shape.setOrigin(size1, size1);
	shape2.setOrigin(size2, size2);
	rectangle.setOrigin(recsize.x / 2, recsize.y / 2);
	rectangle.setFillColor(sf::Color(1, 120, 5));
	shape.setFillColor(sf::Color(150, 50, 250));
	//shape.setFillColor(sf::Color(0, 72, 186));
	//shape2.setFillColor(sf::Color(255, 213, 0));
	int pos1 = 150, pos2 = 350;
	shape.setPosition(pos1, pos2);
	shape2.setPosition(pos1, pos2);
	rectangle.setPosition(pos1, pos2 + 160);


	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(0, 20));
	convex.setPoint(1, sf::Vector2f(50, -15));
	convex.setPoint(2, sf::Vector2f(125, -30));
	convex.setPoint(3, sf::Vector2f(50, 20));
	convex.setFillColor(sf::Color(1, 120, 5));
	convex.setPosition(pos1, pos2 + 170);
	//default origin looks nicer
	//convex.setOrigin(0, 20);






	shape.setScale(2, 2);
	shape2.setScale(2, 2);
	rectangle.setScale(3, 2);
	convex.setScale(1.3, 1.3);



	//sf::Texture texture;
	//load texture
	if (attempttexture1 == true) {
		try {
			loadtexture("flower.png", shape2, texture);
		}
		catch (const std::exception& err) {
			std::cout << err.what() << std::endl;
		}
		attempttexture1 = false;
}
	// Clock
	sf::Time elapsed = frameClock.getElapsedTime();
	if (elapsed.asMilliseconds() >= 30) { //31.25
		//std::cout <<"Elapsed seconds: " << elapsed.asSeconds() << std::endl;
		runanimation(shape2, angle, swtchsde, 2.5);
		runanimation(convex, angle2, swtchsde2, 2.5);
		runanimation(sun, angle3, swtchsde3, 2.5);
		//
		//every frame animation is smoother. even if tied to framerate
		// 
		// 
		//cloudanimate3(2, cloud, initcloud);
		//cloudanimate3(1.75, cloud2, initcloud2);
		frameClock.restart();
	}
	//std::cout << angle << std::endl << std::endl;
	shape2.setRotation(angle);
	convex.rotate(angle2); //setRotation if it was in private part of class, this is for smoother animation
	sun.setRotation(angle3);


	// Last step
	drawbackground();
	setsun();
	window->draw(sun);
	drawclouds();
	// Didn't use a function to draw all shapes at the same time because source.cpp has window.display();
	window->draw(rectangle);
	window->draw(shape);
	window->draw(shape2);
	window->draw(convex);
	checkcloudobstruction();
	//telemetry(shape2);

}
void Cvijet::runanimation(sf::CircleShape& shape,float& angle,bool& swtchsde, float animationangle) { // Animation for flower
	//std::cout << this->angle << std::endl;
	if (angle == 30) {
		swtchsde = true;
	}
	if (angle == -30) {
		swtchsde = false;
	}
	if (swtchsde == false) {
		angle += animationangle;
	}
	if (swtchsde== true) {
		angle -= animationangle;
	}

}
void Cvijet::runanimation(sf::ConvexShape& shape,float& angle2, bool& swtchsde2, float animationangle) { // Animation for leaf
	//std::cout << this->angle2 << std::endl;
	if (angle2 == 15) {
		swtchsde2 = true;
	}
	if (angle2 == -15) {
		swtchsde2 = false;
	}
	if (swtchsde2 == false) {
		angle2 += animationangle;
	}
	if (swtchsde2 == true) {
		angle2 -= animationangle;
	}
}
void Cvijet::checkcloudobstruction() {
		sf::Vector2f darksize(800, 600); // Could also use (this->window->getSize().x, this->window->getSize().y)
		dark.setSize(darksize);
	if ((cloud[6].x +30 >= sun.getPosition().x -10 && !(cloud[0].x -30 >= sun.getPosition().x +10)) || (cloud2[6].x +30 >= sun.getPosition().x -10 && !(cloud2[0].x -30 >= sun.getPosition().x +10 ))) {
		this->testcounter += 1;
		std::cout << "cloud obstruction " << testcounter << std::endl;
		if (darkvalue < 120) {
			darkvalue += 10;
		}
		dark.setFillColor(sf::Color(0, 0, 0, darkvalue));
		window->draw(dark);
	}
	else {
		if (darkvalue > 0) {
			darkvalue -= 10;
		}
		dark.setFillColor(sf::Color(0, 0, 0, darkvalue));
		window->draw(dark);
	}
}
