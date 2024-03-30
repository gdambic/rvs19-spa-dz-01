#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
private:
	RenderWindow* wind;
	sf::Vector2u windowSize;
	sf::Clock clock;
	sf::Time time;
	sf::RectangleShape petal;
	sf::RectangleShape stabiljk;
	sf::CircleShape core;

	sf::RectangleShape cloud1;
	sf::CircleShape cloud2;
	sf::CircleShape cloud3;
	sf::CircleShape cloud4;
	sf::CircleShape cloud5;

	sf::RectangleShape ground;
	sf::RectangleShape ground2;
	sf::RectangleShape back_ground;

	//list
	int smoother = 80;
	int size_list = 110;
	int x_offset = 112;
	int y_offset = 180;

	float x_ofset;
	float y_ofset;

	sf::ConvexShape Lightning1;
	sf::ConvexShape Lightning2;
	sf::ConvexShape Lightning3;

	//sf::Color dark_blue; //zasto ne mogu tu setati color neg onda u metodi moram dark_blue.r dark_blue.g itd...
	//radio sam colore u metodama jer mi ovo nema smisla

public:
	Cvijet(RenderWindow* window);
	void draw();
	float get_x_center();
	float get_y_center();
	void background();
	void list();
	void petals();
	void stabiljka();
	void core_cvijeta();
	void oci();
	void usne();
	void kisa();
	void cloud();
	void zemlja();
	void munja();
};

