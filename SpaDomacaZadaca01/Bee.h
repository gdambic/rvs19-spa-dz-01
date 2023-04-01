#pragma once
#include <SFML/Graphics.hpp>

class Bee
{
private:
	sf::RenderWindow* window;

	sf::CircleShape body;
	sf::CircleShape head;
	sf::CircleShape sting;
	sf::CircleShape wing1;
	sf::CircleShape wing2;

	float x = 200;
	float y = 200;

	bool up, down, left, right;
public:
	Bee(sf::RenderWindow* window) 
	{
		this->window = window;

		body.setRadius(13);
		body.setFillColor(sf::Color::Yellow);
		body.setOutlineThickness(2);
		body.setOutlineColor(sf::Color::Black);
		body.setPosition(x, y);
		
		head.setRadius(8);
		head.setFillColor(sf::Color::Yellow);
		head.setOutlineThickness(1.5);
		head.setOutlineColor(sf::Color::Black);
		head.setPosition(x-10, y+5);

		sf::CircleShape sting_(10, 3);
		sting = sting_;
		
		sting.setPosition(x + 15, y+8);
		sting.setFillColor(sf::Color::Black);
		sting.rotate(-40);

		wing1.setRadius(7);
		wing1.setPosition(x, y-7);
		wing1.setFillColor(sf::Color(240, 240, 240, 255));
		wing1.setOutlineColor(sf::Color::Black);
		wing1.setOutlineThickness(1);

		wing2.setRadius(7);
		wing2.setPosition(x + 9, y - 7);
		wing2.setFillColor(sf::Color(240, 240, 240, 255));
		wing2.setOutlineColor(sf::Color::Black);
		wing2.setOutlineThickness(1);

		up = false;
		down = false;
		left = false;
		right = false;
	}

	void draw() 
	{
		window->draw(body); 
		window->draw(head); 
		window->draw(sting);
		window->draw(wing1); 
		window->draw(wing2); 
	}

	void processEvents(sf::Keyboard::Key key, bool checkPressed) 
	{
		if (checkPressed == true) {
			if (key == sf::Keyboard::Up)
				up = true;
			if (key == sf::Keyboard::Down)
				down = true;
			if (key == sf::Keyboard::Left)
				left = true;
			if (key == sf::Keyboard::Right)
				right = true;
		} 

		if (checkPressed == false) {
			up = false;
			down = false;
			left = false;
			right = false;
		}
	}

	void fly(sf::Vector2f move) {
		
		body.move(move);
		head.move(move);
		sting.move(move);
		wing1.move(move);
		wing2.move(move);
	}

	void update()
	{
		sf::Vector2f movement;
		if (up) 
			movement.y -= 3.0f;
		if (down)
			movement.y += 3.0f;
		if (left)
			movement.x -= 3.0f;
		if (right) {
			movement.x += 3.0f;
		}
		
		fly(movement);
	}
};

