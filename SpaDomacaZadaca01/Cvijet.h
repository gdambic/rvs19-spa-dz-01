#pragma once
#include <SFML/Graphics.hpp>

//using namespace sf;

class Cvijet
{
public:

	Cvijet(sf::RenderWindow* window);

	void set_window(sf::RenderWindow* window);
	void set_vrijeme(sf::Time* vrijeme);

	void background();

	void bojelatica1();
	void bojelatica2();
	void bojelatica3();

	void krug1Draw();
	void krug2Draw();
	void krug3Draw();

	///  Prvi krug latica ///
	void Nkut1Draw();
	void Nkut2Draw();
	void Nkut3Draw();
	void Nkut4Draw();
	void Nkut5Draw();
	void Nkut6Draw();
	void Nkut7Draw();
	void Nkut8Draw();
	void Nkut9Draw();
	void Nkut10Draw();
	void Nkut11Draw();
	void Nkut12Draw();
	void Nkut13Draw();
	void Nkut14Draw();
	void Nkut15Draw();
	void Nkut16Draw();
	////////////////////////

	// Drugi krug latica //
	void Nkut1DrawD();
	void Nkut2DrawD();
	void Nkut3DrawD();
	void Nkut4DrawD();
	void Nkut5DrawD();
	void Nkut6DrawD();
	void Nkut7DrawD();
	void Nkut8DrawD();
	void Nkut9DrawD();
	void Nkut10DrawD();
	void Nkut11DrawD();
	void Nkut12DrawD();
	void Nkut13DrawD();
	void Nkut14DrawD();
	void Nkut15DrawD();
	void Nkut16DrawD();

	/////////////////////////

	// Treci krug latica //
	void Nkut1DrawT();
	void Nkut2DrawT();
	void Nkut3DrawT();
	void Nkut4DrawT();
	void Nkut5DrawT();
	void Nkut6DrawT();
	void Nkut7DrawT();
	void Nkut8DrawT();
	void Nkut9DrawT();
	void Nkut10DrawT();
	void Nkut11DrawT();
	void Nkut12DrawT();
	void Nkut13DrawT();
	void Nkut14DrawT();
	void Nkut15DrawT();
	void Nkut16DrawT();

	/////////////////////////

	void Nkut_latice_animacija(sf::CircleShape element);
	void NkutD_latice_animacija(sf::CircleShape element);
	void NkutT_latice_animacija(sf::CircleShape element);

	void draw(sf::Time* vrijeme);

private:
	sf::CircleShape krug_1;
	sf::CircleShape krug_2;
	sf::CircleShape krug_3;
	sf::CircleShape krug_4;
	sf::CircleShape krug_5;
	sf::CircleShape krug_6;

	sf::CircleShape Nkut01;
	sf::CircleShape Nkut02;
	sf::CircleShape Nkut03;
	sf::CircleShape Nkut04;
	sf::CircleShape Nkut05;
	sf::CircleShape Nkut06;
	sf::CircleShape Nkut07;
	sf::CircleShape Nkut08;
	sf::CircleShape Nkut09;
	sf::CircleShape Nkut10;
	sf::CircleShape Nkut11;
	sf::CircleShape Nkut12;
	sf::CircleShape Nkut13;
	sf::CircleShape Nkut14;
	sf::CircleShape Nkut15;
	sf::CircleShape Nkut16;

	sf::CircleShape Nkut01D;
	sf::CircleShape Nkut02D;
	sf::CircleShape Nkut03D;
	sf::CircleShape Nkut04D;
	sf::CircleShape Nkut05D;
	sf::CircleShape Nkut06D;
	sf::CircleShape Nkut07D;
	sf::CircleShape Nkut08D;
	sf::CircleShape Nkut09D;
	sf::CircleShape Nkut10D;
	sf::CircleShape Nkut11D;
	sf::CircleShape Nkut12D;
	sf::CircleShape Nkut13D;
	sf::CircleShape Nkut14D;
	sf::CircleShape Nkut15D;
	sf::CircleShape Nkut16D;

	sf::CircleShape Nkut01T;
	sf::CircleShape Nkut02T;
	sf::CircleShape Nkut03T;
	sf::CircleShape Nkut04T;
	sf::CircleShape Nkut05T;
	sf::CircleShape Nkut06T;
	sf::CircleShape Nkut07T;
	sf::CircleShape Nkut08T;
	sf::CircleShape Nkut09T;
	sf::CircleShape Nkut10T;
	sf::CircleShape Nkut11T;
	sf::CircleShape Nkut12T;
	sf::CircleShape Nkut13T;
	sf::CircleShape Nkut14T;
	sf::CircleShape Nkut15T;
	sf::CircleShape Nkut16T;

	sf::RenderWindow* window;
	sf::Time* vrijeme;

	float modifier = 1;

	//Krugovi u centru - tucak

	float temp_radijus01 = 80.f;
	float temp_radijus02 = 80.f;

	float pps01 = 0.001f;
	float pps02 = 0.001f;

	///Krug u pozadini - iza latica
	float temp_radijus03;

	//Za animaciju Background()
	float x_temp, y_temp, x = 0, y = 0;

	//Latice prvi krug BOJE//
	int red1 = 117;
	int green1 = 213;
	int blue1 = 253;

	int red2 = 183;
	int green2 = 108;
	int blue2 = 253;

	int temp_boja1 = 0;
	int temp_boja2 = 0;

	// // // // // //

	//Latice drugi krug BOJE//
	int red3 = 1;
	int green3 = 31;
	int blue3 = 253;

	int red4 = 6;
	int green4 = 214;
	int blue4 = 160;

	int temp_boja3 = 0;
	int temp_boja4 = 0;

	// // // // // //
	//
	//Latice treci krug BOJE//
	int red5 = 255;
	int green5 = 34;
	int blue5 = 129;

	int red6 = 130;
	int green6 = 244;
	int blue6 = 202;

	int temp_boja5 = 0;
	int temp_boja6 = 0;

	// // // // // //
};
