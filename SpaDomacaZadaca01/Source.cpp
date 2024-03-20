#include <SFML/Graphics.hpp>
#include "Flower.h"
#include "iostream"
using namespace std;

int main()
{

	
    Flower f;
	cout << "Welcome to the procedural flower generator!" << endl << endl;
	cout << "If you wish to change a specific setting, enter the number corresponding to the setting." << endl;
	cout << "After selecting a setting, you will be prompted to enter a new value." << endl;
	cout << "Once you are satisfied, type 10 to generate the flower, or 11 to exit without generating." << endl << endl;
	cout << "1. Center Size" << endl;
	cout << "2. Stem Length" << endl;
	cout << "3. Stem Width" << endl;
	cout << "4. Petal Count" << endl;
	cout << "5. Petal Size" << endl;
	cout << "6. Leaves Size" << endl;
	cout << "7. Leaves Amount" << endl;
	cout << "10. Generate Flower" << endl;
	cout << "11. Exit" << endl << endl;


	//menu for changing the settings
	while (true)
	{
		int userin = 10; //dynamic user input
		cin >> userin;
		if (userin == 1)
		{
			cout << "you selected Center Size: ";
			f.setCenterSize(f.readinput());
			cout << "the new value is: " << f.getCenterSize() << endl;
		}
		else if (userin == 2)
		{
			cout << "you selected Stem Length: ";
			f.setStemLenght(f.readinput());
			cout << "the new value is: " << f.getStemLenght() << endl;
		}
		else if (userin == 3)
		{
			cout << "you selected Stem Width: ";
			f.setStemWidth(f.readinput());
			cout << "the new value is: " << f.getStemWidth() << endl;
		}
		else if (userin == 4)
		{
			cout << "you selected Petal Count: ";
			f.setPetalNum(f.readinput());
			cout << "the new value is: " << f.getPetalNum() << endl;
		}
		else if (userin == 5)
		{
			cout << "you selected Petal Size: ";
			f.setPetalSize(f.readinput());
			cout << "the new value is: " << f.getPetalSize() << endl;
		}
		else if (userin == 6)
		{
			cout << "you selected Leaves Size: ";
			f.setLeafSize(f.readinput());
			cout << "the new value is: " << f.getLeafSize() << endl;
		}
		else if (userin == 7)
		{
			cout << "you selected Leaves Amount: ";
			f.setLeavesNum(f.readinput());
			cout << "the new value is: " << f.getLeavesNum() << endl;
		}
		else if (userin == 10)
		{
			break;
		}
		else if (userin == 11)
		{
			return 0;
		}
		else
		{
			cout << "Invalid input, please try again." << endl;
		
		}
	
	}

	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Procedural Flower Generator");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		f.draw(window); // Draw the flower
		window.display();
	}

	return 0;
}