#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw()
{
		
	//Crtanje kvadrata(poz 1,1)
	sf::CircleShape square1(80.f, 4);
	square1.rotate(45.f);
	square1.setFillColor(sf::Color(163, 205, 157));
	square1.setPosition(90, -30);
	square1.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 1,2)
	sf::CircleShape square2(80.f, 4);
	square2.rotate(45.f);
	square2.setFillColor(sf::Color(70, 197, 54));
	square2.setPosition(164, -30);
	square2.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 1,3)
	sf::CircleShape square3(80.f, 4);
	square3.rotate(45.f);
	square3.setFillColor(sf::Color(131, 204, 131));
	square3.setPosition(238, -30);
	square3.setScale(0.65, 0.65);
	
	//Crtanje kvadrata(poz 1,4)
	sf::CircleShape square4(80.f, 4);
	square4.rotate(45.f);
	square4.setFillColor(sf::Color(138, 194, 149));
	square4.setPosition(312, -30);
	square4.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 1,5)
	sf::CircleShape square5(80.f, 4);
	square5.rotate(45.f);
	square5.setFillColor(sf::Color(96, 225, 96));
	square5.setPosition(386, -30);
	square5.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 1,6)
	sf::CircleShape square6(80.f, 4);
	square6.rotate(45.f);
	square6.setFillColor(sf::Color(111, 220, 93));
	square6.setPosition(460, -30);
	square6.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 1,7)
	sf::CircleShape square7(80.f, 4);
	square7.rotate(45.f);
	square7.setFillColor(sf::Color(163, 205, 157));
	square7.setPosition(534, -30);
	square7.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 1,8)
	sf::CircleShape square8(80.f, 4);
	square8.rotate(45.f);
	square8.setFillColor(sf::Color(46, 149, 70));
	square8.setPosition(608, -30);
	square8.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,1)
	sf::CircleShape square9(80.f, 4);
	square9.rotate(45.f);
	square9.setFillColor(sf::Color(46, 149, 70));
	square9.setPosition(90, 43);
	square9.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,2)
	sf::CircleShape square10(80.f, 4);
	square10.rotate(45.f);
	square10.setFillColor(sf::Color(97, 137, 103));
	square10.setPosition(163, 43);
	square10.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,3)
	sf::CircleShape square11(80.f, 4);
	square11.rotate(45.f);
	square11.setFillColor(sf::Color(6, 147, 7));
	square11.setPosition(237, 43);
	square11.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,4)
	sf::CircleShape square12(80.f, 4);
	square12.rotate(45.f);
	square12.setFillColor(sf::Color(70, 197, 54));
	square12.setPosition(311, 43);
	square12.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,5)
	sf::CircleShape square13(80.f, 4);
	square13.rotate(45.f);
	square13.setFillColor(sf::Color(69, 127, 69));
	square13.setPosition(385, 43);
	square13.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,6)
	sf::CircleShape square14(80.f, 4);
	square14.rotate(45.f);
	square14.setFillColor(sf::Color(111, 220, 93));
	square14.setPosition(459, 43);
	square14.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,7)
	sf::CircleShape square15(80.f, 4);
	square15.rotate(45.f);
	square15.setFillColor(sf::Color(14, 114, 16));
	square15.setPosition(533, 43);
	square15.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 2,8)
	sf::CircleShape square16(80.f, 4);
	square16.rotate(45.f);
	square16.setFillColor(sf::Color(210, 210, 210));
	square16.setPosition(607, 43);
	square16.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 3,1)
	sf::CircleShape square17(80.f, 4);
	square17.rotate(45.f);
	square17.setFillColor(sf::Color(70, 197, 54));
	square17.setPosition(90, 116);
	square17.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 3,4)
	sf::CircleShape square18(80.f, 4);
	square18.rotate(45.f);
	square18.setFillColor(sf::Color(163, 205, 157));
	square18.setPosition(311, 116);
	square18.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 3,5)
	sf::CircleShape square19(80.f, 4);
	square19.rotate(45.f);
	square19.setFillColor(sf::Color(27, 215, 69));
	square19.setPosition(385, 116);
	square19.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 3,8)
	sf::CircleShape square20(80.f, 4);
	square20.rotate(45.f);
	square20.setFillColor(sf::Color(220, 220, 220));
	square20.setPosition(607, 116);
	square20.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 4,1)
	sf::CircleShape square21(80.f, 4);
	square21.rotate(45.f);
	square21.setFillColor(sf::Color(9, 186, 8));
	square21.setPosition(90, 189);
	square21.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 4,4)
	sf::CircleShape square22(80.f, 4);
	square22.rotate(45.f);
	square22.setFillColor(sf::Color(27, 163, 55));
	square22.setPosition(311, 189);
	square22.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 4,5)
	sf::CircleShape square23(80.f, 4);
	square23.rotate(45.f);
	square23.setFillColor(sf::Color(14, 114, 16));
	square23.setPosition(385, 189);
	square23.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 4,8)
	sf::CircleShape square24(80.f, 4);
	square24.rotate(45.f);
	square24.setFillColor(sf::Color(77, 229, 82));
	square24.setPosition(607, 189);
	square24.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 5,1)
	sf::CircleShape square25(80.f, 4);
	square25.rotate(45.f);
	square25.setFillColor(sf::Color(77, 229, 82));
	square25.setPosition(90, 262);
	square25.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 5,2)
	sf::CircleShape square26(80.f, 4);
	square26.rotate(45.f);
	square26.setFillColor(sf::Color(70, 197, 54));
	square26.setPosition(164, 262);
	square26.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 5,3)
	sf::CircleShape square27(80.f, 4);
	square27.rotate(45.f);
	square27.setFillColor(sf::Color(96, 225, 96));
	square27.setPosition(238, 262);
	square27.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 5,6)
	sf::CircleShape square28(80.f, 4);
	square28.rotate(45.f);
	square28.setFillColor(sf::Color(198, 211, 194));
	square28.setPosition(459, 262);
	square28.setScale(0.65, 0.65);


	//Crtanje kvadrata(poz 5,7)
	sf::CircleShape square29(80.f, 4);
	square29.rotate(45.f);
	square29.setFillColor(sf::Color(96, 225, 96));
	square29.setPosition(533, 262);
	square29.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 5,8)
	sf::CircleShape square30(80.f, 4);
	square30.rotate(45.f);
	square30.setFillColor(sf::Color(70, 197, 54));
	square30.setPosition(607, 262);
	square30.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 6,1)
	sf::CircleShape square31(80.f, 4);
	square31.rotate(45.f);
	square31.setFillColor(sf::Color(138, 194, 149));
	square31.setPosition(90, 335);
	square31.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 6,2)
	sf::CircleShape square32(80.f, 4);
	square32.rotate(45.f);
	square32.setFillColor(sf::Color(46, 149, 70));
	square32.setPosition(164, 335);
	square32.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 6,7)
	sf::CircleShape square33(80.f, 4);
	square33.rotate(45.f);
	square33.setFillColor(sf::Color(97, 137, 103));
	square33.setPosition(533, 335);
	square33.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 6,8)
	sf::CircleShape square34(80.f, 4);
	square34.rotate(45.f);
	square34.setFillColor(sf::Color(178, 205, 174));
	square34.setPosition(607, 335);
	square34.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 7,1)
	sf::CircleShape square35(80.f, 4);
	square35.rotate(45.f);
	square35.setFillColor(sf::Color(194, 226, 187));
	square35.setPosition(90, 408);
	square35.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 7,2)
	sf::CircleShape square36(80.f, 4);
	square36.rotate(45.f);
	square36.setFillColor(sf::Color(88, 159, 93));
	square36.setPosition(164, 408);
	square36.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 7,7)
	sf::CircleShape square37(80.f, 4);
	square37.rotate(45.f);
	square37.setFillColor(sf::Color(157, 239, 157));
	square37.setPosition(533, 408);
	square37.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 7,8)
	sf::CircleShape square38(80.f, 4);
	square38.rotate(45.f);
	square38.setFillColor(sf::Color(65, 131, 85));
	square38.setPosition(607, 408);
	square38.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,1)
	sf::CircleShape square39(80.f, 4);
	square39.rotate(45.f);
	square39.setFillColor(sf::Color(27, 163, 55));
	square39.setPosition(90, 481);
	square39.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,2)
	sf::CircleShape square40(80.f, 4);
	square40.rotate(45.f);
	square40.setFillColor(sf::Color(163, 205, 157));
	square40.setPosition(164, 481);
	square40.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,3)
	sf::CircleShape square41(80.f, 4);
	square41.rotate(45.f);
	square41.setFillColor(sf::Color(0, 0, 0));
	square41.setPosition(238, 481);
	square41.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,4)
	sf::CircleShape square42(80.f, 4);
	square42.rotate(45.f);
	square42.setFillColor(sf::Color(126, 224, 137));
	square42.setPosition(312, 481);
	square42.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,5)
	sf::CircleShape square43(80.f, 4);
	square43.rotate(45.f);
	square43.setFillColor(sf::Color(194, 226, 187));
	square43.setPosition(386, 481);
	square43.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,7)
	sf::CircleShape square44(80.f, 4);
	square44.rotate(45.f);
	square44.setFillColor(sf::Color(70, 197, 54));
	square44.setPosition(533, 481);
	square44.setScale(0.65, 0.65);

	//Crtanje kvadrata(poz 8,8)
	sf::CircleShape square45(80.f, 4);
	square45.rotate(45.f);
	square45.setFillColor(sf::Color(101, 205, 84));
	square45.setPosition(607, 481);
	square45.setScale(0.65, 0.65);

	//Crtanje crte1
	sf::RectangleShape shape1;
	shape1.setSize(sf::Vector2f(800, 100));
	shape1.setFillColor(sf::Color(0, 0, 0));
	shape1.setPosition(0, -20);

	//Crtanje crte2
	sf::RectangleShape shape2;
	shape2.setSize(sf::Vector2f(1800, 75));
	shape2.setFillColor(sf::Color(0, 0, 0));
	shape2.setPosition(-80, 78);

	//Crtanje crte3
	sf::RectangleShape shape3;
	shape3.setSize(sf::Vector2f(2800, 75));
	shape3.setFillColor(sf::Color(0, 0, 0));
	shape3.setPosition(-160, 151);

	//Crtanje crte4
	sf::RectangleShape shape4;
	shape4.setSize(sf::Vector2f(3000, 75));
	shape4.setFillColor(sf::Color(0, 0, 0));
	shape4.setPosition(-240, 224);

	//Crtanje crte5
	sf::RectangleShape shape5;
	shape5.setSize(sf::Vector2f(3200, 75));
	shape5.setFillColor(sf::Color(0, 0, 0));
	shape5.setPosition(-320, 297);

	//Crtanje crte6
	sf::RectangleShape shape6;
	shape6.setSize(sf::Vector2f(3400, 75));
	shape6.setFillColor(sf::Color(0, 0, 0));
	shape6.setPosition(-400, 370);

	//Crtanje crte7
	sf::RectangleShape shape7;
	shape7.setSize(sf::Vector2f(3600, 75));
	shape7.setFillColor(sf::Color(0, 0, 0));
	shape7.setPosition(-480, 443);

	//Crtanje crte8
	sf::RectangleShape shape8;
	shape8.setSize(sf::Vector2f(3800, 75));
	shape8.setFillColor(sf::Color(0, 0, 0));
	shape8.setPosition(-560, 516);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();

		//Crtanje zelenih kvadratica
		window->draw(square1);
		window->draw(square2);
		window->draw(square3);
		window->draw(square4);
		window->draw(square5);
		window->draw(square6);
		window->draw(square7);
		window->draw(square8);
		window->draw(square9);
		window->draw(square10);
		window->draw(square11);
		window->draw(square12);
		window->draw(square13);
		window->draw(square14);
		window->draw(square15);
		window->draw(square16);
		window->draw(square17);
		window->draw(square18);
		window->draw(square19);
		window->draw(square20);
		window->draw(square21);
		window->draw(square22);
		window->draw(square23);
		window->draw(square24);
		window->draw(square25);
		window->draw(square26);
		window->draw(square27);
		window->draw(square28);
		window->draw(square29);
		window->draw(square30);
		window->draw(square31);
		window->draw(square32);
		window->draw(square33);
		window->draw(square34);
		window->draw(square35);
		window->draw(square36);
		window->draw(square37);
		window->draw(square38);
		window->draw(square39);
		window->draw(square40);
		window->draw(square41);
		window->draw(square42);
		window->draw(square43);
		window->draw(square44);
		window->draw(square45);

		//ANIMACIJA

		//Pomicanje prvog reda/crte
		shape1.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape1);

		//Pomicanje drugog reda/crte
		shape2.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape2);

		//Pomicanje treceg reda/crte
		shape3.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape3);

		//Pomicanje cetvrtog reda/crte
		shape4.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape4);

		//Pomicanje petog reda/crte
		shape5.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape5);

		//Pomicanje sestog reda/crte
		shape6.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape6);

		//Pomicanje sedmog reda/crte
		shape7.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape7);

		//Pomicanje osmog reda/crte
		shape8.move(sf::Vector2f(2.5f, 0.0f));
		window->draw(shape8);

		window->display();
	}

	
}
