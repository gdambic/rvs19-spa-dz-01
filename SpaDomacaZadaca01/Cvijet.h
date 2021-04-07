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
	
	sf::Clock clock;
	
	
	float x = 100.0f;
	float brzina = 100.0f;
	
	sf::CircleShape kruna2;
	sf::Time dt;

public:

	Cvijet(sf::RenderWindow& window);

	void set_anim(sf::CircleShape& kruna2, sf::Clock& clock);
	void draw_glava(sf::CircleShape& oblik);
	void draw_tijelo(sf::RectangleShape& line, sf::RectangleShape& line2);
	void draw_latice(sf::ConvexShape& latica1, sf::ConvexShape& latica2);
	void draw_kruna(sf::CircleShape& kruna);
	void draw_animirani(sf::Time& dt);
	void draw();
};


