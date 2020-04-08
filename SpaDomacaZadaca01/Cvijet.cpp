#include "Cvijet.h"
using std::chrono::system_clock;

Cvijet::Cvijet(sf::RenderWindow* window){
    this->mWindow = window;
}

void Cvijet::draw()
{
    
    sf::CircleShape vrh(40);
    vrh.setFillColor(sf::Color::Yellow);
    vrh.setOutlineThickness(50);
    vrh.setOutlineColor(sf::Color::White);
    vrh.setPosition(350, 60);

    sf::RectangleShape stabiljka(sf::Vector2f(150, 6));
    stabiljka.rotate(90);
    stabiljka.setFillColor(sf::Color::White);
    stabiljka.setPosition(390, 190);

    sf::RectangleShape trava(sf::Vector2f(120, 50));
    trava.setSize(sf::Vector2f(200, 200));
    trava.setPosition(290, 300);
    trava.setFillColor(sf::Color::Green);

    mWindow->draw(vrh);
    mWindow->draw(stabiljka);
    mWindow->draw(trava);
 
    mWindow->display();
    this_thread::sleep_until(system_clock::now() + 0.5s);
    mWindow->clear();
    mWindow->display();
    this_thread::sleep_until(system_clock::now() + 0.5s);
}






