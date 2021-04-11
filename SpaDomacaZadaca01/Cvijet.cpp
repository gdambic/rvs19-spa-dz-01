#pragma once
#include "Cvijet.h"/*
#include "Source.cpp"*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <corecrt_wtime.h>
#include <ctime>

using namespace std;


Cvijet::Cvijet(sf::RenderWindow* window) : mWindow(window) {
	
}
void Cvijet::animacija()
{
	sf::Clock clock;
	sf::Event event;
	// Change to start the animation
	// Red and blue to store the color transition
	// Duration to control animation speed
	int change = 0;
	int red = 255;
	int blue = 0;
	float duration = float();

	// Set a basic red circle as the starting shape
	//sf::Color color = sf::Color::Red;
	//sf::CircleShape circle(150);
	//circle.setFillColor(color);

	//	moj cvijet
	sf::Color color = sf::Color::Red;
	sf::CircleShape shape1(25.f);
	shape1.setFillColor(color);
	shape1.move(360, 310);

	
	while (mWindow->isOpen()) {
		// How much time since last loop?
		sf::Time dt = clock.restart();
		duration += dt.asSeconds();

		while (mWindow->pollEvent(event)) {
			//Handle events here
			if (event.type == sf::Event::EventType::Closed)
				mWindow->close();

			//Respond to key pressed events
			if (event.type == sf::Event::EventType::KeyPressed) {
				if (event.key.code == sf::Keyboard::C) {
					// C key pressed, start animation
					change = 1;
				}
			}
		}

		// Animation started and animation duration per frame (0.01f) reached
		// Change color by 1 
		if (change == 1 && duration > 0.01f) {
			red -= 1;
			blue += 1;
			if (red > 0) {
				// Reset frame time and set new color for circle
				duration = 0;
				color = sf::Color(red, 0, blue);
				shape1.setFillColor(color);
			}
			else {
				// Stop animation 
				change = 0;
			}
		}

		// Clear render window and draw circle
		mWindow->clear(sf::Color::Black);
		draw();
		mWindow->draw(shape1);
		mWindow->display();
	}

}

void Cvijet::draw()
{
	//alien

	// define a triangle
	sf::CircleShape triangle2(200.f, 3);
	triangle2.rotate(0.f);
	triangle2.setFillColor(sf::Color(245, 215, 0));
	triangle2.move(180, 100);

	mWindow->draw(triangle2);
	
	sf::RectangleShape line4(sf::Vector2f(80.f, 40.f));
	line4.rotate(0.f);
	line4.setFillColor(sf::Color(128, 128, 128));
	line4.move(340, 100);

	mWindow->draw(line4);

	sf::CircleShape shape12(20.f);

	shape12.setFillColor(sf::Color(128, 128, 128));
	shape12.move(320, 100);

	mWindow->draw(shape12);

	sf::CircleShape shape13(20.f);

	shape13.setFillColor(sf::Color(128, 128, 128));
	shape13.move(400, 100);

	mWindow->draw(shape13);

	sf::CircleShape shape14(40.f);

	shape14.setFillColor(sf::Color(128, 128, 128));
	shape14.move(340, 60);

	mWindow->draw(shape14);

	// CVIJET

	sf::RectangleShape line(sf::Vector2f(280.f, 8.f));
	line.rotate(80.f);
	line.setFillColor(sf::Color(100, 250, 50));
	line.move(385, 330);

	mWindow->draw(line);

	sf::CircleShape shape2(35.f);
	
	shape2.setFillColor(sf::Color(255, 255, 255));
	shape2.move(325, 300);

	mWindow->draw(shape2);

	sf::CircleShape shape3(35.f);
	
	shape3.setFillColor(sf::Color(255, 255, 255));
	shape3.move(350, 275);

	mWindow->draw(shape3);

	sf::CircleShape shape4(35.f);
	
	shape4.setFillColor(sf::Color(255, 255, 255));
	shape4.move(375, 300);

	mWindow->draw(shape4);

	sf::CircleShape shape5(35.f);
	
	shape5.setFillColor(sf::Color(255, 255, 255));
	shape5.move(350, 325);

	mWindow->draw(shape5);

	sf::CircleShape triangle(45.f, 3);
	triangle.rotate(200.f);
	triangle.setFillColor(sf::Color(100, 250, 50));
	triangle.move(463, 550);

	mWindow->draw(triangle);

	//OBLAK
	sf::CircleShape shape6(30.f);
	sf::CircleShape shape7(30.f);
	sf::CircleShape shape8(30.f);

	shape6.setFillColor(sf::Color(0, 255, 255));
	shape6.move(70, 150);

	shape7.setFillColor(sf::Color(0, 255, 255));
	shape7.move(110, 135);

	shape8.setFillColor(sf::Color(0, 255, 255));
	shape8.move(150, 150);

	mWindow->draw(shape6);
	mWindow->draw(shape7);
	mWindow->draw(shape8);

	sf::RectangleShape line2(sf::Vector2f(100.f, 20.f));
	line2.rotate(0.f);
	line2.setFillColor(sf::Color(0, 255, 255));
	line2.move(90, 189);

	mWindow->draw(line2);


	//OBLAK desni
	sf::CircleShape shape9(30.f);
	sf::CircleShape shape10(30.f);
	sf::CircleShape shape11(30.f);

	shape9.setFillColor(sf::Color(0, 255, 255));
	shape9.move(630, 270);

	shape10.setFillColor(sf::Color(0, 255, 255));
	shape10.move(670, 255);

	shape11.setFillColor(sf::Color(0, 255, 255));
	shape11.move(710, 270);

	mWindow->draw(shape9);
	mWindow->draw(shape10);
	mWindow->draw(shape11);

	sf::RectangleShape line3(sf::Vector2f(100.f, 20.f));
	line3.rotate(0.f);
	line3.setFillColor(sf::Color(0, 255, 255));
	line3.move(650, 309);

	mWindow->draw(line3);


	// bijela Color(255, 255, 255)
	// zelena Color(100, 250, 50)
	// narancasta Color(250, 150, 100)
	// Oblak plava Color(0, 255, 255)
	// Alien zelena Color(0, 128, 128)
	// Alien zuta Color(255, 255, 0)

	
	

	return;
}
