#include <SFML/Graphics.hpp>
#include <iostream>

#include "main.hh"
#include "Flower.hh"

int main() {
   sf::RenderWindow window(sf::VideoMode({800, 600}), "Flower", (sf::Style::Close | sf::Style::Titlebar));
   window.setFramerateLimit(60);
   Flower flower(window);

   sf::Clock clock = sf::Clock();
   float previousX = 0.f;
   int direction = 1;

   #pragma mark - Bee Setup
   float horizontalAmplitude = 150.0f;
   float horizontalSpeed = 0.8f;
   float verticalAmplitude = 25.0f;
   float verticalSpeed = 0.8f * 2;
   int imageWidth = 529;
   int imageHeight = 395;
   int beeStartingX = window.getSize().x - ((imageWidth * 0.25) + 20);
   int beeStartingY = 120;
   sf::Texture beeTexture("bee.png", false, sf::IntRect({0, 0}, {imageWidth, imageHeight}));
   beeTexture.setSmooth(true);
   sf::Sprite beeSprite = sf::Sprite(beeTexture);
   beeSprite.setScale({-0.25f, 0.25f});
   beeSprite.setOrigin({float(beeTexture.getSize().x), 0});
   
   while (window.isOpen()) {
      while (const std::optional event = window.pollEvent()) {
         if (event->is<sf::Event::Closed>()) window.close();
      }

      window.clear(sf::Color(83, 234, 253));

      #pragma mark - Scene
      sf::Color grass = sf::Color(100, 200, 100);
      sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(window.getSize().x, 200));
      rectangle.setFillColor(grass);
      rectangle.setPosition(sf::Vector2f(0, window.getSize().y - 200));
      window.draw(rectangle);

      #pragma mark - Flower
      flower.draw();

      #pragma mark - Animated Bee
      float elapsedTime = clock.getElapsedTime().asSeconds();
      // If the bee gets to the end then flip it around
      float currentX = std::sin(elapsedTime * horizontalSpeed) * horizontalAmplitude;
      float currentY = std::sin(elapsedTime * verticalSpeed) * verticalAmplitude;

      // Check if direction changed
      int newDirection = (currentX > previousX) ? 1 : -1;
      if (newDirection != direction) {
         direction = newDirection;
         if (direction == 1) {
            // Moving right
            beeSprite.setScale({-0.25f, 0.25f});
            beeSprite.setOrigin({float(beeTexture.getSize().x), 0});
         } else {
            // Moving left
            beeSprite.setScale({0.25f, 0.25f});
            beeSprite.setOrigin({0, 0});
         }
      }

      // Update position and previousX
      beeSprite.setPosition(sf::Vector2f((beeStartingX - horizontalAmplitude) + currentX, (beeStartingY - verticalAmplitude) + currentY));
      previousX = currentX;

      window.draw(beeSprite);

      window.display();
   }
}