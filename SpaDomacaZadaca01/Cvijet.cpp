#include<iostream>
#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}



void Cvijet::draw()
{

	sf::Time elapsed1 = frameClock.getElapsedTime();
	pomakSunce = ((int)elapsed1.asSeconds() % 50+1)*4;


	sf::Font font;
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		std::cout << "ERROR: Font nije ucitan!" << std::endl;

		window->close();
	}

	sf::Text text;
	text.setPosition(490, 100);
	text.setFont(font); 
	text.setString("Komande:\n\t<- pomak cvijeta u lijevo\n\t-> pomak cvijeta u desno\n\tESC kraj programa");
	text.setCharacterSize(24);


	//----------Elementi------------
	sf::CircleShape sunce(50);
	sunce.setFillColor(sf::Color(255, 241, 0));
	sunce.setPosition(50 + pomakSunce, 50);


	sf::CircleShape glavaCvijeta(45);
	glavaCvijeta.setPosition(180 + pomakCvijet, 300);
	glavaCvijeta.setFillColor(sf::Color(63, 34, 22));
	glavaCvijeta.setOutlineThickness(15);
	glavaCvijeta.setOutlineColor(sf::Color(226, 152, 2));

	sf::RectangleShape peteljka(sf::Vector2f(5, 150));
	peteljka.setPosition(180 + 45 + pomakCvijet, 360 + 45);
	peteljka.setFillColor(sf::Color(44, 73, 6));

	sf::ConvexShape list;
	list.setPosition(126 + pomakCvijet, 400);
	list.setFillColor(sf::Color(44, 73, 6));
	list.setPointCount(5);
	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(80.f, -30.f));
	list.setPoint(2, sf::Vector2f(140.f, 0.f));
	list.setPoint(3, sf::Vector2f(80.f, 30.f));
	list.setRotation(45);

	sf::ConvexShape list2;
	list2.setPosition(340 + pomakCvijet, 425);
	list2.setFillColor(sf::Color(44, 73, 6));
	list2.setPointCount(5);
	list2.setPoint(0, sf::Vector2f(0.f, 0.f));
	list2.setPoint(1, sf::Vector2f(80.f, -30.f));
	list2.setPoint(2, sf::Vector2f(140.f, 0.f));
	list2.setPoint(3, sf::Vector2f(80.f, 30.f));
	list2.setRotation(142);
	//------------------------------

	window->draw(glavaCvijeta);
	window->draw(peteljka);
	window->draw(sunce);
	window->draw(list);
	window->draw(list2);
	window->draw(text);
}

void Cvijet::desno()
{
	kordinate();
	if (pomakCvijet <= 600)
		pomakCvijet++;
	else
		pomakCvijet = -250;
}

void Cvijet::lijevo()
{
	kordinate();
	if (pomakCvijet >= -250)
		pomakCvijet--;
	else
		pomakCvijet = 600;
}

void Cvijet::kordinate()
{
	std::cout << pomakCvijet<<"  ";
}
