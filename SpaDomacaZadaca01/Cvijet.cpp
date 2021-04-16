#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow* prozor)
{
	this->prozor = prozor;
	pripremi_stabljiku();
	pripremi_trokut();
	pripremi_list();

	
}

void Cvijet::set_colourtrokut()
{
	trokut.setFillColor(sf::Color::Red);
}

void Cvijet::set_colourstabljika()
{
	stabljika.setFillColor(sf::Color::Green);
}

void Cvijet::set_colourlist()
{
	list.setFillColor(sf::Color::Green);
}

void Cvijet::set_pointnumbertrokut()
{
	trokut.setPointCount(6);
}

void Cvijet::set_pointnumberlist()
{
	list.setPointCount(5);
}

void Cvijet::set_radiustrokut()
{
	trokut.setRadius(50);
}

void Cvijet::set_radiusstabljika()
{
	stabljika.setSize(sf::Vector2f(20, 200));
}

void Cvijet::set_positiontrokut()
{
	trokut.setPosition(50, 50);
}

void Cvijet::set_positionstabljika()
{
	stabljika.setPosition(90, 150);
}

void Cvijet::set_positionlist()
{
	list.setPoint(0, sf::Vector2f(110, 300));
	list.setPoint(1, sf::Vector2f(150, 250));
	list.setPoint(2, sf::Vector2f(200, 225));
	list.setPoint(3, sf::Vector2f(150, 300));
	list.setPoint(4, sf::Vector2f(110, 320));
}

void Cvijet::set_thicknesstrokut()
{
	trokut.setOutlineThickness(2.0);
}

void Cvijet::set_thicknessstabljika()
{
	stabljika.setOutlineThickness(0.0);
}

void Cvijet::pripremi_trokut()
{
	set_colourtrokut();
	set_pointnumbertrokut();
	set_radiustrokut();
	set_positiontrokut();
	set_thicknesstrokut();

}

void Cvijet::pripremi_stabljiku()
{
	set_colourstabljika();
	set_radiusstabljika();
	set_positionstabljika();
	set_thicknessstabljika();
}

void Cvijet::pripremi_list()
{
	set_colourlist();
	set_pointnumberlist();
	set_positionlist();

}




void Cvijet::draw()
{
	(*prozor).draw(trokut);
	(*prozor).draw(stabljika);
	(*prozor).draw(list);
}
