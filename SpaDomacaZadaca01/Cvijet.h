#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet 
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	sf::CircleShape get_sunce() const;
	void set_sunce(const sf::CircleShape sunce);
	std::vector<sf::CircleShape> get_latice() const;
	void set_latice(const std::vector<sf::CircleShape> latice);
	sf::CircleShape get_tucak() const;
	void set_tucak(const sf::CircleShape tucak);
	sf::ConvexShape get_peteljka() const;
	void set_peteljka(const sf::ConvexShape peteljka);
	float get_konstanta() const;
	void set_konstanta(const float konstanta);
	
private:
	sf::RenderWindow* window;
	sf::CircleShape sunce;
	std::vector<sf::CircleShape> latice;
	sf::CircleShape tucak;
	sf::ConvexShape peteljka;
	sf::Clock frameClock;
	float konstanta;
};

