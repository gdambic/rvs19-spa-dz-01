#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw()
{
    //sun
    CircleShape sunce(10.f);
    sunce.setFillColor(Color(255, 255, 0));
    sunce.setPosition(Vector2f(5, 5));
    Time elapsed1 = clock.getElapsedTime();

    if (clock.getElapsedTime().asMilliseconds() > 2000)
    {
        sunce.setRadius(30.f - 10.f * ((clock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
        if (clock.getElapsedTime().asMilliseconds() >= 4000)
        {
            clock.restart();
        }
    }
    else
    {
        sunce.setRadius(20.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
    }
    window->draw(sunce);

    //flower_head
    CircleShape head(100.f);
    head.setFillColor(Color(237, 233, 15));
    head.setOutlineThickness(50.f);
    head.setOutlineColor(Color(255, 0, 0));
    head.setPosition(Vector2f(280, 80));
    window->draw(head);

    //line
    RectangleShape line(Vector2f(150.f, 5.f));
    line.rotate(90.f);
    line.setFillColor(Color(137, 201, 91));
    line.setPosition(Vector2f(383, 329));
    line.setSize(Vector2f(250.f, 10.f));
    window->draw(line);

    //leaf
    leaf.setPointCount(4);
    leaf.setPoint(0, Vector2f(375.f, 440.f));
    leaf.setPoint(1, Vector2f(440.f, 400.f));
    leaf.setPoint(2, Vector2f(600.f, 360.f));
    leaf.setPoint(3, Vector2f(460.f, 450.f));
    leaf.setFillColor(Color(137, 201, 91));
    window->draw(leaf);

    //weed
    RectangleShape weed(Vector2f(200.f, 200.f));
    weed.setFillColor(Color(45, 103, 3));
    weed.setPosition(Vector2f(0, 500));
    weed.setSize(Vector2f(800.f, 600.f));
    window->draw(weed);




    //eye1
    CircleShape eye11(37.f);
    eye11.setFillColor(Color(22, 163, 242));
    eye11.setPosition(Vector2f(312, 102));
    eye11.setOutlineThickness(3.f);
    eye11.setOutlineColor(Color(0, 0, 0));
    window->draw(eye11);

    CircleShape eye1(5.f);
    eye1.setFillColor(Color(0, 0, 0));
    eye1.setPosition(Vector2f(310, 100));
    Time elapsed2 = clock.getElapsedTime();

    if (clock.getElapsedTime().asMilliseconds() > 2000)
    {
        eye1.setRadius(30.f - 10.f * ((clock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
        if (clock.getElapsedTime().asMilliseconds() >= 4000)
        {
            clock.restart();
        }
    }
    else
    {
        eye1.setRadius(20.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
    }
    window->draw(eye1);

    //eye2
    CircleShape eye22(37.f);
    eye22.setFillColor(Color(22, 163, 242));
    eye22.setPosition(Vector2f(402, 102));
    eye22.setOutlineThickness(3.f);
    eye22.setOutlineColor(Color(0, 0, 0));
    window->draw(eye22);

    CircleShape eye2(10.f);
    eye2.setFillColor(Color(0, 0, 0));
    eye2.setPosition(Vector2f(400, 100));
    Time elapsed3 = clock.getElapsedTime();

    if (clock.getElapsedTime().asMilliseconds() > 2000)
    {
        eye2.setRadius(30.f - 10.f * ((clock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
        if (clock.getElapsedTime().asMilliseconds() >= 4000)
        {
            clock.restart();
        }
    }
    else
    {
        eye2.setRadius(20.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
    }
    window->draw(eye2);


    //mouth
    mouth.setPointCount(3);
    mouth.setPoint(0, Vector2f(400.f, 300.f));
    mouth.setPoint(1, Vector2f(315.f, 260.f));
    mouth.setPoint(2, Vector2f(510.f, 190.f));
    mouth.setFillColor(Color(228, 241, 245));
    mouth.setOutlineThickness(5.f);
    mouth.setOutlineColor(Color(0, 0, 0));
    window->draw(mouth);

}
