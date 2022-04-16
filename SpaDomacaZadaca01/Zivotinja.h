#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Zivotinja
{
public:

    Zivotinja(sf::RenderWindow* window);

    void draw();

    int gen_randNum();

    class Glava 
    {
    public: 
        sf::RectangleShape usi;
        sf::CircleShape nos;
        sf::CircleShape oko1;
        sf::CircleShape oko2;
        sf::CircleShape lice;

        sf::RectangleShape get_usi()const;
        void set_usi(const sf::RectangleShape usi);

        sf::CircleShape get_nos()const;
        void set_nos(const sf::CircleShape nos);

        sf::CircleShape get_lice()const;
        void set_lice(const sf::CircleShape lice);

        sf::CircleShape get_oko1()const;
        void set_oko1(const sf::CircleShape oko1);

        sf::CircleShape get_oko2()const;
        void set_oko2(const sf::CircleShape oko2);

    };

    class Abdomen
    {
    public:
        sf::CircleShape trbuh;

        sf::CircleShape get_trbuh()const;
        void set_trbuh(const sf::CircleShape trbuh);
    };

    class Noge
    {
    public:
        sf::RectangleShape noga1;
        sf::RectangleShape noga2;
        sf::RectangleShape kandza1;
        sf::RectangleShape kandza2;

        sf::RectangleShape get_noga1()const;
        void set_noga1(const sf::RectangleShape noga1);

        sf::RectangleShape get_noga2()const;
        void set_noga2(const sf::RectangleShape noga2);

        sf::RectangleShape get_kandza1()const;
        void set_kandza1(const sf::RectangleShape kandza1);

        sf::RectangleShape get_kandza2()const;
        void set_kandza2(const sf::RectangleShape kandza2);
    };

private:
    sf::RenderWindow* window;
    Glava g1;
    Abdomen a1;
    Noge n1, n2;
};

