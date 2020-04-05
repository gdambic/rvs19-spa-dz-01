#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
public:
	Cvijet(sf::RenderWindow& window);

	sf::CircleShape get_crveniKrug();
	sf::CircleShape get_zutiKrug();
	sf::CircleShape get_maliKrug();
	sf::ConvexShape get_listBiljke();
	sf::RectangleShape get_linija();
	void draw();


private:
	sf::RenderWindow& window;
	sf::CircleShape crveniKrug;
	sf::CircleShape zutiKrug;
	sf::CircleShape maliKrug;
	sf::ConvexShape listBiljke;
	sf::RectangleShape linija;
	sf::Clock clock;

};

