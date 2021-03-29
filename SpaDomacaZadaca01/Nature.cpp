#include <iostream>
#include <SFML/Graphics.hpp>
#include "Nature.h"

using namespace sf;

Nature::Nature(RenderWindow* window) : renderWindow(window)
{
	sky.set_sky("assets/sky.jpg");
	flower.set_flower("assets/flower.png");
	butterfly.set_butterfly("assets/butterfly.png");
	grass.set_grass("assets/grass.png");
	sun.set_sun("assets/sun.png");
	clouds.set_clouds("assets/clouds.png");
}

void Nature::render()
{
	renderWindow->draw(sky.get_sky_sprite());
	renderWindow->draw(flower.get_flower_sprite());
	renderWindow->draw(butterfly.animate());
	renderWindow->draw(grass.get_grass_sprite());
	renderWindow->draw(sun.get_sun_sprite());
	renderWindow->draw(clouds.animate());
}
