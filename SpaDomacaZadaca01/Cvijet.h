#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
	sf::Color randColor();
	sf::RectangleShape background(sf::Vector2u& prozorDim, const sf::Color boja);
	void set_tekstura(std::string file);
	void set_krug(float velicina, float x, float y, float outlineThickness);
	void set_latice(float velicina, int listovi, sf::Color boja, float x, float y);
	void set_trava(float visina);
	void set_sunce();
private:
	sf::RenderWindow *window;
	sf::Texture tekstura;
	sf::CircleShape krug;
	sf::CircleShape latice;
	sf::RectangleShape sunce;
	sf::RectangleShape trava;
	sf::RectangleShape stabiljka;
};