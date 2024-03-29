#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}
/* The super fast sun */
void Cvijet::draw_sun(float time)
{
    // Create the big Sun
    sf::CircleShape sun(60); 
    sun.setFillColor(sf::Color(255, 255, 0)); // make it yellow
    sun.setPosition(20, 20);

    // Create some rays behind the sun, make it shine
    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color(255, 165, 0)); // rays are orange
    square.setOrigin(50, 50); 
    square.setPosition(80, 80);

    // Creating the squre rotation for the rays to shine bright, but really fast
    float rotationSpeed = 15.0f; // 15 degrees per rotation
    float rotationAngle = -rotationSpeed * (time / 0.9); //Clockwise orienation
    square.setRotation(rotationAngle);

    window->draw(square);
    window->draw(sun);
}
/* Making that pretty flower */
void Cvijet::draw_flower()
{

    sf::Vector2u windowSize = window->getSize();
    float centerX = windowSize.x / 2.0f;
    float centerY = windowSize.y / 2.0f;

    // Create shapes for flower
    sf::CircleShape centerCircle(65); // Center circle (flower core)
    centerCircle.setFillColor(sf::Color::Red);
    centerCircle.setPosition(centerX - 35, centerY - 45);

    // Petals
    sf::CircleShape petal1(60); // Petal 1
    petal1.setFillColor(sf::Color(255, 192, 203));
    petal1.setPosition(centerX - 80, centerY - 75);

    sf::CircleShape petal2(55); // Petal 2
    petal2.setFillColor(sf::Color(255, 192, 203));
    petal2.setPosition(centerX + 25, centerY - 95);

    sf::CircleShape petal3(60); // Petal 3
    petal3.setFillColor(sf::Color(255, 192, 203));
    petal3.setPosition(centerX + 25, centerY - 15);

    sf::CircleShape petal4(60); // Petal 4
    petal4.setFillColor(sf::Color(255, 192, 203));
    petal4.setPosition(centerX - 75, centerY - 5);

    // Stem
    sf::RectangleShape stem(sf::Vector2f(10, 150));
    stem.setFillColor(sf::Color(34, 139, 34)); // Dark green color
    stem.setPosition(centerX + 30, centerY + 60);

    // Leaves
    sf::ConvexShape leaf1; // Leaf 1
    leaf1.setPointCount(4);
    leaf1.setFillColor(sf::Color(34, 139, 34)); // Dark green color
    leaf1.setPoint(0, sf::Vector2f(centerX + 35, centerY + 160));
    leaf1.setPoint(1, sf::Vector2f(centerX + 60, centerY + 190));
    leaf1.setPoint(2, sf::Vector2f(centerX + 110, centerY + 140));
    leaf1.setPoint(3, sf::Vector2f(centerX + 60, centerY + 120));

    sf::ConvexShape leaf2; // Leaf 2
    leaf2.setPointCount(4);
    leaf2.setFillColor(sf::Color(34, 139, 34)); // Dark green color
    leaf2.setPoint(0, sf::Vector2f(centerX + 35, centerY + 160));
    leaf2.setPoint(1, sf::Vector2f(centerX + 10, centerY + 190));
    leaf2.setPoint(2, sf::Vector2f(centerX - 40, centerY + 140));
    leaf2.setPoint(3, sf::Vector2f(centerX + 10, centerY + 120));

    sf::ConvexShape leaf3; // Leaf 3
    leaf3.setPointCount(4);
    leaf3.setFillColor(sf::Color(34, 139, 34)); // Dark green color
    leaf3.setPoint(0, sf::Vector2f(centerX + 35, centerY + 160));
    leaf3.setPoint(1, sf::Vector2f(centerX + 60, centerY + 190));
    leaf3.setPoint(2, sf::Vector2f(centerX + 110, centerY + 140));
    leaf3.setPoint(3, sf::Vector2f(centerX + 60, centerY + 120));
    leaf3.setRotation(180);

    sf::ConvexShape leaf4; // Leaf 4
    leaf4.setPointCount(4);
    leaf4.setFillColor(sf::Color(34, 139, 34)); // Dark green color
    leaf4.setPoint(0, sf::Vector2f(centerX + 35, centerY + 160));
    leaf4.setPoint(1, sf::Vector2f(centerX + 10, centerY + 190));
    leaf4.setPoint(2, sf::Vector2f(centerX - 40, centerY + 140));
    leaf4.setPoint(3, sf::Vector2f(centerX + 10, centerY + 120));
    leaf4.setRotation(180);

    // Draw shapes
    window->draw(stem);
    window->draw(petal1);
    window->draw(petal2);
    window->draw(petal3);
    window->draw(petal4);
    window->draw(centerCircle);
    window->draw(leaf1);
    window->draw(leaf2);
    window->draw(leaf3);
    window->draw(leaf4);
}
/* Make that beautiful green grass */
void Cvijet::draw_grass()
{
    // 50 lines of grass :D
    const int numBlades = 100;

    // The grass are the lines
    sf::VertexArray grass(sf::Lines);

    // The grass will go up and down, max and min values
    float minHeight = 50.0f;
    float maxHeight = 100.0f;

    // Grass line width
    float bladeWidth = window->getSize().x / numBlades;

    // One forinjo, populate the vertex array with grass blades
    for (int i = 0; i < numBlades; ++i)
    {
        // how the grass will grow and shrink in random
        float height = minHeight + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxHeight - minHeight)));

        // Calculate positions
        sf::Vector2f point1(i * bladeWidth, window->getSize().y);
        sf::Vector2f point2((i + 0.5f) * bladeWidth, window->getSize().y - height);

        // Add points to the vertex array
        grass.append(sf::Vertex(point1, sf::Color::Green));
        grass.append(sf::Vertex(point2, sf::Color::Green));
    }

    // Make it happen with the grass
    window->draw(grass);
}
