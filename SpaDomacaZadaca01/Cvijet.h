#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Cvijet
{
public:

	Cvijet(sf::RenderWindow* window);

	void draw();

	void animate_shape_tucak(sf::CircleShape& c);
	
	//Sredina cvijeta
	sf::CircleShape get_tucak() const;
	void set_tucak(const sf::CircleShape tucak);

	//Stabiljka
	sf::RectangleShape get_stabljika() const;
	void set_stabljika(const sf::RectangleShape stabljika);

	//Latice
	sf::CircleShape get_latica()const;
	void set_latica(const sf::CircleShape latica);

	//Listovi
	sf::CircleShape get_list()const;
	void set_list(const sf::CircleShape list);

	//Zemlja
	sf::RectangleShape get_Zemlja() const;
	void set_Zemlja(const sf::RectangleShape zemlja);


	//TESTIRANJE
	sf::RectangleShape get_testing()const;
	void set_testing(const sf::RectangleShape testing);

	//ANIMIRANJE

private:
	//Prozor
	sf::RenderWindow *window;

	//Krugovi
	sf::CircleShape tucak;
	sf::CircleShape list;
	sf::CircleShape latica;

	//Pravokutinici
	sf::RectangleShape stabljika;
	sf::RectangleShape zemlja;
	sf::RectangleShape testing;

	//Vrijeme i boje 
	//sf::Clock clock; 
	//
	//sf::Color color1 = sf::Color(255, 255, 0);
	//sf::Color color2 = sf::Color(255, 51, 0);
	//
	//sf::Time time1 = sf::seconds(rand());
	//sf::Time time2= sf::seconds(3);
	//sf::Time time3 = sf::seconds(4.5);
	
};

