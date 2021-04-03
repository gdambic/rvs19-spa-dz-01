#include "Cvijet.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	set_window(window);
}

void Cvijet::set_window(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::set_vrijeme(sf::Time* vrijeme)
{
	this->vrijeme = vrijeme;
}

//

void Cvijet::background()
{
	if (x == 0 && y == 0)
	{
		x = 4;
		y = 4;
	}

	int time = vrijeme->asSeconds();

	if (x_temp == 2872 || x_temp < 0)
	{
		x *= -1;
		y *= -1;
	}

	x_temp = x_temp + x;
	y_temp = y_temp + y;

	std::cout << "\tx, y =" << x_temp << "\tTime:" << vrijeme->asSeconds() << "\tGreen6: " << green6 << std::endl;

	sf::VertexArray pozadina(sf::TrianglesFan, 9);

	pozadina[0].position = sf::Vector2f(8000 - x_temp, 3000 - y_temp);
	pozadina[1].position = sf::Vector2f(12000 - x_temp, 6000 - y_temp);
	pozadina[2].position = sf::Vector2f(10000 - x_temp, 10000 - y_temp);
	pozadina[3].position = sf::Vector2f(8000 - x_temp, 13000 - y_temp);
	pozadina[4].position = sf::Vector2f(4000 - x_temp, 13000 - y_temp);
	pozadina[5].position = sf::Vector2f(-3600 - x_temp, 10000 - y_temp);
	pozadina[6].position = sf::Vector2f(-4000 - x_temp, 6000 - y_temp);
	pozadina[7].position = sf::Vector2f(-2000 - x_temp, -2000 - y_temp);
	pozadina[8].position = sf::Vector2f(9000 - x_temp, -2000 - y_temp);

	pozadina[0].color = sf::Color(0, 0, 0);
	pozadina[1].color = sf::Color(0, 255, 0);
	pozadina[2].color = sf::Color(0, 0, 255);
	pozadina[3].color = sf::Color(121, 121, 121);
	pozadina[4].color = sf::Color(225, 0, 0);
	pozadina[5].color = sf::Color(0, 0, 225);
	pozadina[6].color = sf::Color(0, 0, 255);
	pozadina[7].color = sf::Color(220, 100, 50);
	pozadina[8].color = sf::Color(121, 0, 0);
	window->draw(pozadina);
}

//

void Cvijet::bojelatica1()
{
	if (temp_boja1 == 0)
	{
		temp_boja1 = 1;
	}
	if (temp_boja2 == 0)
	{
		temp_boja2 = 1;
	}

	if (green1 < 1 || green1 > 254)
	{
		temp_boja1 *= -1;
	}
	if (green2 == 0 || green2 == 255)
	{
		temp_boja2 *= -1;
	}

	green1 -= temp_boja1;
	green2 -= temp_boja2;
}

void Cvijet::bojelatica2()
{
	if (temp_boja3 == 0)
	{
		temp_boja3 = 1;
	}
	if (temp_boja4 == 0)
	{
		temp_boja4 = 1;
	}

	if (green3 < 1 || green3 > 254)
	{
		temp_boja3 *= -1;
	}
	if (green4 == 0 || green4 == 255)
	{
		temp_boja4 *= -1;
	}

	green3 -= temp_boja3;
	green4 -= temp_boja4;
}

void Cvijet::bojelatica3()
{
	if (temp_boja5 == 0)
	{
		temp_boja5 = 1;
	}
	if (temp_boja6 == 0)
	{
		temp_boja6 = 1;
	}

	if (green5 < 1 || green5 > 254)
	{
		temp_boja5 *= -1;
	}
	if (green6 == 0 || green6 == 255)
	{
		temp_boja6 *= -1;
	}

	green5 -= temp_boja5;
	green6 -= temp_boja6;
}

/// // // //////////////

void Cvijet::krug1Draw()
{
	float upper = 85.f;
	float lower = 80.f;

	krug_1.setPosition(320, 220);

	/////////////////////////////////////////////////////

	krug_1.setRadius(temp_radijus01);
	krug_1.setFillColor(sf::Color(255, 150, 0));
	window->draw(krug_1);

	if (temp_radijus01 <= lower || temp_radijus01 >= upper)
	{
		(pps01) *= -1.f;
	}

	temp_radijus01 += pps01 * vrijeme->asSeconds();

	////////////////////////////////////////////////////////
}

void Cvijet::krug2Draw()
{
	float upper = 87.f;
	float lower = 82.f;

	krug_2.setPosition(325, 225);

	/////////////////////////////////////////////////////

	krug_1.setRadius(temp_radijus02);
	krug_1.setFillColor(sf::Color(255, 255, 0));
	window->draw(krug_1);

	if (temp_radijus02 <= lower || temp_radijus02 >= upper)
	{
		(pps02) *= -1.f;
	}

	temp_radijus02 += pps02 * vrijeme->asSeconds();

	////////////////////////////////////////////////////////
}

void Cvijet::krug3Draw()
{
	temp_radijus03 = 120.f;
	float upper = 350.f;
	float lower = 100.f;

	krug_3.setPosition(280, 180);

	/////////////////////////////////////////////////////

	krug_3.setRadius(temp_radijus03);
	krug_3.setFillColor(sf::Color(255, 34, 129));
	window->draw(krug_3);

	if (temp_radijus03 <= lower || temp_radijus03 >= upper)
	{
		(pps01) *= -1.f;
	}

	temp_radijus03 += pps01 * vrijeme->asSeconds();

	////////////////////////////////////////////////////////
}

///////////////////////////////////////////
void Cvijet::Nkut1Draw()
{
	Nkut01.setPosition(400, 300);
	Nkut01.setFillColor(sf::Color(red1, green1, blue1));
	Nkut01.rotate(1.1f);

	Nkut_latice_animacija(Nkut01);
}

void Cvijet::Nkut2Draw()
{
	Nkut02.setPosition(400, 300);
	Nkut02.setFillColor(sf::Color(red2, green2, blue2));
	Nkut02.rotate(1.2f);

	Nkut_latice_animacija(Nkut02);
}

void Cvijet::Nkut3Draw()
{
	Nkut03.setPosition(400, 300);
	Nkut03.setFillColor(sf::Color(red1, green1, blue1));
	Nkut03.rotate(1.3f);

	Nkut_latice_animacija(Nkut03);
}

void Cvijet::Nkut4Draw()
{
	Nkut04.setPosition(400, 300);
	Nkut04.setFillColor(sf::Color(red2, green2, blue2));
	Nkut04.rotate(1.4f);

	Nkut_latice_animacija(Nkut04);
}

void Cvijet::Nkut5Draw()
{
	Nkut05.setPosition(400, 300);
	Nkut05.setFillColor(sf::Color(red1, green1, blue1));
	Nkut05.rotate(1.5f);

	Nkut_latice_animacija(Nkut05);
}

void Cvijet::Nkut6Draw()
{
	Nkut06.setPosition(400, 300);
	Nkut06.setFillColor(sf::Color(red2, green2, blue2));
	Nkut06.rotate(1.6f);

	Nkut_latice_animacija(Nkut06);
}

void Cvijet::Nkut7Draw()
{
	Nkut07.setPosition(400, 300);
	Nkut07.setFillColor(sf::Color(red1, green1, blue1));
	Nkut07.rotate(1.7f);

	Nkut_latice_animacija(Nkut07);
}

void Cvijet::Nkut8Draw()
{
	Nkut08.setPosition(400, 300);
	Nkut08.setFillColor(sf::Color(red2, green2, blue2));
	Nkut08.rotate(1.8f);

	Nkut_latice_animacija(Nkut08);
}

void Cvijet::Nkut9Draw()
{
	Nkut09.setPosition(400, 300);
	Nkut09.setFillColor(sf::Color(red1, green1, blue1));
	Nkut09.rotate(1.9f);

	Nkut_latice_animacija(Nkut09);
}

void Cvijet::Nkut10Draw()
{
	Nkut10.setPosition(400, 300);
	Nkut10.setFillColor(sf::Color(red2, green2, blue2));
	Nkut10.rotate(2.f);

	Nkut_latice_animacija(Nkut10);
}

void Cvijet::Nkut11Draw()
{
	Nkut11.setPosition(400, 300);
	Nkut11.setFillColor(sf::Color(red1, green1, blue1));
	Nkut11.rotate(2.1f);

	Nkut_latice_animacija(Nkut11);
}

void Cvijet::Nkut12Draw()
{
	Nkut12.setPosition(400, 300);
	Nkut12.setFillColor(sf::Color(red2, green2, blue2));
	Nkut12.rotate(2.2f);

	Nkut_latice_animacija(Nkut12);
}

void Cvijet::Nkut13Draw()
{
	Nkut13.setPosition(400, 300);
	Nkut13.setFillColor(sf::Color(red1, green1, blue1));
	Nkut13.rotate(2.3f);

	Nkut_latice_animacija(Nkut13);
}

void Cvijet::Nkut14Draw()
{
	Nkut14.setPosition(400, 300);
	Nkut14.setFillColor(sf::Color(red2, green2, blue2));
	Nkut14.rotate(2.4f);

	Nkut_latice_animacija(Nkut14);
}

void Cvijet::Nkut15Draw()
{
	Nkut15.setPosition(400, 300);
	Nkut15.setFillColor(sf::Color(red1, green1, blue1));
	Nkut15.rotate(2.5f);

	Nkut_latice_animacija(Nkut15);
}

void Cvijet::Nkut16Draw()
{
	Nkut16.setPosition(400, 300);
	Nkut16.setFillColor(sf::Color(red2, green2, blue2));
	Nkut16.rotate(2.6f);

	Nkut_latice_animacija(Nkut16);
}

/// ///////////////////////////

void Cvijet::Nkut1DrawD()
{
	Nkut01D.setPosition(400, 300);
	Nkut01D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut01D.rotate(-1.19f);

	NkutD_latice_animacija(Nkut01D);
}

void Cvijet::Nkut2DrawD()
{
	Nkut02D.setPosition(400, 300);
	Nkut02D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut02D.rotate(-1.29f);

	NkutD_latice_animacija(Nkut02D);
}

void Cvijet::Nkut3DrawD()
{
	Nkut03D.setPosition(400, 300);
	Nkut03D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut03D.rotate(-1.39f);

	NkutD_latice_animacija(Nkut03D);
}

void Cvijet::Nkut4DrawD()
{
	Nkut04D.setPosition(400, 300);
	Nkut04D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut04D.rotate(-1.49f);

	NkutD_latice_animacija(Nkut04D);
}

void Cvijet::Nkut5DrawD()
{
	Nkut05D.setPosition(400, 300);
	Nkut05D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut05D.rotate(-1.59f);

	NkutD_latice_animacija(Nkut05D);
}

void Cvijet::Nkut6DrawD()
{
	Nkut06D.setPosition(400, 300);
	Nkut06D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut06D.rotate(-1.69f);

	NkutD_latice_animacija(Nkut06D);
}

void Cvijet::Nkut7DrawD()
{
	Nkut07D.setPosition(400, 300);
	Nkut07D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut07D.rotate(-1.79f);

	NkutD_latice_animacija(Nkut07D);
}

void Cvijet::Nkut8DrawD()
{
	Nkut08D.setPosition(400, 300);
	Nkut08D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut08D.rotate(-1.89f);

	NkutD_latice_animacija(Nkut08D);
}

void Cvijet::Nkut9DrawD()
{
	Nkut09D.setPosition(400, 300);
	Nkut09D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut09D.rotate(-1.99f);

	NkutD_latice_animacija(Nkut09D);
}

void Cvijet::Nkut10DrawD()
{
	Nkut10D.setPosition(400, 300);
	Nkut10D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut10D.rotate(-2.09f);

	NkutD_latice_animacija(Nkut10D);
}

void Cvijet::Nkut11DrawD()
{
	Nkut11D.setPosition(400, 300);
	Nkut11D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut11D.rotate(-2.19f);

	NkutD_latice_animacija(Nkut11D);
}

void Cvijet::Nkut12DrawD()
{
	Nkut12D.setPosition(400, 300);
	Nkut12D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut12D.rotate(-2.29f);

	NkutD_latice_animacija(Nkut12D);
}

void Cvijet::Nkut13DrawD()
{
	Nkut13D.setPosition(400, 300);
	Nkut13D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut13D.rotate(-2.39f);

	NkutD_latice_animacija(Nkut13D);
}

void Cvijet::Nkut14DrawD()
{
	Nkut14D.setPosition(400, 300);
	Nkut14D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut14D.rotate(-2.49f);

	NkutD_latice_animacija(Nkut14D);
}

void Cvijet::Nkut15DrawD()
{
	Nkut15D.setPosition(400, 300);
	Nkut15D.setFillColor(sf::Color(red3, green3, blue3));
	Nkut15D.rotate(-2.59f);

	NkutD_latice_animacija(Nkut16D);
}

void Cvijet::Nkut16DrawD()
{
	Nkut16D.setPosition(400, 300);
	Nkut16D.setFillColor(sf::Color(red4, green4, blue4));
	Nkut16D.rotate(-2.69f);

	NkutD_latice_animacija(Nkut16D);
}

//////////////////////////////

//////////////////////////////

void Cvijet::Nkut1DrawT()
{
	Nkut01T.setPosition(400, 300);
	Nkut01T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut01T.rotate(1.3f);

	NkutT_latice_animacija(Nkut01T);
}

void Cvijet::Nkut2DrawT()
{
	Nkut02T.setPosition(400, 300);
	Nkut02T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut02T.rotate(1.4f);

	NkutT_latice_animacija(Nkut02T);
}

void Cvijet::Nkut3DrawT()
{
	Nkut03T.setPosition(400, 300);
	Nkut03T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut03T.rotate(1.6f);

	NkutT_latice_animacija(Nkut03T);
}

void Cvijet::Nkut4DrawT()
{
	Nkut04T.setPosition(400, 300);
	Nkut04T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut04T.rotate(1.8f);

	NkutT_latice_animacija(Nkut04T);
}

void Cvijet::Nkut5DrawT()
{
	Nkut05T.setPosition(400, 300);
	Nkut05T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut05T.rotate(2.0f);

	NkutT_latice_animacija(Nkut05T);
}

void Cvijet::Nkut6DrawT()
{
	Nkut06T.setPosition(400, 300);
	Nkut06T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut06T.rotate(2.2f);

	NkutT_latice_animacija(Nkut06T);
}

void Cvijet::Nkut7DrawT()
{
	Nkut07T.setPosition(400, 300);
	Nkut07T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut07T.rotate(2.4f);

	NkutT_latice_animacija(Nkut07T);
}

void Cvijet::Nkut8DrawT()
{
	Nkut08T.setPosition(400, 300);
	Nkut08T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut08T.rotate(2.6f);

	NkutT_latice_animacija(Nkut08T);
}

void Cvijet::Nkut9DrawT()
{
	Nkut09T.setPosition(400, 300);
	Nkut09T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut09T.rotate(2.8f);

	NkutT_latice_animacija(Nkut09T);
}

void Cvijet::Nkut10DrawT()
{
	Nkut10T.setPosition(400, 300);
	Nkut10T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut10T.rotate(3.0f);

	NkutT_latice_animacija(Nkut10T);
}

void Cvijet::Nkut11DrawT()
{
	Nkut11T.setPosition(400, 300);
	Nkut11T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut11T.rotate(3.2f);

	NkutT_latice_animacija(Nkut11T);
}

void Cvijet::Nkut12DrawT()
{
	Nkut12T.setPosition(400, 300);
	Nkut12T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut12T.rotate(3.4f);

	NkutT_latice_animacija(Nkut12T);
}

void Cvijet::Nkut13DrawT()
{
	Nkut13T.setPosition(400, 300);
	Nkut13T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut13T.rotate(3.6f);

	NkutT_latice_animacija(Nkut13T);
}

void Cvijet::Nkut14DrawT()
{
	Nkut14T.setPosition(400, 300);
	Nkut14T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut14T.rotate(3.8f);

	NkutT_latice_animacija(Nkut14T);
}

void Cvijet::Nkut15DrawT()
{
	Nkut15T.setPosition(400, 300);
	Nkut15T.setFillColor(sf::Color(red5, green5, blue5));
	Nkut15T.rotate(4.0f);

	NkutT_latice_animacija(Nkut16T);
}

void Cvijet::Nkut16DrawT()
{
	Nkut16T.setPosition(400, 300);
	Nkut16T.setFillColor(sf::Color(red6, green6, blue6));
	Nkut16T.rotate(4.2f);

	NkutT_latice_animacija(Nkut16T);
}

//////////////////////////////

void Cvijet::Nkut_latice_animacija(sf::CircleShape element)
{
	element.setPointCount(3);
	element.setRadius(80);
	window->draw(element);
}

void Cvijet::NkutD_latice_animacija(sf::CircleShape element)
{
	element.setPointCount(5);
	element.setRadius(100);
	window->draw(element);
}

void Cvijet::NkutT_latice_animacija(sf::CircleShape element)
{
	element.setPointCount(6);
	element.setRadius(130);
	window->draw(element);
}

//crtanje
void Cvijet::draw(sf::Time* vrijeme)
{
	set_vrijeme(vrijeme);

	background();

	bojelatica1();
	bojelatica2();
	bojelatica3();

	//Pozadinski krug cvijeta - iza latiica
	krug3Draw();

	//Treci red latica//
	Nkut1DrawT();
	Nkut2DrawT();
	Nkut3DrawT();
	Nkut4DrawT();
	Nkut5DrawT();
	Nkut6DrawT();
	Nkut7DrawT();
	Nkut8DrawT();
	Nkut9DrawT();
	Nkut10DrawT();
	Nkut11DrawT();
	Nkut12DrawT();
	Nkut13DrawT();
	Nkut14DrawT();
	Nkut15DrawT();
	Nkut16DrawT();

	//Drugi red latica//
	Nkut1DrawD();
	Nkut2DrawD();
	Nkut3DrawD();
	Nkut4DrawD();
	Nkut5DrawD();
	Nkut6DrawD();
	Nkut7DrawD();
	Nkut8DrawD();
	Nkut9DrawD();
	Nkut10DrawD();
	Nkut11DrawD();
	Nkut12DrawD();
	Nkut13DrawD();
	Nkut14DrawD();
	Nkut15DrawD();
	Nkut16DrawD();

	// Prvi red latica//
	Nkut1Draw();
	Nkut2Draw();
	Nkut3Draw();
	Nkut4Draw();
	Nkut5Draw();
	Nkut6Draw();
	Nkut7Draw();
	Nkut8Draw();
	Nkut9Draw();
	Nkut10Draw();
	Nkut11Draw();
	Nkut12Draw();
	Nkut13Draw();
	Nkut14Draw();
	Nkut15Draw();
	Nkut16Draw();

	// Centar cvijeta - tucak il kaj vec
	krug1Draw();
	krug2Draw();
}