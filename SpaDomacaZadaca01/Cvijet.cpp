#include "Cvijet.h"
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow* window) 
    : window(window), flower(50.f), sun(10.f), line(sf::Vector2f(150.f, 5.f)), pet1(25.f), pet2(25.f), pet3(25.f), pet4(25.f)
{
    // Init each object

    //sun
    sun.setFillColor(sf::Color::Yellow);
    sun.setOutlineThickness(10.f);
    sun.setOutlineColor(sf::Color::Magenta);
    set_sun_x(15);
    set_sun_y(25);
    sun.setPosition(get_sun_x(), get_sun_y());

    //flower ( circle )
    flower.setFillColor(sf::Color::Yellow);
    flower.setOutlineThickness(10.f);
    flower.setOutlineColor(sf::Color::Red);
    set_flower_x(150); // gornja granica, ne sredina!
    set_flower_y(150); // gornja granica, ne sredina!
    flower.setPosition(get_flower_x(), get_flower_y());
    std::cout << "Flower coordinets: " << std::endl;
    std::cout << "X =  " << get_flower_x() << std::endl;
    std::cout << "Y =  " << get_flower_y() << std::endl;

    //line
    line.setFillColor(sf::Color::Green);
    line.rotate(90);
    set_line_x(get_flower_x() + 50);
    set_line_y(get_flower_y() + 100);
    line.setPosition(get_line_x(), get_line_y());


    //leaf
    convex.setPointCount(4);
    convex.setFillColor(sf::Color::Green);
    set_convex_x(get_line_x());
    set_convex_y(get_line_x() + 130);
    convex.setPoint(0, sf::Vector2f(get_convex_x(), get_convex_y())); // prva tocka na liniji
    convex.setPoint(1, sf::Vector2f(get_convex_x() + 50, get_convex_y() + 15)); // druga tocka desno po x, dolje po y
    convex.setPoint(2, sf::Vector2f(get_convex_x() + 90, get_convex_y())); // treca tocka desno po x, gore po y
    convex.setPoint(3, sf::Vector2f(get_convex_x() + 50, get_convex_y() - 15)); // cetvrta tocka lijevo po x, gore po y

    //pettles
    // Flower coordinates
    float flowerX = 200.f;
    float flowerY = 200.f;

    // Flower radius
    float flowerRadius = 50.f;

    // Petal length (distance from center of flower)
    float petalLength = 60.f;

    // Angle between petals (in radians)
    float angleIncrement = 3.14159f / 2.f;

    // Calculate petal positions
    float angle = 0.f;
    pet1.setFillColor(sf::Color::Blue);
    pet1.setOutlineThickness(2.f);
    set_pet1_x(flowerX + cos(angle) * petalLength - pet1.getRadius());
    set_pet1_y(flowerY + sin(angle) * petalLength - pet1.getRadius());
    pet1.setPosition(get_pet1_x(), get_pet1_y());
    angle += angleIncrement;

    pet2.setFillColor(sf::Color::Blue);
    pet2.setOutlineThickness(2.f);
    set_pet2_x(flowerX + cos(angle) * petalLength - pet2.getRadius());
    set_pet2_y(flowerY + sin(angle) * petalLength - pet2.getRadius());
    pet2.setPosition(get_pet2_x(), get_pet2_y());
    angle += angleIncrement;

    pet3.setFillColor(sf::Color::Blue);
    pet3.setOutlineThickness(2.f);
    set_pet3_x(flowerX + cos(angle) * petalLength - pet3.getRadius());
    set_pet3_y(flowerY + sin(angle) * petalLength - pet3.getRadius());
    pet3.setPosition(get_pet3_x(), get_pet3_y());
    angle += angleIncrement;

    pet4.setFillColor(sf::Color::Blue);
    pet4.setOutlineThickness(2.f);
    set_pet4_x(flowerX + cos(angle) * petalLength - pet4.getRadius());
    set_pet4_y(flowerY + sin(angle) * petalLength - pet4.getRadius());
    pet4.setPosition(get_pet4_x(), get_pet4_y());

    pet1p = &pet1;
    pet2p = &pet2;
    pet3p = &pet3;
    pet4p = &pet4;
    
}

void Cvijet::update_screen() {

    window->setActive(true);
    window->clear();
    window->draw(line);
    window->draw(pet1);
    window->draw(pet2);
    window->draw(pet3);
    window->draw(pet4);
    window->draw(sun);
    window->draw(flower);
    window->draw(convex);
   
    window->display(); // refresh, update the screen
    window->setActive(false);

}


void Cvijet::animate_sun() {
    sf::Clock clock;
    sf::Time elapsed;
    //window object needs to be locked and unlocked with setActive(true/false) while drawing to avoid concurrent access issues
    while (get_sun_x() <= 500.0)
    {

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 0.01)
        {
            //window->setActive(true);
            //window->clear(); // remove all obj from display
            set_sun_x(get_sun_x() + 15);
            sun.setPosition(get_sun_x(), get_sun_y());
            update_screen();
            //window->setActive(false);
            //std::cout << "Prva petlja" << std::endl;
            //std::cout << "Sun: " << get_sun_x() << ", " << get_sun_y() << std::endl;
        }
        else
        {
            continue;
        }

        clock.restart();
    }

    while (get_sun_y() <= 500.0)
    {

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 0.01)
        {
            //window->setActive(true);
            //window->clear(); // remove all obj from display
            set_sun_y(get_sun_y() + 15);
            sun.setPosition(get_sun_x(), get_sun_y());
            update_screen();
            //window->setActive(false);
            //std::cout << "Druga petlja" << std::endl;
            //std::cout << "Sun: " << get_sun_x() << ", " << get_sun_y() << std::endl;
        }
        else
        {
            continue;
        }

        clock.restart();
    }

    while (get_sun_x() <= 510.0 && get_sun_x() > 15.0)
    {

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 0.01)
        {
            //window->setActive(true);
            //window->clear(); // remove all obj from display
            set_sun_x(get_sun_x() - 15);
            sun.setPosition(get_sun_x(), get_sun_y());
            update_screen();
            //window->setActive(false);
            //std::cout << "Treca petlja" << std::endl;
            //std::cout << "Sun: " << get_sun_x() << ", " << get_sun_y() << std::endl;
        }
        else
        {
            continue;
        }

        clock.restart();
    }

    while (get_sun_y() <= 510.0 && get_sun_y() > 15.0)
    {

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 0.01)
        {
            //window->setActive(true);
            //window->clear(); // remove all obj from display
            set_sun_y(get_sun_y() - 15);
            sun.setPosition(get_sun_x(), get_sun_y());
            update_screen();
            //window->setActive(false);
            //std::cout << "Cetvrta petlja" << std::endl;
            //std::cout << "Sun: " << get_sun_x() << ", " << get_sun_y() << std::endl;
        }
        else
        {
            continue;
        }

        clock.restart();
    }
}

void Cvijet::animate_leaf() {
    
    window->clear();
    sf::Clock clock;
    sf::Time elapsed;

    elapsed = clock.restart();
    static float time = 0; // keep track of time
    
    while (elapsed.asSeconds() < 1.5)
    {
        time += 0.1; // increase time by a small amount

        //convex.setPoint(0, sf::Vector2f(200, 330)); // set the first point to the original position
        convex.setPoint(1, sf::Vector2f(250 + sin(time) * 5, 345 + sin(time * 1.2) * 3)); // adjust the second point using a sine wave function
        //convex.setPoint(2, sf::Vector2f(290, 330)); // set the third point to the original position
        convex.setPoint(3, sf::Vector2f(250 + sin(time * 0.8) * 3, 315 + sin(time * 1.5) * 5)); // adjust the fourth point using a sine wave function

        //window->setActive(true);
        //window->clear(); // remove all obj from display
        update_screen();
        //window->setActive(false);

        elapsed = clock.getElapsedTime();
    }

}

void Cvijet::animate_petals(sf::CircleShape* pet1p, sf::CircleShape* pet2p, sf::CircleShape* pet3p, sf::CircleShape* pet4p) { //fu*k this function!!

    const float M_PI = 3.14159265358979323846;
    sf::Clock clock;
    sf::Time elapsed;
    elapsed = clock.restart();

    // Flower coordinates
    float flowerX = 200.f;
    float flowerY = 200.f;

    // Flower radius
    float flowerRadius = 50.f;

    // Petal length (distance from center of flower)
    float petalLength = 60.f;

    // Angle between petals (in radians)
    float angleIncrement = -0.2f;

    // Initialize petal angles
    float petalAngles[4] = { 0.f, -M_PI / 2.f, M_PI, M_PI / 2.f };

    // Update petal positions
    while (elapsed.asSeconds() < 2.0)
    {
        set_pet1_x(flowerX + cos(petalAngles[0]) * petalLength - pet1.getRadius()); // jedini razlog za pointere je bio da dobijem radijus... fml
        set_pet1_y(flowerY + sin(petalAngles[0]) * petalLength - pet1.getRadius());
        pet1.setPosition(get_pet1_x(), get_pet1_y());
        petalAngles[0] += angleIncrement;

        set_pet2_x(flowerX + cos(petalAngles[1]) * petalLength - pet2.getRadius());
        set_pet2_y(flowerY + sin(petalAngles[1]) * petalLength - pet2.getRadius());
        pet2.setPosition(get_pet2_x(), get_pet2_y());
        petalAngles[1] += angleIncrement;

        set_pet3_x(flowerX + cos(petalAngles[2]) * petalLength - pet3.getRadius());
        set_pet3_y(flowerY + sin(petalAngles[2]) * petalLength - pet3.getRadius());
        pet3.setPosition(get_pet3_x(), get_pet3_y());
        petalAngles[2] += angleIncrement;

        set_pet4_x(flowerX + cos(petalAngles[3]) * petalLength - pet4.getRadius());
        set_pet4_y(flowerY + sin(petalAngles[3]) * petalLength - pet4.getRadius());
        pet4.setPosition(get_pet4_x(), get_pet4_y());
        petalAngles[3] += angleIncrement;

        update_screen();

        elapsed = clock.getElapsedTime();
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

void Cvijet::set_convex_x(const double convex_x)
{
    this->convex_x = convex_x;
}

void Cvijet::set_convex_y(const double convex_y)
{
    this->convex_y = convex_y;
}

double Cvijet::get_convex_x() const
{
    return convex_x;
}

double Cvijet::get_convex_y() const
{
    return convex_y;
}

void Cvijet::set_pet1_x(const double pet1_x) {
    this->pet1_x = pet1_x;
}
void Cvijet::set_pet1_y(const double pet1_y) {
    this->pet1_y = pet1_y;
}
double Cvijet::get_pet1_x() const {
    return pet1_x;
}
double Cvijet::get_pet1_y() const {
    return pet1_y;
}
void Cvijet::set_pet2_x(const double pet2_x) {
    this->pet2_x = pet2_x;
}
void Cvijet::set_pet2_y(const double pet2_y) {
    this->pet2_y = pet2_y;
}
double Cvijet::get_pet2_x() const {
    return pet2_x;
}
double Cvijet::get_pet2_y() const {
    return pet2_y;
}
void Cvijet::set_pet3_x(const double pet3_x) {
    this->pet3_x = pet3_x;
}
void Cvijet::set_pet3_y(const double pet3_y) {
    this->pet3_y = pet3_y;
}
double Cvijet::get_pet3_x() const {
    return pet3_x;
}
double Cvijet::get_pet3_y() const {
    return pet3_y;
}
void Cvijet::set_pet4_x(const double pet4_x) {
    this->pet4_x = pet4_x;
}
void Cvijet::set_pet4_y(const double pet4_y) {
    this->pet4_y = pet4_y;
}
double Cvijet::get_pet4_x() const {
    return pet4_x;
}
double Cvijet::get_pet4_y() const {
    return pet4_y;
}
sf::CircleShape* Cvijet::get_pet1p() {
    return pet1p;
}
sf::CircleShape* Cvijet::get_pet2p() {
    return pet2p;
}
sf::CircleShape* Cvijet::get_pet3p() {
    return pet3p;
}
sf::CircleShape* Cvijet::get_pet4p() {
    return pet4p;
}