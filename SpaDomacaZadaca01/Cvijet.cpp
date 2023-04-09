#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;

    flower.setFillColor(sf::Color::Magenta);
    flower.setOutlineThickness(10.f);
    flower.setOutlineColor(sf::Color::Red);
    flower.setRadius(50);
    set_flower_x(200);
    set_flower_y(200);
    flower.setPosition(get_flower_x(), get_flower_y());

    sun.setFillColor(sf::Color::Yellow);
    sun.setOutlineThickness(10.f);
    sun.setOutlineColor(sf::Color::Blue);
    sun.setRadius(10);
    set_sun_x(20);
    set_sun_y(25);
    sun.setPosition(get_sun_x(), get_sun_y());

    line.setFillColor(sf::Color::Green);
    line.setSize(sf::Vector2f(150.f, 5.f));
    line.rotate(90);
    set_line_x(get_flower_x() + 50);
    set_line_y(get_flower_y() + 100);
    line.setPosition(get_line_x(), get_line_y());

    leaf.setPointCount(4);
    leaf.setFillColor(sf::Color::Green);
    set_leaf_x(get_line_x());
    set_leaf_y(get_line_x() + 100);
    leaf.setPoint(0, sf::Vector2f(get_leaf_x(), get_leaf_y()));
    leaf.setPoint(1, sf::Vector2f(get_leaf_x() + 70, get_leaf_y() + 20));
    leaf.setPoint(2, sf::Vector2f(get_leaf_x() + 110, get_leaf_y()));
    leaf.setPoint(3, sf::Vector2f(get_leaf_x() + 60, get_leaf_y() - 20));


}

void Cvijet::draw_screen() {

    window->setActive(true);
    window->clear();
    window->draw(line);
    window->draw(sun);
    window->draw(flower);
    window->draw(leaf);
    window->display();
    window->setActive(false);

}


void Cvijet::animate_the_sun() {

    sf::Clock clock;
    sf::Time elapsed;

    while (get_sun_x() <= 500.0)
    {

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 0.01)
        {
            set_sun_x(get_sun_x() + 15);
            sun.setPosition(get_sun_x(), get_sun_y());
            draw_screen();
        }
        else
        {
            continue;
        }

        clock.restart();
    }
    while (get_sun_x() > 0)
    {

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 0.01)
        {
            set_sun_x(get_sun_x() - 15);
            sun.setPosition(get_sun_x(), get_sun_y());
            draw_screen();
        }
        else
        {
            continue;
        }

        clock.restart();
    }

}
void Cvijet::set_sun_x(const double sun_x)
{
    this->sun_x = sun_x;
}

void Cvijet::set_sun_y(const double sun_y)
{
    this->sun_y = sun_y;
}

double Cvijet::get_sun_x() const
{
    return sun_x;
}

double Cvijet::get_sun_y() const
{
    return sun_y;
}

void Cvijet::set_flower_x(const double flower_x)
{
    this->flower_x = flower_x;
}

void Cvijet::set_flower_y(const double flower_y)
{
    this->flower_y = flower_y;
}

double Cvijet::get_flower_x() const
{
    return flower_x;
}

double Cvijet::get_flower_y() const
{
    return flower_y;
}

void Cvijet::set_line_x(const double line_x)
{
    this->line_x = line_x;
}

void Cvijet::set_line_y(const double line_y)
{
    this->line_y = line_y;
}

double Cvijet::get_line_x() const
{
    return line_x;
}

double Cvijet::get_line_y() const
{
    return line_y;
}

void Cvijet::set_leaf_x(const double leaf_x)
{
    this->leaf_x = leaf_x;
}

void Cvijet::set_leaf_y(const double leaf_y)
{
    this->leaf_y = leaf_y;
}

double Cvijet::get_leaf_x() const
{
    return leaf_x;
}

double Cvijet::get_leaf_y() const
{
    return leaf_y;
}
