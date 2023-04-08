#include "Cvijet.h"
#include <vector>
#include <iostream>
#include <sstream>

int main() {


#pragma region Glavni zadatak
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!"); // VideoMode(800, 600) (1920, 1080) (3840, 2160)
    window.setFramerateLimit(60);

    Cvijet cvijet(&window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << "Petels coordinnates: " << std::endl;
        std::cout << "Pet1 : (x= " << cvijet.get_pet1_x() << ", " << "y= " << cvijet.get_pet1_y() << ")" << std::endl;
        std::cout << "Pet2 : (x= " << cvijet.get_pet2_x() << ", " << "y= " << cvijet.get_pet2_y() << ")" << std::endl;
        std::cout << "Pet3 : (x= " << cvijet.get_pet3_x() << ", " << "y= " << cvijet.get_pet3_y() << ")" << std::endl;
        std::cout << "Pet4 : (x= " << cvijet.get_pet4_x() << ", " << "y= " << cvijet.get_pet4_y() << ")" << std::endl;
        std::cout << std::endl;

        cvijet.update_screen();
        cvijet.animate_sun();
        cvijet.animate_leaf();
        cvijet.animate_petals(cvijet.get_pet1p(), cvijet.get_pet2p(), cvijet.get_pet3p(), cvijet.get_pet4p());
        window.display();
    }
    
#pragma endregion


	return 0;
}