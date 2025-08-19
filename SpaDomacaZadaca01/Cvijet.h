#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
private:
	sf::CircleShape tucak;
	std::vector<sf::CircleShape> latice;
	sf::RectangleShape stabljika;
	sf::CircleShape list;
	bool ran;
	int i;
	sf::Color color;
public:
	Cvijet(sf::RenderWindow& window);

	void anim(sf::Clock& clock);

	sf::CircleShape get_tucak() const;
	sf::RectangleShape get_stabljika() const;
	std::vector<sf::CircleShape> get_latice()const;
	sf::CircleShape get_list()const;
	void set_tucak(const sf::CircleShape tucak);
	void set_stabljuka(const sf::RectangleShape stabljika);
	void set_list(const sf::CircleShape list);
	void set_latica(const sf::CircleShape latica, const int i);
	bool get_ran() const;

	void set_ran(const bool ran);
};