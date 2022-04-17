#include "cvijet.h"
#include <SFML/Graphics.hpp>
#include<vector>
using namespace sf;

Cvijet::Cvijet(sf::RenderWindow& window)
{
	sunce.setRadius(30);
	sunce.setFillColor(Color(200, 200, 0));
	sunce.setPosition(500, 50);

	krug2.setRadius(80);
	krug2.setFillColor(Color(200, 200, 0));
	krug2.setPosition(200, 200);	
	krug.setRadius(100);
	krug.setFillColor(Color(200, 20, 0));
	krug.setPosition(180, 180);
	stabiljka.setSize(Vector2f(30, 600));
	stabiljka.setFillColor(Color(0, 200, 0));
	stabiljka.setPosition(270, 215);
}
void Cvijet::draw(sf::RenderWindow &window)
{
	window.draw(stabiljka);
	window.draw(krug);
	window.draw(krug2);
	window.draw(sunce);
}
