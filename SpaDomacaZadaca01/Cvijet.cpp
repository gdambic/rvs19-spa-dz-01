#include "Cvijet.h"
#include <iostream>
using namespace sf;
using namespace std;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
   CircleShape sunce(60.f);
   sunce.setFillColor(Color::Yellow);
   sunce.setPosition(500.f, 60.f);

   for (size_t i = 0; i < 20; i++)
   {
       CircleShape sunray(60.f, 3);
       sunray.setPosition(Vector2f(555.f,120.f));
       sunray.setFillColor(Color::Yellow);
       sunray.rotate(10.f * i * 4);
       window->draw(sunray);
   }

   Font font;
   font.loadFromFile("./arial.ttf");
   
   Text text;

   text.setFont(font);

   text.setString("Sunce zlatino");

   text.setCharacterSize(24);

   text.setFillColor(Color::Black);

   text.setStyle(Text::Bold | Text::Underlined);
   
   text.setPosition(Vector2f(480.f, 110.f));

   ConvexShape convex;
   convex.setFillColor(Color::Red);
   convex.setPointCount(6);

   convex.setPoint(0, Vector2f(10.f, 10.f));  
   convex.setPoint(1, Vector2f(60.f, 60.f));
   convex.setPoint(2, Vector2f(110.f,10.f));
   convex.setPoint(3, Vector2f(110.f, 160.f));
   convex.setPoint(4, Vector2f(60.f, 210.f));
   convex.setPoint(5, Vector2f(10.f, 160.f));

	RectangleShape line(Vector2f(160.f, 10.f));
    line.setFillColor(Color::Green);
	line.rotate(90.f);
	line.setPosition(Vector2f(65.f, 205.f));

    window->draw(convex);
    window->draw(sunce);
	window->draw(line);
    window->draw(text);

}

