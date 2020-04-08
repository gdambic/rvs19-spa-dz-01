#include <SFML/Graphics.hpp>
#include "Cvijet.h"

using namespace sf;
using namespace std;



int main()
{

	RenderWindow window(VideoMode(800, 600), "Cvijetić");
	window.setFramerateLimit(60);

	Cvijet cvijet(window);
	cvijet.draw();

	return 0;
}