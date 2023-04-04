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
#include <SFML/Audio.hpp>
#include "Cvijet.h"
#include <fstream>
using namespace std;
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	Texture texture;
	texture.loadFromFile("Trava.jpg");
	texture.setSmooth(true);
	cvijet.TekstruaSetter(&texture);
	Texture Nebo;
	Nebo.loadFromFile("Nebo.jpg");
	Nebo.setSmooth(true);
	cvijet.TeksturaSetterNebo(&Nebo);
	Texture Stabiljka;
	Stabiljka.loadFromFile("Plant.jpg");
	Stabiljka.setSmooth(true);
	cvijet.TeksturaSetterStabiljka(&Stabiljka);
	Texture Suncokret;
	Suncokret.loadFromFile("Suncokret.png");
	cvijet.SetterZaSliku(&Suncokret);

	


	
		while (window.isOpen())
		{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		cvijet.draw();
		window.display();
		}

	return 0;
}