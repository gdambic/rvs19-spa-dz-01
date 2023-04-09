#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Cvijet
{
private:
	sf::RenderWindow* window;
	bool swtchsde = false;
	bool swtchsde2 = false;
	bool swtchsde3 = false;
	bool attempttexture1 = true;
	bool attempttexture2 = true;
	int cloudinit = 100;
	int size1 = 50, size2 = 30;
	int cloudsize = 30;
	int testcounter = 0;
	int darkvalue = 0;
	int sunsize = 30;
	float angle = 0.0;
	float rayangle = 0.0;
	float rayangleinit = 0.0;
	float rayangledelta = 0.0;
	float angle2 = 0.0;
	float angle3 = 0.0;
	//sf::Vector2f cloud[7] = { {cloudinit,cloudinit},{cloudinit+10,cloudinit-20},{cloudinit+30,cloudinit-30},{cloudinit+70,cloudinit-30},{cloudinit+100,cloudinit},{cloudinit+40,cloudinit},{cloudinit+70,cloudinit} };
	//sf::Vector2f initcloud[7] = { {0,100},{10,80},{30,70},{70,70},{100,100},{40,100},{70,100} };
	sf::Clock frameClock;
	sf::Texture texture, texture2;
	sf::Vector2f initcloud[7] = { {-130,100},{-120,80},{-100,70},{-60,70},{-30,100},{-90,100},{-60,100} };
	sf::Vector2f cloud[7] = { {100,100},{110,80},{130,70},{170,70},{200,100},{140,100},{170,100} };
	sf::Vector2f initcloud2[7] = { {-130,80},{-120,60},{-100,50},{-60,50},{-30,80},{-90,80},{-60,80} };
	sf::Vector2f cloud2[7] = { {100,80},{110,60},{130,50},{170,50},{200,80},{140,80},{170,80} };
	sf::CircleShape sun;
	sf::CircleShape shape2;
	sf::CircleShape trianglear[8];
	sf::CircleShape shape;
	sf::RectangleShape rectangle;
	sf::RectangleShape rectanglebck;
	sf::RectangleShape rectanglebck2;
	sf::RectangleShape dark;
	void loadtexture(std::string name, sf::CircleShape& shape, sf::Texture& texture);
	void runanimation(sf::CircleShape& shape, float& angle, bool& swtchsde, float animationangle);
	void runanimation(sf::ConvexShape& shape, float& angle, bool& swtchsde, float animationangle); //for Convex
	void drawbackground();
	void runclouds();
	void runclouds2();
	void runray();
	void setsun();
	void cloudanimate3(double clouddelta, sf::Vector2f cloud[7], sf::Vector2f initcloud[7]);
	void sunanimate(double angledelta, sf::CircleShape& triangle);
	void telemetry(sf::CircleShape& shape);
	void drawclouds();
	void checkcloudobstruction();
	//sf::ConvexShape convex; // Not here
public:
	Cvijet(sf::RenderWindow* window );
	void draw();
};

