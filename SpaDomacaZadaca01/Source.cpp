#include <SFML/Graphics.hpp>
#include "Cvijet.h"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(800, 600), "Hello,  world ");

    window.setFramerateLimit(60);

    Cvijet cvijet(window);

    cvijet.draw();

    return 0;
}