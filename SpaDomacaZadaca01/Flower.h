#include <SFML/Graphics.hpp>

class Flower
{
public:
    Flower(sf::RenderWindow &window);

    void draw();

private:

    sf::RenderWindow &window;

    //Flower
    sf::CircleShape head;
    sf::CircleShape stem;
    sf::ConvexShape leaf1;
    sf::ConvexShape leaf2;

    //Sun
    sf::CircleShape sun;
    sf::Clock frameClock;

}