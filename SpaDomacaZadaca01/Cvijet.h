#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include<vector>;
using namespace std;

class Cvijet
{
private:
    sf::RenderWindow* window;
    sf::CircleShape krug;
    sf::CircleShape krug2;
    sf::CircleShape sunce;
    sf::RectangleShape stapka;
    sf::ConvexShape list;
    sf::Clock frameClock;
    sf::Texture texture;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture texturep;
    sf::Texture textureBackground;
    sf::Sprite spriteBackground;
    bool sunce_malo = true;
    bool krug1 = true;
      
public:
    Cvijet(sf::RenderWindow* window);
    void draw();
    void set_background(sf::Sprite& spriteBackground);
    void set_krug(sf::CircleShape &krug);
    void set_krug2(sf::CircleShape &krug2);
    void set_sunce(sf::CircleShape &sunce);
    void set_stapka(sf::RectangleShape &stapka);
    void set_list(sf::ConvexShape &list);
    sf::CircleShape get_krug();
    sf::CircleShape get_krug2();
    sf::CircleShape get_sunce();
    sf::RectangleShape get_stapka();
    sf::ConvexShape get_list();
    sf::Sprite get_spriteBackground();
};
