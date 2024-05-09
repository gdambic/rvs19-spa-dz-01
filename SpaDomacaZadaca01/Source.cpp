#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Cvijet.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Hello, SFML world!", Style::Default);
    window.setFramerateLimit(60);
    Cvijet cvijet(&window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

/*        cvijet.update();*/  // Update animation state

        window.clear(Color::Black);
        cvijet.draw();  // Draw everything
        window.display();
    }

    return 0;
}
