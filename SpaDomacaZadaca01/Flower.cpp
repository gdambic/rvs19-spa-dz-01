#include "Flower.h"

Flower::Flower() {
	// Set default values
	//flower instance:
    petal_num = 5;                   // Default number of petals
    petal_size = 20.f;               // Default petal size
    stem_size = 10.f;                // Default stem size
    center_size = 30.f;              // Default center size
    leaves_num = 2;                  // Default number of leaves
    leaf_size = 15.f;                // Default leaf size
    flower_num = 1;                  // Number of flowers
    season = 0;                      // Default to summer (0 stand for summer)
    spring_intensity = 0.5f;         // Default spring intensity
    summer_intensity = 0.5f;         // Default summer intensity
    winter_intensity = 0.5f;         // Default winter intensity
    wind_intensity = 0.5f;           // Default wind intensity
    x = 0.f;                         // Default X position
    y = 0.f;                         // Default Y position
    petal_color = sf::Color::Red;    // Default petal color
    center_color = sf::Color::Yellow;// Default center color
    stem_color = sf::Color::Green;   // Default stem color
    leaf_color = sf::Color::Green;   // Default leaf color

}

void Flower::draw(sf::RenderWindow& window) {

    // Draw center
    sf::CircleShape center(center_size); // Use center_size variable
    center.setPosition(400 - center_size, 300 - center_size); // Centering based on size
    center.setFillColor(center_color); // Use center_color variable
    window.draw(center);
    
    // petal drawing
    for (int i = 0; i < petal_num; ++i) 
    {
        sf::CircleShape petal(petal_size); 

        // position the petals
        petal.setPosition(400 + cos(i * 2 * 3.14 / petal_num) * 60 - petal_size, 300 + sin(i * 2 * 3.14 / petal_num) * 60 - petal_size);
        petal.setFillColor(petal_color); // Use petal_color variable
        window.draw(petal);
    }

    //draw stem
    sf::RectangleShape stem(sf::Vector2f(stem_size, 200)); // 200 is an example length; adjust as needed
    stem.setOrigin(stem_size / 2, 0); // Set origin to the middle of the top side for rotation
    stem.setPosition(400, 300 + center_size); // Positioning at the bottom of the center
    stem.setFillColor(stem_color);
    window.draw(stem);

}
