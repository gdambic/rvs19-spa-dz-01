#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
private:
	sf::RenderWindow* window;
	int nKockast;
	float cKockast;
	int kKockast;
	std::vector<sf::RectangleShape> laticeKockast;
	std::vector<sf::CircleShape> stabljikaKockast;
	int nKruzic;
	float cKruzic;
	int kKruzic;
	std::vector<sf::CircleShape> laticeKruzic;
	std::vector<sf::CircleShape> stabljikaKruzic;
	int nRuza;
	float cRuza;
	int kRuza;
	std::vector<sf::CircleShape> laticeRuza;
	std::vector<sf::CircleShape> stabljikaRuza;

public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void drawCvijetKockast();
	void drawStabljikaKockast();
	void drawCvijetKruzic();
	void drawStabljikaKruzic();
	void drawCvijetRuza();
	void drawStabljikaRuza();
};