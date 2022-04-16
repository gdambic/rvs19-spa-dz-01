#include "Zivotinja.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Zivotinja::Zivotinja(sf::RenderWindow* window)
{
    this->window = window;
}

void Zivotinja::draw()
{
    //glava
    g1.lice.setRadius(20.f);
    g1.lice.setFillColor(sf::Color::Color(255, 255, 0));
    g1.lice.setOrigin(15, 15);
    g1.lice.setPosition(300, 180);

    int num = gen_randNum();

    if (num % 2 != 0) {

        sf::CircleShape nos_temp(15, 3);
        g1.nos = nos_temp;
        g1.nos.setPosition(280, 180);
        g1.nos.setFillColor(sf::Color::Color(255, 165, 0));

        sf::CircleShape oko1_temp(5, 8);
        g1.oko1 = oko1_temp;
        g1.oko1.setPosition(280, 180);
        g1.oko1.setFillColor(sf::Color::Color(0, 0, 0));

        sf::CircleShape oko2_temp(5, 8);
        g1.oko2 = oko2_temp;
        g1.oko2.setPosition(302, 180);
        g1.oko2.setFillColor(sf::Color::Color(0, 0, 0));

    }

    else if (num % 2 == 0)
    {
        sf::CircleShape nos_temp(15, 3);
        //nos_temp.rotate(-100);
        g1.nos = nos_temp;
        g1.nos.setPosition(295, 175.5);
        g1.nos.setFillColor(sf::Color::Color(255, 165, 0));

        sf::CircleShape oko1_temp(5, 8);
        g1.oko1 = oko1_temp;
        g1.oko1.setPosition(293, 180);
        g1.oko1.setFillColor(sf::Color::Color(0, 0, 0));

        sf::CircleShape oko2_temp(5, 8);
        g1.oko2 = oko2_temp;
        g1.oko2.setPosition(315, 180);
        g1.oko2.setFillColor(sf::Color::Color(0, 0, 0));
    }

    //Trbuh
    a1.trbuh.setRadius(20.f);
    a1.trbuh.setFillColor(sf::Color::Color(255, 255, 0));
    a1.trbuh.setOrigin(15, 15);
    a1.trbuh.setPosition(305, 215);

    //Noge
    sf::RectangleShape noga1_temp(sf::Vector2f(20, 5));
    noga1_temp.rotate(-90);
    n1.noga1 = noga1_temp;
    n1.noga1.setFillColor(sf::Color::Color(255, 165, 0));
    n1.noga1.setPosition(300, 255);

    sf::RectangleShape noga2_temp(sf::Vector2f(20, 5));
    noga2_temp.rotate(-90);
    n1.noga2 = noga2_temp;
    n1.noga2.setFillColor(sf::Color::Color(255, 165, 0));
    n1.noga2.setPosition(315, 255);

    sf::RectangleShape kandza1_temp(sf::Vector2f(15, 5));
    kandza1_temp.rotate(180);
    n1.kandza1 = kandza1_temp;
    n1.kandza1.setFillColor(sf::Color::Color(255, 165, 0));
    n1.kandza1.setPosition(308.5, 260);

    sf::RectangleShape kandza2_temp(sf::Vector2f(15, 5));
    kandza2_temp.rotate(180);
    n1.kandza2 = kandza2_temp;
    n1.kandza2.setFillColor(sf::Color::Color(255, 165, 0));
    n1.kandza2.setPosition(327.5, 260);

    if (num % 2 != 0) {
        //ovo sam mogao i drugacije
        sf::RectangleShape crv_temp(sf::Vector2f(30, 8));
        crv_temp.rotate(180);
        n2.noga1 = crv_temp;
        n2.noga1.setFillColor(sf::Color::Color(255, 192, 203));
        n2.noga1.setOutlineThickness(2);
        n2.noga1.setOutlineColor(sf::Color::Color(255, 20, 147));
        n2.noga1.setPosition(390, 255);
    }
    else if (num % 2 == 0) {
        //ovo sam mogao i drugacije
        sf::RectangleShape crv_temp(sf::Vector2f(30, 8));
        crv_temp.rotate(180);
        n2.noga1 = crv_temp;
        n2.noga1.setFillColor(sf::Color::Color(255, 192, 203));
        n2.noga1.setOutlineThickness(2);
        n2.noga1.setOutlineColor(sf::Color::Color(255, 20, 147));
        n2.noga1.setPosition(375, 255);
    }

    //Klasa Glava
    window->draw(g1.lice);
    window->draw(g1.nos);
    window->draw(g1.oko1);
    window->draw(g1.oko2);

    //Klasa Abdomen
    window->draw(a1.trbuh);

    //Klasa Noge
    window->draw(n1.noga1);
    window->draw(n1.noga2);
    window->draw(n1.kandza1);
    window->draw(n1.kandza2);

    //Crv
    window->draw(n2.noga1);


}

int Zivotinja::gen_randNum()
{
    srand(time(NULL));
    int min = 1;
    int max = 100;
    int range = max - min + 1;
    
    int num = rand() % range + min;
    return num;
}

sf::RectangleShape Zivotinja::Glava::get_usi() const
{
    return usi;
}

void Zivotinja::Glava::set_usi(const sf::RectangleShape usi)
{
    this->usi = usi;
}

sf::CircleShape Zivotinja::Glava::get_nos() const
{
    return nos;
}

void Zivotinja::Glava::set_nos(const sf::CircleShape nos)
{
    this->nos = nos;
}

sf::CircleShape Zivotinja::Glava::get_lice() const
{
    return lice;
}

void Zivotinja::Glava::set_lice(const sf::CircleShape lice)
{
    this->lice = lice;
}

sf::CircleShape Zivotinja::Glava::get_oko1() const
{
    return oko1;
}

void Zivotinja::Glava::set_oko1(const sf::CircleShape oci)
{
    this->oko1 = oko1;
}

sf::CircleShape Zivotinja::Glava::get_oko2() const
{
    return oko2;
}

void Zivotinja::Glava::set_oko2(const sf::CircleShape oko2)
{
    this->oko2 = oko2;
}

sf::CircleShape Zivotinja::Abdomen::get_trbuh() const
{
    return trbuh;
}

void Zivotinja::Abdomen::set_trbuh(const sf::CircleShape trbuh)
{
    this->trbuh = trbuh;
}

sf::RectangleShape Zivotinja::Noge::get_noga1() const
{
    return noga1;
}

void Zivotinja::Noge::set_noga1(const sf::RectangleShape noga1)
{
    this->noga1 = noga1;
}

sf::RectangleShape Zivotinja::Noge::get_noga2() const
{
    return noga2;
}

void Zivotinja::Noge::set_noga2(const sf::RectangleShape kandza)
{
    this->noga2 = noga2;
}

sf::RectangleShape Zivotinja::Noge::get_kandza1() const
{
    return kandza1;
}

void Zivotinja::Noge::set_kandza1(const sf::RectangleShape kandza1)
{
    this->kandza1 = kandza1;
}

sf::RectangleShape Zivotinja::Noge::get_kandza2() const
{
    return kandza2;
}

void Zivotinja::Noge::set_kandza2(const sf::RectangleShape kandza2)
{
    this->kandza2 = kandza2;
}
