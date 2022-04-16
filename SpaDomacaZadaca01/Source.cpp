#include "SFML/Graphics.hpp"

int main() {
    sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Sprite");

    sf::Event event;
    sf::Texture texture;
    texture.loadFromFile("chardons.png");

    sf::IntRect okvir(200, 0, 70, 50);
    sf::Sprite predlozak(texture, okvir);
    sf::Clock clock;

    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            if (okvir.left == 600)
                okvir.left = 0;
            else
                okvir.left += 50;

            predlozak.setTextureRect(okvir);
            clock.restart();
        }


        renderWindow.clear();
        renderWindow.draw(predlozak);
        renderWindow.display();
    }
}