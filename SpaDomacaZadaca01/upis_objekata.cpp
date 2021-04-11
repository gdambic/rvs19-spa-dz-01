#include <iostream>
#include "upis_objekata.h"
#include "Cvijet.h"

void upis_sunca(Cvijet& cvijet)
{
	bool ponovi = false;
	float radijus, x, y;

	do {
		try
		{
			ponovi = false;

			std::cout << "** UPIS SUNCA **" << std::endl;
			std::cout << "Radijus: ";
			std::cin >> radijus;
			std::cout << "x koordinata: ";
			std::cin >> x;
			std::cout << "y koordinata: ";
			std::cin >> y;

			cvijet.set_radijus_sunca(radijus);
			cvijet.set_pozicija_sunca(x, y);
		}
		catch (const std::exception& error)
		{
			ponovi = true;
			std::cout << error.what() << std::endl;
		}
	} while (ponovi);
}

void upis_cvijeta(Cvijet& cvijet)
{
	bool ponovi = false;
	float radijus, x, y;

	do {
		try
		{
			ponovi = false;

			std::cout << std::endl << "** UPIS TUCKA **" << std::endl;
			std::cout << "Radijus: ";
			std::cin >> radijus;
			std::cout << "x koordinata: ";
			std::cin >> x;
			std::cout << "y koordinata: ";
			std::cin >> y;

			cvijet.set_pozicija_tucka(radijus, x, y);
			cvijet.set_radijus_tucka(radijus);
		}
		catch (const std::exception& error)
		{
			ponovi = true;
			std::cout << error.what() << std::endl;
		}
	} while (ponovi);
}