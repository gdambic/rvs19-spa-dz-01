#pragma 

#include <SFML/Graphics.hpp>
#include <iostream>

class Cvijet
{
private:
	sf::RenderWindow* window;

	//cvijet
	float radius = 50.f;
	float sirina = 10.f;
	float visina = 150.f;
	float tjelo_x = (radius + radius / 3) + 50;		//polumjer unutarnjeg kruga plus sirina vanjskog kruga -> tako je definirano u metodi "napravi_krug"
	float tjelo_y = (radius + radius / 3) *2 + 50;					//duplo je veci zato jer tjelo_x je pola kruga
	
	sf::CircleShape napravi_krug(float radius);
	sf::RectangleShape napravi_tjelo(float sirina, float visina, float radius);
	sf::ConvexShape napravi_list();
	sf::CircleShape napravi_sunce(float radius);


	sf::CircleShape kruznica = napravi_krug(radius);
	sf::RectangleShape tjelo_cvijeta = napravi_tjelo(sirina, visina, radius);
	sf::ConvexShape list_romb = napravi_list();
	sf::CircleShape sunce1 = napravi_sunce(15);
	sf::CircleShape sunce2 = napravi_sunce(25);
	int n = 0;

public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

