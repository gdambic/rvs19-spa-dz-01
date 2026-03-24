#pragma once

#include <SFML/Graphics.hpp>

class Flower {
   private:
      sf::RenderWindow& _window;

   public:
      Flower(sf::RenderWindow& window);

      /**
       * Draws the flower to the window
       */
      void draw();
};