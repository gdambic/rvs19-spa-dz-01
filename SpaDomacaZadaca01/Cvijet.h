#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <array>

class Cvijet
{
	// ~~~ Konstante
	std::string textures[8] = { "textures/sunmun-0.png", "textures/sunmun-1.png", "textures/sunmun-2.png", "textures/sunmun-3.png", "textures/sunmun-4.png", "textures/sunmun-5.png", "textures/sunmun-6.png", "textures/sunmun-7.png" };
	const std::string flowerpoints = "flowerpoints";
	const std::string stalkpoints = "stalkpoints";
	const unsigned int width = 730;
	const unsigned int height = 1163;

	// ~~~ Varijable
	unsigned short r = rand() % 255;
	unsigned short g = rand() % 255;
	unsigned short b = rand() % 255;
	int d = 1;
	bool mun = true;
	bool deltaplus = true;
	sf::RenderWindow* window;
	sf::RectangleShape background;
	sf::RectangleShape sunmun;
	sf::Texture texture_background;
	sf::Texture texture_sunmun;
	float windowsize[2];
	float scale = 0.45;
	float move[2];
	int delta = 25;
	unsigned short texture = 0;


	// ~~~ Tocke
	std::vector<std::vector<std::array<float, 2>>> petals;
	std::vector<std::vector<std::array<float, 2>>> stalks;
	sf::ConvexShape* petal_convex;
	sf::ConvexShape* petal_shadow;
	sf::ConvexShape* stalk_convex;
	sf::ConvexShape* stalk_shadow;
	sf::Text* numbies;

	// ~~~ Funkcije
	void setup();
	void latice();
	void stalak();
	void background_setup();

public:
	Cvijet(sf::RenderWindow *window);
	void draw(sf::Time elapsedTime);
};

