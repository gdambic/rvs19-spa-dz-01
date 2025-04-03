#include "Cvijet.h"
#include <cmath>
Cvijet::Cvijet(sf::RenderWindow* win)
{
    window = win;
    nebo.setSize(sf::Vector2f(800, 600));
    nebo.setFillColor(sf::Color(135, 206, 250));
    sunce.setRadius(40);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(50, 50);
    sunceScale = 40;
    smanjujeSe = true;
    sredina.setRadius(50);
    sredina.setFillColor(sf::Color::Yellow);
    sredina.setPosition(325, 200);
    for (int i = 0; i < 6; i++) {
        latice[i].setPointCount(4);
        latice[i].setPoint(0, sf::Vector2f(100, 0));
        latice[i].setPoint(1, sf::Vector2f(150, 50));
        latice[i].setPoint(2, sf::Vector2f(100, 100));
        latice[i].setPoint(3, sf::Vector2f(0, 50));
        latice[i].setFillColor(sf::Color::Red);
        latice[i].setOrigin(50, 50);
        latice[i].setPosition(375, 250);
        latice[i].setRotation(i * 60);
    }
    stabljika.setSize(sf::Vector2f(10, 200));
    stabljika.setFillColor(sf::Color::Green);
    stabljika.setPosition(370, 300);
    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(0, 0));
    list.setPoint(1, sf::Vector2f(100, -30));
    list.setPoint(2, sf::Vector2f(150, 30));
    list.setPoint(3, sf::Vector2f(50, 40));
    list.setFillColor(sf::Color::Green);
    list.setPosition(350, 400);
    for (int i = 0; i < 3; i++) {
        sf::CircleShape oblak1(30);
        oblak1.setFillColor(sf::Color::White);
        oblak1.setPosition(200 + i * 250, 100);
        oblaci.push_back(oblak1);
        sf::CircleShape oblak2(30);
        oblak2.setFillColor(sf::Color::White);
        oblak2.setPosition(230 + i * 250, 100);
        oblaci.push_back(oblak2);
        sf::CircleShape oblak3(30);
        oblak3.setFillColor(sf::Color::White);
        oblak3.setPosition(210 + i * 250, 130); 
        oblaci.push_back(oblak3);
    }
    tlo.setSize(sf::Vector2f(800, 100));  
    tlo.setFillColor(sf::Color(34, 139, 34)); 
    tlo.setPosition(0, 500);  
}

void Cvijet::draw() {
    sf::Time elapsed = frameClock.getElapsedTime();
    if (elapsed.asMilliseconds() > 50) {
        if (smanjujeSe) {
            sunceScale -= 0.5;
            if (sunceScale <= 30) smanjujeSe = false;
        }
        else {
            sunceScale += 0.5;
            if (sunceScale >= 40) smanjujeSe = true;
        }
        sunce.setRadius(sunceScale);
        sunce.setPosition(50, 50);
        windOffset = std::sin(elapsed.asSeconds() * 2) * 5;
        for (int i = 0; i < 6; i++) {
            float angleOffset = std::sin(elapsed.asSeconds() * 2 + i) * 5;
            latice[i].setRotation(i * 60 + angleOffset);
        }
        for (auto& oblak : oblaci) {
            oblak.move(0.5, 0);
            if (oblak.getPosition().x > 800) oblak.setPosition(-60, oblak.getPosition().y);
        }

        frameClock.restart();
    }

    window->draw(nebo);
    window->draw(sunce);
    for (auto& oblak : oblaci) window->draw(oblak);  
    window->draw(stabljika);
    window->draw(list);
    for (auto& latica : latice) window->draw(latica);
    window->draw(sredina);
    window->draw(tlo);
}
