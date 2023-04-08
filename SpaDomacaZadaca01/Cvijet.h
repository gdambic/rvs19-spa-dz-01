#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet {
public:
    Cvijet(RenderWindow& window) : window(window) {}
    void draw(RenderWindow& window);

    // central part of peach flower

    CircleShape PEACH_FLOWER_BASE;

    // inner circles for central part of peach flower
    CircleShape INNER_CIRCLE_01;
    CircleShape INNER_CIRCLE_02;
    CircleShape INNER_CIRCLE_03;
    CircleShape INNER_CIRCLE_04;
    CircleShape INNER_CIRCLE_05;
    
    // peach flower petals

    CircleShape PEACH_FLOWER_CIRCLE_01;
    CircleShape PEACH_FLOWER_CIRCLE_02;
    CircleShape PEACH_FLOWER_CIRCLE_03;
    CircleShape PEACH_FLOWER_CIRCLE_04;
    CircleShape PEACH_FLOWER_CIRCLE_05;
    CircleShape PEACH_FLOWER_CIRCLE_06;

    // support branch for the peach flower

    RectangleShape PEACH_BRANCH;

    // animated objects

    CircleShape SUN;

private:
    RenderWindow& window;

    // sun variables
    float velicina_sunca = 1;
    bool rast_sunca = true;
};

