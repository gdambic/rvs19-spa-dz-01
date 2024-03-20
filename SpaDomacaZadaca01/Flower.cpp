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
    petal_num = 6;                   // Default number of petals
    petal_size = 25.f;               // Default petal size
    stem_width = 10.f;               // Default stem size
    stem_lenght = 200.f;             // Default stem size
    center_size = 30.f;              // Default center size
    leaves_num = 5;                  // Default number of leaves
    leaf_size = 30.f;                // Default leaf size
    flower_num = 1;                  // Number of flowers
    petal_color = sf::Color::Yellow; // Default petal color
    center_color = sf::Color::Red;   // Default center color
    stem_color = sf::Color::Green;   // Default stem color
    leaf_color = sf::Color::Green;   // Default leaf color
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
        petal.setPosition(400 + cos(i * 2 * 3.14 / petal_num) * 60 - petal_size, 300 + sin(i * 2 * 3.14 / petal_num) * 60 - petal_size);
        petal.setFillColor(petal_color);
        window.draw(petal);
    }


    // Draw stem
    sf::RectangleShape stem(sf::Vector2f(stem_width, stem_lenght));
    stem.setOrigin(stem_width / 2, 0);
    stem.setPosition(400, 300 + center_size);
    stem.setFillColor(stem_color);
    window.draw(stem);


    //draw leaves
    int starting_y = 420; // Y position of the first leaf
    int x_center = 400; // X position of the stem center
    int offset_x = 50; // Horizontal distance from the stem to the leaf tip
    int offset_y = 20; // Vertical distance between each leaf

    for (int i = 0; i < leaves_num; ++i) {
        // Determine the side for the current leaf: right (1) for even i, left (-1) for odd i
        int side = i % 2 == 0 ? 1 : -1;
        // Calculate y position for the current leaf
        int y_position = starting_y + (i * offset_y);

        sf::ConvexShape leaf;
        leaf.setPointCount(3);
        leaf.setPoint(0, sf::Vector2f(x_center, y_position));
        leaf.setPoint(1, sf::Vector2f(x_center + side * offset_x, y_position));
        leaf.setPoint(2, sf::Vector2f(x_center + side * (offset_x / 2), y_position + offset_y / 2));
        leaf.setFillColor(leaf_color);
        window.draw(leaf);
    }

}




//setters   
void Flower::setPetalNum(int num)
{
    if (num < 0)
    {
        cout << "flower cant have negative petals" << endl;
    }
    else if (num > 30)
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
    else if (size > 50)
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
