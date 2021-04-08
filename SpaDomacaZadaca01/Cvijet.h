#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:


	sf::RenderWindow &window;
	sf::CircleShape oblik;
	sf::RectangleShape line;
	sf::RectangleShape line2;
	sf::ConvexShape latica1;
	sf::ConvexShape latica2;
	sf::CircleShape kruna;
	sf::RectangleShape zemlja;

	
	sf::Clock clock;
	
	
	float x = 1;
	float brzina = 100;
	
	sf::CircleShape kruna2;
	sf::Time dt;

public:

	Cvijet(sf::RenderWindow& window);

	void draw_kruna2(sf::CircleShape& kruna2, sf::Clock& clock, sf::Time& dt);
	void draw_glava(sf::CircleShape& oblik);
	void draw_zemlja(sf::RectangleShape& zemlja);
	void draw_tijelo(sf::RectangleShape& line, sf::RectangleShape& line2);
	void draw_latice(sf::ConvexShape& latica1, sf::ConvexShape& latica2);
	void draw_kruna(sf::CircleShape& kruna);
	void draw();
};


