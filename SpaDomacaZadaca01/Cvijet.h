#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cvijet
{
private: 
	RenderWindow* window = nullptr;
	
public:
 Cvijet(sf::RenderWindow* window);
 RectangleShape Nebo();
 CircleShape Sunce();
 CircleShape Sunce2();
 RectangleShape Trava();
 RectangleShape Cvijetic();
 CircleShape Cvijetic2();
 CircleShape Latica();
 CircleShape Latica1();
 CircleShape Latica2();
 CircleShape Latica3();
 CircleShape Latica4();
 CircleShape Latica5();
 CircleShape Latica6();
 RectangleShape Kuca();
 RectangleShape Vrata();
 CircleShape Rucka();
 RectangleShape Krov();
 RectangleShape Krov1();
 RectangleShape Krov2();
 RectangleShape Krov3();
 RectangleShape Krov4();
 RectangleShape Krov5();
 RectangleShape Krov6();
 RectangleShape Krov7();
 RectangleShape Krov8();
 RectangleShape Krov9();

 void draw();
};

