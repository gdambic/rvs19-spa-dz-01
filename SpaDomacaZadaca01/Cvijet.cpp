#include "Cvijet.h"
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/NonCopyable.hpp>
using namespace sf;




Cvijet::Cvijet(sf::RenderWindow *window)
{
	PWindow = window;
	
}

void Cvijet::TekstruaSetter(Texture* a)
{
	TeksturaZaTravu = a;
	
}

void Cvijet::TeksturaSetterNebo(Texture* b)
{
	TeksturaZaNebo = b;
}

void Cvijet::TeksturaSetterStabiljka(Texture* c)
{
	TeksturaZaStabiljku = c;
}

RectangleShape Cvijet::Pozadina()
{
	return RectangleShape(Vector2f(2560.f,1600.f));
}

CircleShape Cvijet::Krug()
{   
	return CircleShape(150.f);
}
CircleShape Cvijet::Krug2()
{
	return CircleShape(300.f);
}

RectangleShape Cvijet::Stabiljka()
{
	return RectangleShape(Vector2f(50.f, 450.f));
}

RectangleShape Cvijet::Trava()
{
	return RectangleShape(Vector2f(2560.f, 100.f));
}

CircleShape Cvijet::Tucak()
{
	return CircleShape(200.f);
}

void Cvijet::SetterZaSliku(Texture* d)
{
	TeksturaZaCvijet = d;
}

void Cvijet::draw(){
	Clock clock;

	CircleShape Tuckic = Tucak();
	RectangleShape Stabiljcica = Stabiljka();
	RectangleShape Pozadinica = Pozadina();
	RectangleShape Travica = Trava();
	CircleShape Kruzic= Krug();
	CircleShape Kruzic2 = Krug2();
	Pozadinica.setTexture(TeksturaZaNebo);
	Kruzic.setFillColor(Color(252, 198, 3));
	Kruzic.move(150, 150);
	Kruzic2.setFillColor(Color(252, 198, 3, 200));
	Travica.setTexture(TeksturaZaTravu);
	Travica.move(0, 1000);
	Stabiljcica.setTexture(TeksturaZaStabiljku);
	Stabiljcica.move(1080, 600);
	Tuckic.setTexture(TeksturaZaCvijet);
	Tuckic.move(900, 300);



	PWindow->draw(Pozadinica);
	PWindow->draw(Kruzic);
	PWindow->draw(Kruzic2);
	PWindow->draw(Travica);
	PWindow->draw(Stabiljcica);
	PWindow->draw(Tuckic);
}



