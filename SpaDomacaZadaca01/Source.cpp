#include"Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "TELETABIJI");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	//sf::Music music;

	//if (!music.openFromFile("res/INeedADolar.ogg"))
	//{
	//	std::cout << "MANE ZIKE" << std::endl;
	//}
	//music.play();



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();
		
	
	}

	return 0;
}