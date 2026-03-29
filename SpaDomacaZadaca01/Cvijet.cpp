#include "Cvijet.hpp"
#include<cmath>

Cvijet::Cvijet(sf::RenderWindow* window)
    : m_window(window)
{
    // center
    center.setRadius(25.f);
    center.setFillColor(sf::Color::Yellow);
    center.setOrigin(25.f, 25.f);
    center.setPosition(400.f, 300.f);

    // petals
    float angle = 0.f;
    for (int i = 0; i < 6; ++i) {
        petals[i].setRadius(20.f);
        petals[i].setFillColor(sf::Color::Red);
        petals[i].setOrigin(20.f, 20.f);
        float rad = angle * 3.14159265f / 180.f;
        float x = 400.f + std::cos(rad) * 45.f;
        float y = 300.f + std::sin(rad) * 45.f;
        petals[i].setPosition(x, y);
        angle += 60.f;
    }

    // stem
    stem.setSize(sf::Vector2f(10.f, 150.f));
    stem.setFillColor(sf::Color(34, 139, 34));
    stem.setOrigin(5.f, 0.f);
    stem.setPosition(400.f, 325.f);

    // leaf
    leaf.setRadius(20.f);
    leaf.setFillColor(sf::Color(34, 139, 34));
    leaf.setOrigin(20.f, 20.f);
    leaf.setPosition(420.f, 400.f);
    leaf.setRotation(45.f);

	// sun
	sunRadius = 20.f; // pocetni polumjer sunca
	sunGrowing = true; // inicijalno raste
	frameClock.restart(); // pokretanje sata
	sun.setRadius(sunRadius); // pocetni polumjer sunca
	sun.setFillColor(sf::Color::Yellow); // boja sunca
	sun.setOrigin(sunRadius, sunRadius); // centriranje sunca
	sun.setPosition(700.f, 100.f); //polozaj sunca
}

void Cvijet::draw()
{
    //crtanje sunca
	float dt = frameClock.restart().asSeconds(); // vrijeme proteklo od zadnjeg framea
    float speed = 5.f; // prilagodi brzinu
	if (sunGrowing) sunRadius += speed * dt; else sunRadius -= speed * dt; // sun raste ili se smanjuje ovisno o stanju
	if (sunRadius >= 20.f) { sunRadius = 20.f; sunGrowing = false; } // sun se smanjuje kad dosegne 20, raste kad dosegne 15
    else if (sunRadius <= 15.f) { sunRadius = 15.f; sunGrowing = true; } 
	sun.setRadius(sunRadius); // postavljanje novog polumjera sunca
	sun.setOrigin(sunRadius, sunRadius); // centriranje sunca nakon promjene polumjera
	m_window->draw(sun); // crtanje sunca

    if (m_window) 
    {
        m_window->draw(stem);
        for (int i = 0; i < 6; ++i) m_window->draw(petals[i]);
        m_window->draw(center);
        m_window->draw(leaf);
    }
}
