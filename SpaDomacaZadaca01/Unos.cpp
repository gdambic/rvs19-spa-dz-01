#include "Unos.h"

void Unos::setWidth()
{
    this->width = 800;
}

void Unos::setHeight()
{
    this->height = 600;
}

Unos::Unos()
{
    setWidth();
    setHeight();
}

int Unos::getWidth()
{
    return width;
}

int Unos::getHeight()
{
    return height;
}
