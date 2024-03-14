#include "Flower.h"
#include <iostream>
using namespace std;




//read the user input
float Flower::readinput()
{
    float input;
	cin >> input;
	return input;
}

//flower class constructor
Flower::Flower() {
	// Set default values
    petal_num = 6;                   // Default number of petals
    petal_size = 30.f;               // Default petal size
    stem_width = 10.f;               // Default stem size
    stem_lenght = 200.f;             // Default stem size
    center_size = 30.f;              // Default center size
    leaves_num = 5;                  // Default number of leaves
    leaf_size = 30.f;                // Default leaf size
    flower_num = 1;                  // Number of flowers
    season = 0;                      // Default to summer (0 stand for summer)
    spring_intensity = 0.5f;         // Default spring intensity
    summer_intensity = 0.5f;         // Default summer intensity
    winter_intensity = 0.5f;         // Default winter intensity
    wind_intensity = 0.5f;           // Default wind intensity
    petal_color = sf::Color::Yellow;    // Default petal color
    center_color = sf::Color::Red;// Default center color
    stem_color = sf::Color::Green;   // Default stem color
    leaf_color = sf::Color::Green;   // Default leaf colocr

}


//draw the flower on the window
void Flower::draw(sf::RenderWindow& window) {
   
    // Draw center
    sf::CircleShape center(center_size);
    center.setPosition(400 - center_size, 300 - center_size);
    center.setFillColor(center_color);
    window.draw(center);

    // Draw petals
    for (int i = 0; i < petal_num; ++i) {
        sf::CircleShape petal(petal_size);
        petal.setPosition(400 + cos(i * 2 * 3.14159 / petal_num) * 60 - petal_size, 300 + sin(i * 2 * 3.14159 / petal_num) * 60 - petal_size);
        petal.setFillColor(petal_color);
        window.draw(petal);
    }

    // Draw stem
    sf::RectangleShape stem(sf::Vector2f(stem_width, stem_lenght));
    stem.setOrigin(stem_width / 2, 0);
    stem.setPosition(400, 300 + center_size);
    stem.setFillColor(stem_color);
    window.draw(stem);

    // Draw leaves
   sf::ConvexShape leaf;
   leaf.setPointCount(3);
   leaf.setPoint(0, sf::Vector2f(0, 0));
   leaf.setPoint(1, sf::Vector2f(40, 20));
}




//setters   
void Flower::setPetalNum(int num)
{
    if (num < 0)
    {
        cout << "flower cant have negative petals" << endl;
    }
    else if (num > 100)
    {
        cout << "flower cant have that many petals" << endl;
    }
    else
    {
        this->petal_num = num;
    }
}

void Flower::setPetalSize(float size)
{
    if (size < 0)
    {
        cout << "Petals cant be negatively sized" << endl;
    }
    else if (size > 300)
    {
        cout << "Petals cant be that large" << endl;
    }
    else
    {
        this->petal_size = size;
    }
}

void Flower::setStemWidth(float width)
{
    if (width < 2)
    {
        cout << "Stem cant be that thin" << endl;
    }
    else if (width > 50)
    {
		cout << "Stem cant be that wide" << endl;
	}
    else
    {
		this->stem_width = width;
	}
}

void Flower::setStemLenght(float lenght)
{
    if (lenght < 50)
    {
		cout << "Stem cant be that short" << endl;
	}
    else if (lenght > 500)
    {
		cout << "Stem cant be that long" << endl;
	}
    else
    {
		this->stem_lenght = lenght;
	}
}

void Flower::setCenterSize(float size)
{
    if (size < 10)
    {
		cout << "Center cant be that small" << endl;
	}
    else if (size > 300)
    {
		cout << "Center cant be that large" << endl;
	}
    else
    {
		this->center_size = size;
	}
}

void Flower::setLeavesNum(int num)
{
    if (num < 0)
    {
		cout << "Flower cant have negative leaves" << endl;
	}
    else if (num > 10)
    {
		cout << "Flower cant have that many leaves" << endl;
	}
    else
    {
		this->leaves_num = num;
	}
}

void Flower::setLeafSize(float size)
{
    this->leaf_size = size;
}

void Flower::setFlowerNum(int num)
{
   	this->flower_num = num;
}

void Flower::setSeason(int season)
{
	this->season = season;
}

void Flower::setSpringIntensity(float intensity)
{
	this->spring_intensity = intensity;
}

void Flower::setSummerIntensity(float intensity)
{
	this->summer_intensity = intensity;
}

void Flower::setWinterIntensity(float intensity)
{
	this->winter_intensity = intensity;
}

void Flower::setWindIntensity(float intensity)
{
    this->wind_intensity = intensity;
}

void Flower::setPetalColor(sf::Color color)
{
	this->petal_color = color;
}

void Flower::setCenterColor(sf::Color color)
{
	this->center_color = color;
}

void Flower::setStemColor(sf::Color color)
{
	this->stem_color = color;
}

void Flower::setLeafColor(sf::Color color)
{
	this->leaf_color = color;
}


//getters

int Flower::getPetalNum()
{
    return petal_num;
}

float Flower::getPetalSize()
{
    return petal_size;
}

float Flower::getStemWidth()
{
    return stem_width;
}

float Flower::getStemLenght()
{
    return stem_lenght;
}

float Flower::getCenterSize()
{
    return center_size;
}

int Flower::getLeavesNum()
{
    return leaves_num;
}

float Flower::getLeafSize()
{
    return leaf_size;
}

int Flower::getFlowerNum()
{
    return flower_num;
}

int Flower::getSeason()
{
    return season;
}

float Flower::getSpringIntensity()
{
    return spring_intensity;
}

float Flower::getSummerIntensity()
{
    return summer_intensity;
}

float Flower::getWinterIntensity()
{
    return winter_intensity;
}

float Flower::getWindIntensity()
{
    return wind_intensity;
}

sf::Color Flower::getPetalColor()
{
    return petal_color;
}

sf::Color Flower::getCenterColor()
{
    return center_color;
}

sf::Color Flower::getStemColor()
{
    return stem_color;
}

sf::Color Flower::getLeafColor()
{
    return leaf_color;
}
