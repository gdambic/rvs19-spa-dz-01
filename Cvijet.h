#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>

using namespace std;

class Cvijet
{
public:
    Cvijet(sf::RenderWindow& win);
    void draw();

private:
    sf::RenderWindow& window;
    sf::RenderTexture canvas;
    sf::Sprite canvasSprite;
    float W, H;          // low-res canvas size
    float winW, winH;    // actual window size

    sf::Clock frameClock;
    float totalTime;

    float getDayFactor() const;
    sf::Color lerp(sf::Color a, sf::Color b, float t) const;

    void drawSky();
    void drawStars();
    void drawMoon();
    void drawSun();
    void drawClouds();
    void drawMountains();
    void drawTrees();
    void drawGround();
    void drawFlowers();
    void drawFireflies();

    struct Star { float x, y, bright, speed, phase; };
    vector<Star> stars;

    struct Firefly { float x, y, phase, speed; };
    vector<Firefly> fireflies;
};
