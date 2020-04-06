#include "Cvijet.h"
#include <iostream>
#include <ctime>

using namespace std;


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw() const
{

	//stabiljka
	sf::RectangleShape linija(sf::Vector2f(198.f, 5.f));
	linija.setPosition(333.f, 409.f);
	linija.rotate(90.f);
	linija.setFillColor(sf::Color(100, 230, 90));
	window->draw(linija);

	//list
	sf::CircleShape list(60.f, 8);
	list.setFillColor(sf::Color::Transparent);
	list.setPosition(333.f, 415.f);
	list.setOutlineThickness(6.f);
	list.setOutlineColor(sf::Color(100, 230, 90));
	window->draw(list);

	//zilice na listu
	sf::RectangleShape list_dodatak(sf::Vector2f(121.f, 3.f));
	list_dodatak.setPosition(436.f, 432.f);
	list_dodatak.rotate(133.f);
	list_dodatak.setFillColor(sf::Color(100, 230, 90));
	window->draw(list_dodatak);

	sf::RectangleShape list_dodatak2(sf::Vector2f(72.f, 2.f));
	list_dodatak2.setPosition(352.f, 431.f);
	list_dodatak2.rotate(75.f);
	list_dodatak2.setFillColor(sf::Color(100, 230, 90));
	window->draw(list_dodatak2);

	sf::RectangleShape list_dodatak3(sf::Vector2f(52.f, 1.f));
	list_dodatak3.setPosition(393.f, 415.f);
	list_dodatak3.rotate(75.f);
	list_dodatak3.setFillColor(sf::Color(100, 230, 90));
	window->draw(list_dodatak3);

	sf::RectangleShape list_dodatak4(sf::Vector2f(69.f, 2.f));
	list_dodatak4.setPosition(438.f, 520.f);
	list_dodatak4.rotate(195.f);
	list_dodatak4.setFillColor(sf::Color(100, 230, 90));
	window->draw(list_dodatak4);

	sf::RectangleShape list_dodatak5(sf::Vector2f(49.f, 1.f));
	list_dodatak5.setPosition(453.f, 473.f);
	list_dodatak5.rotate(189.f);
	list_dodatak5.setFillColor(sf::Color(100, 230, 90));
	window->draw(list_dodatak5);

   //latice (osmerokut)
	sf::CircleShape baza(80.f, 8);
	baza.setFillColor(sf::Color(160,40,390));
	baza.setPosition(250.f, 245.f);
	baza.setOutlineThickness(6.f);
	baza.setOutlineColor(sf::Color(190, 70, 200));
	window->draw(baza);

	//tucak
	sf::CircleShape krug(28.f);
	krug.setFillColor(sf::Color(255, 215, 0));
	krug.setPosition(300.f, 300.f);
	krug.setOutlineThickness(6.f);
	krug.setOutlineColor(sf::Color(255, 180, 0));
	window->draw(krug);

	//kruzici na laticama
	sf::CircleShape kruzic1(4.f);
	kruzic1.setFillColor(sf::Color(160, 50, 470));
	kruzic1.setPosition(275.f, 340.f);
	window->draw(kruzic1);

	sf::CircleShape kruzic2(4.f);
	kruzic2.setFillColor(sf::Color(160, 50, 470));
	kruzic2.setPosition(368.f, 330.f);
	window->draw(kruzic2);

	sf::CircleShape kruzic3(4.f);
	kruzic3.setFillColor(sf::Color(160, 50, 470));
	kruzic3.setPosition(314.f, 263.f);
	window->draw(kruzic3);

	sf::CircleShape kruzic4(4.f);
	kruzic4.setFillColor(sf::Color(160, 50, 470));
	kruzic4.setPosition(360.f, 370.f);
	window->draw(kruzic4);

	sf::CircleShape kruzic5(4.f);
	kruzic5.setFillColor(sf::Color(190, 70, 200));
	kruzic5.setPosition(293.f, 370.f);
	window->draw(kruzic5);

	sf::CircleShape kruzic6(4.f);
	kruzic6.setFillColor(sf::Color(160, 50, 470));
	kruzic6.setPosition(360.f, 290.f);
	window->draw(kruzic6);

	sf::CircleShape kruzic7(4.f);
	kruzic7.setFillColor(sf::Color(190, 70, 200));
	kruzic7.setPosition(344.f, 268.f);
	window->draw(kruzic7);

	sf::CircleShape kruzic8(4.f);
	kruzic8.setFillColor(sf::Color(160, 50, 470));
	kruzic8.setPosition(323.f, 370.f);
	window->draw(kruzic8);

	sf::CircleShape kruzic9(4.f);
	kruzic9.setFillColor(sf::Color(190, 70, 200));
	kruzic9.setPosition(269.f, 295.f);
	window->draw(kruzic9);

	sf::CircleShape kruzic10(4.f);
	kruzic10.setFillColor(sf::Color(190, 70, 200));
	kruzic10.setPosition(385.f, 304.f);
	window->draw(kruzic10);

	//trava
    sf::RectangleShape povrsina(sf::Vector2f(800.f, 32.f));
	povrsina.setFillColor(sf::Color(100, 230, 90));
	povrsina.setPosition(3.f, 570.f);
	window->draw(povrsina);

	
	//leptir
	sf::Texture leptir;
	if (!leptir.loadFromFile("fly.png"))
	{
		cout << "Greska." << endl;
	}


	sf::Sprite sprite;
	sf::IntRect spriterect(0, 0, 200, 200);
	sprite.setTexture(leptir);
	sprite.setTextureRect(spriterect);
	sprite.rotate(10);
	sprite.setPosition(100.f, 100.f);

    //sunce
	sf::Texture sunce;
	if (!sunce.loadFromFile("sun.png"))
	{
		cout << "Greska." << endl;
	}


	sf::Sprite sprite1;
	sf::IntRect spriterect1(0, 0, 100, 100);
	sprite1.setTexture(sunce);
	sprite1.setTextureRect(spriterect1);
	sprite1.setPosition(650.f, 20.f);

	
	//animacija br 1 (s misem)
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		window->draw(sprite1);
		
	}

	//animacija br 2 
	srand(time(nullptr));
	int randPosition1 = rand() % (100 - 1 + 1) + 1;
	int randPosition2 = rand() % (200 - 1 + 1) + 1;
	
    sprite.setPosition(randPosition1, randPosition2);
	window->draw(sprite);
	


	
	
}





