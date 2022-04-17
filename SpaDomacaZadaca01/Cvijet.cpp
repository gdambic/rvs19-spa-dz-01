#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow *window) 
{
	
	this->window = window;
}


//metoda koja crta i animira sunce pomocu frameClocka
void Cvijet::drawSunce()
{
	sf::Texture texture4;
	texture4.loadFromFile("res/sunnce.jpg");

	//sunce
	sf::CircleShape sunce(90);
	sunce.setTexture(&texture4);
	

	//petlja koja postavlja poziciju sunca 
	if (frameClock.getElapsedTime().asMilliseconds() > 6000)
	{

		sunce.setPosition(0.f - 150.f * (frameClock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);

		if (frameClock.getElapsedTime().asMilliseconds() >= 2000)
		{
			frameClock.restart();
		}
	}
	else
	{
		sunce.setPosition(0.f + 150.f * (frameClock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);
	}
	window->draw(sunce);
}


void Cvijet::draw()
{
	//texture potrebne za crtanje
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture_background;
	sf::Texture texture3;
	
	

	
	//znam da bi tu trebala biti provjera dal je nasao file ali nisam uspio
	texture_background.loadFromFile("res/background.jpg");
	texture3.loadFromFile("res/list.png");
	texture1.loadFromFile("res/cvijet1.jpg");
	texture2.loadFromFile("res/cvijet2.jpg");
	

	

	//pozadina
	sf::Sprite s(texture_background);

	//stabiljka
	sf::RectangleShape rectangle(sf::Vector2f(10.f, 400.f));
	rectangle.setPosition(210.f, 300.f);
	rectangle.setTexture(&texture3);

	//vanjski dio cvijeta
	sf::CircleShape octagon(110.f, 8);
	octagon.setPosition(110.f, 200.f);
	octagon.setTexture(&texture2);


	//unutarnji dio cvijeta
	sf::CircleShape circle(65);
	circle.setPosition(150.f, 260.f);
	circle.setTexture(&texture1);
	



	//list
	sf::CircleShape list(80.f, 3);
	list.setPosition(210.f, 350.f); 
	list.setTexture(&texture3);


	//crtanje 
	window->draw(s);
	window->draw(rectangle);
	window->draw(octagon);
	window->draw(circle);
	window->draw(list);
	drawSunce();




	
	
	

}


