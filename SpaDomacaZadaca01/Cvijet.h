#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	
	sf::RectangleShape ground;
	sf::CircleShape sun;

	void draw_petal(float x, float y, float px, float py);
	void draw_cloud(float x, float y, bool r);
	void draw_cloud_part(float x, float y, bool r);

public:

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
		bool mid = false;

		sf::Text text;
		sf::Font font;
		int count = 0;

		void highlight_flower(float x, float y);

	public:
		Bee(sf::RenderWindow* window);
		void draw();
		void processEvents(sf::Keyboard::Key key, bool checkPressed);
		void fly(sf::Vector2f move);
		void update();
	};

	Cvijet(sf::RenderWindow* window);
	void draw(float radius);
	void draw_flower(float x, float y, sf::Color c);
};

