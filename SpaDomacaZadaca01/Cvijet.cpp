#include "Cvijet.h"
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow* window):wind(window)
{
}

void Cvijet::draw()
{
	srand(std::time(nullptr));
	time = clock.getElapsedTime();

	background();

	list();
	stabiljka();
	petals();
	core_cvijeta();
	oci();
	usne();

	munja();
	kisa();
	cloud();
	zemlja();

	if(time.asSeconds()>20)
	clock.restart();
}

float Cvijet::get_x_center()
{
	return wind->getSize().x/2.f;
}

float Cvijet::get_y_center()
{
	return wind->getSize().y / 2.f;
}

void Cvijet::background()
{
	sf::Color light_blue(110, 255, 255);

	//draw background
	back_ground.setSize(sf::Vector2f(800, 600));
	back_ground.setFillColor(light_blue);
	wind->draw(back_ground);
}

void Cvijet::list()
{
	//draw list
	sf::VertexArray List(sf::Lines, 2);

	sf::Color dark_green(0, 80, 0);

	for (int i = 0; i < size_list; i++) {
		List[0].color = dark_green;
		List[1].color = sf::Color::Green;
		if (time.asSeconds() > 9.15) {
			List[0].color=sf::Color(115, 115, 115);
			List[1].color = sf::Color(100, 100, 100);
		}
		if (i < smoother) {
			List[0].position = sf::Vector2f(get_x_center() - x_offset + i, get_y_center() + y_offset + sqrt(i) * 3.5+i/2);
			List[1].position = sf::Vector2f(get_x_center() - x_offset + i, get_y_center() + y_offset - sqrt(i) * 3.5+i / 2);
			wind->draw(List);

			List[0].position = sf::Vector2f(get_x_center() - x_offset + (size_list * 2 + 2) - i, get_y_center() + y_offset + sqrt(i) * 3.5+i / 2);
			List[1].position = sf::Vector2f(get_x_center() - x_offset + (size_list * 2 + 2) - i, get_y_center() + y_offset - sqrt(i) * 3.5+i / 2);
			wind->draw(List);
		}
		else {
			List[0].position = sf::Vector2f(get_x_center() - x_offset + i, get_y_center() + y_offset + sqrt(smoother) * 3.5+i / 2);
			List[1].position = sf::Vector2f(get_x_center() - x_offset + i, get_y_center() + y_offset - sqrt(smoother) * 3.5+i / 2);
			wind->draw(List);

			List[0].position = sf::Vector2f(get_x_center() - x_offset + (size_list * 2 + 2) - i, get_y_center() + y_offset + sqrt(smoother) * 3.5+i / 2);
			List[1].position = sf::Vector2f(get_x_center() - x_offset + (size_list * 2 + 2) - i, get_y_center() + y_offset - sqrt(smoother) * 3.5+i / 2);
			wind->draw(List);
		}
	}
}

void Cvijet::petals()
{
	// Draw petals around the center circle

	for (int i = 0; i < 12; ++i) {

		petal.setSize(sf::Vector2f(105.f, 28.5f));
		petal.setFillColor(sf::Color::Red);
		petal.setOutlineThickness(5);
		petal.setOutlineColor(sf::Color(205, 50, 150));
		petal.setPosition(get_y_center() + 100, get_y_center() + 60);

		float rotationAngle = i * (360.f / 12);
		petal.setRotation(rotationAngle);
		//petal.rotate(i * 30.f); prestalo radit kad sam prebacio u posebnu metodu??

		//animation for petal
		if (time.asSeconds() < 9.4) {
			float speed = 30.0f;
			float distance = speed * time.asSeconds();
			float ostatak = std::fmod(distance, 30);
			petal.rotate(ostatak);
		}

		if (time.asSeconds() > 9.15) {
				petal.setFillColor(sf::Color(125, 125, 125));
				petal.setOutlineColor(sf::Color(100, 100, 100));
		}
		wind->draw(petal);
	}
}

void Cvijet::stabiljka()
{
	//Stabiljka
	stabiljk.setSize(sf::Vector2f(450, 12));
	stabiljk.setFillColor(sf::Color::Green);
	stabiljk.setRotation(90);
	stabiljk.setPosition(get_x_center() + 5, get_y_center() + 60);
	if (time.asSeconds() > 9.15)
		stabiljk.setFillColor(sf::Color(125, 125, 125));
	wind->draw(stabiljk);
}

void Cvijet::core_cvijeta()
{
	//core cvijeta
	core.setRadius(52.5);
	core.setFillColor(sf::Color::Yellow);
	core.setPosition(get_x_center() - 52.5, get_y_center() + 10);
	core.setOutlineThickness(3);
	core.setOutlineColor(sf::Color(0, 0, 0));
	if (time.asSeconds() > 9.15)
		core.setFillColor(sf::Color(125, 125, 125));
	wind->draw(core);
}

void Cvijet::oci()
{
	//oci cvijeta
	sf::VertexArray eye(sf::Lines, 2); //ako stavim "eye" u Cvijet.h onda ovdje ne znam kako da mu dam PrimitiveType jer mi da samo jedan argument sa eye.setPrimitiveType
	eye[0].color = sf::Color::Black;
	eye[1].color = sf::Color::Black;
	x_ofset = -20;
	y_ofset = 40;

	for (int i = 0; i < 10; i++) {

		eye[0].position = sf::Vector2f(get_x_center() + x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + i);
		eye[1].position = sf::Vector2f(get_x_center() + x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + i);
		wind->draw(eye);

		eye[0].position = sf::Vector2f(get_x_center() + x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + 16 - i);
		eye[1].position = sf::Vector2f(get_x_center() + x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + 16 - i);
		wind->draw(eye);
	}

	x_ofset = 20;

	for (int i = 0; i < 10; i++) {


		eye[0].position = sf::Vector2f(get_x_center() + x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + i);
		eye[1].position = sf::Vector2f(get_x_center() + x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + i);
		wind->draw(eye);

		eye[0].position = sf::Vector2f(get_x_center() + x_ofset + sqrt(i) * 4, get_y_center() + y_ofset + 16 - i);
		eye[1].position = sf::Vector2f(get_x_center() + x_ofset - sqrt(i) * 4, get_y_center() + y_ofset + 16 - i);
		wind->draw(eye);
	}

}

void Cvijet::usne()
{
	//usne cvijeta
	sf::VertexArray lips(sf::Lines, 2); //isto ko i sa eye
	lips[0].color = sf::Color::Black;
	lips[1].color = sf::Color::Black;

	for (int i = 0; i < 50; i++) {

		lips[0].position = sf::Vector2f(get_x_center() - 20 + i, get_y_center() + 75);
		lips[1].position = sf::Vector2f(get_x_center() - 20 + i, get_y_center() + 81);
		wind->draw(lips);

	}
}

void Cvijet::kisa()
{
	//draw rain
	const int raindrops = 160;
	sf::RectangleShape* rain=new RectangleShape[raindrops]; //ne znam kako da ovo deklariram u headeru
	
	sf::Color dark_blue(78, 104, 129);

	if (time.asSeconds() > 5) {
		for (int i = 0; i < raindrops; i++) {

			rain[i].setSize(sf::Vector2f(3, 6));
			rain[i].setFillColor(dark_blue);

			float xPosition = get_x_center() + (rand() % (60 + 60)) - 60;
			float yPosition = 100;

			double speed = 0.0003;
			double distance = speed * (time.asMicroseconds() - 5000000);

			if (distance > i * 10) {
				rain[i].setPosition(sf::Vector2f(xPosition, yPosition));
				rain[i].move(0, distance - i * 10);	
			}
			wind->draw(rain[i]);
		}
	}
}

void Cvijet::cloud()
{
	//draw cloud
	cloud1.setSize(sf::Vector2f(150, 30));
	sf::Color cloud_blue(52, 204, 250);
	cloud1.setFillColor(sf::Color(82, 204, 255));
	cloud2.setRadius(35);
	cloud2.setFillColor(cloud_blue);
	cloud3.setRadius(40);
	cloud3.setFillColor(cloud_blue);
	cloud4.setRadius(40);
	cloud4.setFillColor(cloud_blue);
	cloud5.setRadius(35);
	cloud5.setFillColor(cloud_blue);

	double cloud_x = -100;
	int cloud_y = 80;

	cloud1.setPosition(sf::Vector2f(cloud_x, cloud_y));
	cloud2.setPosition(sf::Vector2f(cloud_x - 30, cloud_y - 40));
	cloud3.setPosition(sf::Vector2f(cloud_x + 20, cloud_y - 75));
	cloud4.setPosition(sf::Vector2f(cloud_x + 60, cloud_y - 70));
	cloud5.setPosition(sf::Vector2f(cloud_x + 120, cloud_y - 40));

	if (time.asSeconds() < 4.667) {
		double speed = 90.f;
		double distance = speed * (time.asSeconds());
		cloud1.move(distance, 0);
		cloud2.move(distance, 0);
		cloud3.move(distance, 0);
		cloud4.move(distance, 0);
		cloud5.move(distance, 0);
	}
	else if (time.asSeconds() < 13) {
		double speed = 60.f;
		double distance = speed * (7);
		cloud1.move(distance, 0);
		cloud2.move(distance, 0);
		cloud3.move(distance, 0);
		cloud4.move(distance, 0);
		cloud5.move(distance, 0);
	}
	else {
		double speed = 90.f;
		double distance = speed * (time.asSeconds() - 8.333);
		cloud1.move(distance, 0);
		cloud2.move(distance, 0);
		cloud3.move(distance, 0);
		cloud4.move(distance, 0);
		cloud5.move(distance, 0);
	}


	wind->draw(cloud1);
	wind->draw(cloud2);
	wind->draw(cloud3);
	wind->draw(cloud4);
	wind->draw(cloud5);
}

void Cvijet::zemlja()
{
	sf::Color light_green(110, 255, 55);
	sf::Color light_brown(123, 63, 0);

	//draw ground
	ground.setSize(sf::Vector2f(800, 50));
	ground.setFillColor(light_green);
	ground.setPosition(sf::Vector2f(0, 550));
	wind->draw(ground);

	ground2.setSize(sf::Vector2f(800, 35));
	ground2.setFillColor(light_brown);
	ground2.setPosition(sf::Vector2f(0, 565));
	wind->draw(ground2);
}

void Cvijet::munja()
{
	sf::Color ligtning_color(255,255,73);

	Lightning1.setPointCount(4);
	Lightning1.setPoint(0, sf::Vector2f(get_x_center(), 100));
	Lightning1.setPoint(1, sf::Vector2f(get_x_center()+10, 100));
	Lightning1.setPoint(2, sf::Vector2f(get_x_center()-8, 200));
	Lightning1.setPoint(3, sf::Vector2f(get_x_center()-15, 200));
	Lightning1.setFillColor(ligtning_color);
	
	Lightning2.setPointCount(4);
	Lightning2.setPoint(0, sf::Vector2f(get_x_center()-8, 200));
	Lightning2.setPoint(1, sf::Vector2f(get_x_center() + 30,195));
	Lightning2.setPoint(2, sf::Vector2f(get_x_center() +30, 180));
	Lightning2.setPoint(3, sf::Vector2f(get_x_center() +-8, 188));
	Lightning2.setFillColor(ligtning_color);

	Lightning3.setPointCount(3);
	Lightning3.setPoint(0, sf::Vector2f(get_x_center() +30, 195));
	Lightning3.setPoint(1, sf::Vector2f(get_x_center() + 20, 194));
	Lightning3.setPoint(2, sf::Vector2f(get_x_center(), 350));
	Lightning3.setFillColor(ligtning_color);
	
	if (time.asSeconds() > 9 && time.asSeconds() < 9.3) {

		wind->draw(Lightning1);
		wind->draw(Lightning2);
		wind->draw(Lightning3);
	}
}
