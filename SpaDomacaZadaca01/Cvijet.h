#pragma once
#include <SFML/Graphics.hpp>
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
#include <fstream>
using namespace sf;
using namespace std;
class Cvijet
{
private:

	RenderWindow* PWindow = nullptr;
	const Texture* TeksturaZaTravu=nullptr;
	const Texture* TeksturaZaNebo = nullptr;
	const Texture* TeksturaZaStabiljku = nullptr;
	const Texture* TeksturaZaCvijet=nullptr;
	
	
	





public:
	Cvijet(sf::RenderWindow *window);
	void TekstruaSetter(Texture* a);
	void TeksturaSetterNebo(Texture* b);
	void TeksturaSetterStabiljka(Texture* c);
	RectangleShape Pozadina();
	CircleShape Krug();
	CircleShape Krug2();
	RectangleShape Stabiljka();
	RectangleShape Trava();
	CircleShape Tucak();
	void SetterZaSliku(Texture* d);
	void draw();
	



};

