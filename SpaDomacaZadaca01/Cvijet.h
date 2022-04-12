#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Cvijet
{
public:
	Cvijet(RenderWindow& window);
	void draw(RenderWindow& window);
	void anim(sf::Clock& clock);
private:
	CircleShape glava, lijevo_oko, desno_oko, lijeva_zjenica, desna_zjenica, lijevi_odsjaj, desni_odsjaj;
	RectangleShape nos, usta, linije_zubiju[6], tijelo;
	ConvexShape lijevi_list, desni_list;
};

