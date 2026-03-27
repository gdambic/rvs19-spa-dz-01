#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Cvijet
{
private:
	sf::RenderWindow* window;
	/*sf::CircleShape latica01;
	sf::CircleShape latica02;
	sf::CircleShape latica03;
	sf::CircleShape latica04;
	sf::CircleShape latica05;
	sf::CircleShape latica06;*/

	std::vector<sf::CircleShape> latice;

	sf::CircleShape tucak01;
	sf::CircleShape tucak02;

	sf::RectangleShape stabljika;

	sf::CircleShape list01;
	sf::CircleShape list02;

	// DODANO ZA ANIMACIJU
	sf::Clock clock;
	float baseX = 200.f;

public:
	Cvijet(sf::RenderWindow* window);

	void set_latica01(sf::CircleShape& latica01);
	sf::CircleShape get_latica01();

	void set_latica02(sf::CircleShape& latica02);
	sf::CircleShape get_latica02();

	void set_latica03(sf::CircleShape& latica03);
	sf::CircleShape get_latica03();

	void set_latica04(sf::CircleShape& latica04);
	sf::CircleShape get_latica04();

	void set_latica05(sf::CircleShape& latica05);
	sf::CircleShape get_latica05();

	void set_latica06(sf::CircleShape& latica06);
	sf::CircleShape get_latica06();

	void set_tucak01(sf::CircleShape& tucak01);
	sf::CircleShape get_tucak01();

	void set_tucak02(sf::CircleShape& tucak02);
	sf::CircleShape get_tucak02();

	void set_stabljika(sf::RectangleShape& stabljika);
	sf::RectangleShape get_stabljika();

	void set_list01(sf::CircleShape& list01);
	sf::CircleShape get_list01();

	void set_list02(sf::CircleShape& list02);
	sf::CircleShape get_list02();

	// DODANO
	void update();

	void draw();
};