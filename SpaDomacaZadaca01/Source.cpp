#include "Animation.h"
#include "Objects.h"

using namespace sf;
using namespace std;

//all pixelArt is created by me

//Ovo je treca iteracija...the most crude one. nažalost u prve dvije i bit more then I could chew.
//Bilo je puno više razgranatije (sve je imalo svoj dio), ali iskostvo se pokazalo da nece iæi. 
//Previše vremena sam potrošio na prve dvije iteracije (barem sam dosta naucio), tako da kad sam vidio da necu mmoci to završiti na vrijeme. 
//uzeo sam sve najvažnije i (zadnji dan) plopo ovdje. Žao mi je da nisam završio što sam htio.
//i da ponovo radim, sad vidim o cemu bi trebo razmišljat da bude što više optimiziranije i lakše.
int main()
{
	//by changing these integers, scene will change... might not look nice
	int render_PinkTulip_Number = 18;
	int render_BlueTulip_Number = 100;
	int render_YellowTulip_Number = 20;
	int render_OrangeTulip_Number = 30;
	int render_Windmill_Number = 4;

	sf::RenderWindow window(sf::VideoMode(512, 320), "Netherlands meet a pixel! ");
	window.setFramerateLimit(60);
	
	//buffers for textures
	vector<Texture*> textureTULIP_Vector;
	vector<Texture*> textureVector;

	//getting and saving textures SCENE
	Texture windmill_Texture,ground_Texture,sky_Texture;

	windmill_Texture.loadFromFile("Windmill.png");
	textureVector.push_back(&windmill_Texture);

	ground_Texture.loadFromFile("ground.png");
	textureVector.push_back(&ground_Texture);

	sky_Texture.loadFromFile("sky.png");
	textureVector.push_back(&sky_Texture);
	



	
	//getting and saving textures TULIPS	//ovo bi sve volio staviti u poseban dio, ali texture se
											//nemogu kopirati, a ne znam kako da ih spremim da ih 
											//destruktor ne uništi prije nego što treba
	Texture pinkTulip_Texture, blueTulip_Texture, yellowTulip_Texture, orangeTulip_Texture;

	pinkTulip_Texture.loadFromFile("Pink_Tulip_Row.png");
	textureTULIP_Vector.push_back(&pinkTulip_Texture);

	blueTulip_Texture.loadFromFile("Blue_Tulip.png");
	textureTULIP_Vector.push_back(&blueTulip_Texture);

	yellowTulip_Texture.loadFromFile("Yellow_Tulip.png");
	textureTULIP_Vector.push_back(&yellowTulip_Texture);

	orangeTulip_Texture.loadFromFile("Orange_Tulip.png");
	textureTULIP_Vector.push_back(&orangeTulip_Texture);
	
	//animating tulips //sending textures, instructing a mathod how to cut sprites, speed of animation)
	Animation pinkTulip_Animation(textureTULIP_Vector[0], Vector2u(2, 1), 0.7f);
	Animation blueTulip_Animation(textureTULIP_Vector[1], Vector2u(2, 1), 0.5f);
	Animation yellowTulip_Animation(textureTULIP_Vector[2], Vector2u(2, 1), 0.6f);
	Animation orangeTulip_Animation(textureTULIP_Vector[3], Vector2u(2, 1), 0.8f);
	
	//getting settings from Object class
	Objects pinkTulipObject, blueTulipObject, yellowTulipObject, orangeTulipObject,groundObject,skyObject,windmillObject;
	vector<RectangleShape> tulipsPink = pinkTulipObject.Tulip(textureTULIP_Vector, 17 , 0 , render_PinkTulip_Number,0);
	vector<RectangleShape> tulipsBlue = blueTulipObject.Tulip(textureTULIP_Vector, 13 , -10 , render_BlueTulip_Number,1);
	vector<RectangleShape> tulipsYellow = yellowTulipObject.Tulip(textureTULIP_Vector, 21, -4 , render_YellowTulip_Number,2);
	vector<RectangleShape> tulipsOrange = orangeTulipObject.Tulip(textureTULIP_Vector, 25 , -6 , render_OrangeTulip_Number,3);
	
	
	//building and animating a scene 
	vector<RectangleShape> windmill_Body = windmillObject.Windmill_body(textureVector, 0.6f, render_Windmill_Number, 0);
	Animation windmill_Animation(textureVector[0], Vector2u(2, 1), 1.2f);

	RectangleShape ground = groundObject.Ground(textureVector, 1);
	RectangleShape sky = skyObject.Sky(textureVector, 2);

	
	
	float deltaTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			
				
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				cout << "ljevi klick" << endl;
				
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		pinkTulip_Animation.Update(0, deltaTime);
		blueTulip_Animation.Update(0, deltaTime);
		yellowTulip_Animation.Update(0, deltaTime);
		orangeTulip_Animation.Update(0, deltaTime);
		windmill_Animation.Update(0, deltaTime);


		window.clear();
		//cvijet.draw(); //one cvijet wasnt enough
		window.draw(sky);
		for (int i = 0; i < render_Windmill_Number; i++)
		{
			windmill_Body[i].setTextureRect(windmill_Animation.uvRect);
			window.draw(windmill_Body[i]);
		}

		//blue rows
		for (unsigned i = 0; i < render_BlueTulip_Number; i++)
		{
			tulipsBlue[i].setTextureRect(blueTulip_Animation.uvRect);
			window.draw(tulipsBlue[i]);

		}
		//yellow rows
		for (unsigned i = 0; i < render_YellowTulip_Number; i++)
		{
			tulipsYellow[i].setTextureRect(yellowTulip_Animation.uvRect);
			window.draw(tulipsYellow[i]);

		}
		//orange rows
		for (unsigned i = 0; i < render_OrangeTulip_Number; i++)
		{
			tulipsOrange[i].setTextureRect(orangeTulip_Animation.uvRect);
			window.draw(tulipsOrange[i]);
		}
		//pink rows
		for (unsigned i = 0; i < render_PinkTulip_Number; i++)
		{
		tulipsPink[i].setTextureRect(pinkTulip_Animation.uvRect);
			window.draw(tulipsPink[i]);

		}


		window.draw(ground);
		window.display();
		
	}

	return 0;
}