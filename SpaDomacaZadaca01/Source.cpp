#include<iostream>
#include "Cvijet.h"
int main()
{
	Cvijet cvijet;
	
	while (cvijet.running())
	{
		cvijet.update();
		
		cvijet.render();

	}
	

	return 0;
}