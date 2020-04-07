#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* Window)
{
	//Kontruktor
	this->Window = Window;
}

sf::CircleShape Cvijet::set_Sunce()
{
	//Sunce
	Sunce.setRadius(get_radius());
	Sunce.setFillColor(sf::Color(250, 250, 0));
	Sunce.setPosition(50, 50);
	return Sunce;
}



sf::CircleShape Cvijet::set_UnutarnjiCvijet()
{
	//Unutarnji Cvijet
	UnutarnjiCvijet.setRadius(50);
	UnutarnjiCvijet.setPosition(160, 230);
	UnutarnjiCvijet.setFillColor(sf::Color(160, 100, 20));
	return UnutarnjiCvijet;
}

sf::CircleShape Cvijet::set_VanjskiCvijet()
{
	//Vanjski Cvijet
	VanjskiCvijet.setRadius(80);
	VanjskiCvijet.setPosition(130,200);
	VanjskiCvijet.setFillColor(sf::Color(200, 150, 0));
	return VanjskiCvijet;
}

sf::RectangleShape Cvijet::set_Stabljika()
{
	//Stabljika
	sf::Vector2f velicina(30, 160);
	Stabljika.setSize(velicina);
	Stabljika.setPosition(195, 320);
	Stabljika.setFillColor(sf::Color(100, 250, 10));
	return Stabljika;
}

sf::ConvexShape Cvijet::set_List()
{
	//Ljetno Lisce
	List.setPointCount(3);
	List.setPosition(200, 400);
	List.setFillColor(sf::Color(0, 250, 0));
	List.setPoint(0,sf::Vector2f(100,50));
	List.setPoint(1,sf::Vector2f(20,-30));
	List.setPoint(2,sf::Vector2f(20,20));
	//List.setPoint(3,sf::Vector2f(225,375));

	return List;
}

sf::ConvexShape Cvijet::set_DrugiList()
{
	//Jesensko Lisce
	List.setPointCount(3);
	List.setPosition(215, 400);
	List.setFillColor(sf::Color(80, 0, 0));
	List.setPoint(0, sf::Vector2f(-100, -50));
	List.setPoint(1, sf::Vector2f(-20, 30));
	List.setPoint(2, sf::Vector2f(-20, -20));
	return List;
}

float Cvijet::get_radius()
{
	//Radijus Sunca
	if (vrijeme.getElapsedTime().asSeconds() < 2)
	{
		konstanta += 0.4;
	}
	else if(vrijeme.getElapsedTime().asSeconds() < 4)
	{
		konstanta -= 0.4f;
	}
	else
	{
		vrijeme.restart();
	}

	return konstanta;
}

void Cvijet::draw()
{
	//Crtanje objekata
	Window->draw(set_List());
	Window->draw(set_Stabljika());
	Window->draw(set_VanjskiCvijet());
	Window->draw(set_UnutarnjiCvijet());
	Window->draw(set_Sunce());
	Window->draw(set_DrugiList());

}
