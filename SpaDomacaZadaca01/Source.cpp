#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet");
    window.setFramerateLimit(60);

    Cvijet cvijet(200, 200);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //koristite strijelice na tipkovnici za pomicanje cvijeta
        cvijet.user_movement(7.5, window);
        window.clear(sf::Color::White);
        cvijet.draw(window);
        window.display();
	}

	return 0;
}