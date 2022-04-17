#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Cvijet
{
private:
	float raindropVelocity = 2;
	sf::Vector2f raindropPosition = sf::Vector2f(175, 75);
	sf::Vector2f raindropPosition2 = sf::Vector2f(175, -150);
	sf::RectangleShape raindrop;
	sf::RectangleShape raindrop2;
	sf::RenderWindow* window;
    std::array<sf::ConvexShape, 4> petals1;
    std::array<sf::ConvexShape, 4> petals2;
	std::array<sf::ConvexShape, 16> grass1;
	std::array<sf::ConvexShape, 16> grass2;
	sf::ConvexShape leaf;
	sf::CircleShape circle;
	int circle_radius = 50;
	sf::CircleShape sun;
	sf::RectangleShape stem;
	sf::RectangleShape ground;
	sf::RectangleShape sky;
    sf::Vector2f circle_center = sf::Vector2f(-300, -275);
    sf::Transform transform;
	sf::Transform transform2;
	sf::ConvexShape cloud;
	std::array<sf::RectangleShape, 6> raindrops;
	std::array<sf::RectangleShape, 6> raindrops2;

public:
	Cvijet(sf::RenderWindow* window);
	int get_rnd(int min, int max);
	void set_leaf();
	void set_circle();
	void set_stem();
	void set_sun();
	void set_background();
	void set_cloud();
	void set_raindrops();
	void set_raindrops2();
	void draw();
};
