#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
    ConvexShape latice;
    CircleShape sredina;
    RectangleShape list;
    RectangleShape stabljika;
    CircleShape sunce;
    RectangleShape zrake[8];
    float kut;
    RenderWindow* window;

public:
    Cvijet(RenderWindow* win);
    void crtaj();
    void update();
    void animirajSunce();
    void postaviPoziciju(float x, float y); 
};
