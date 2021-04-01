#include "Cvijet.h"
#include <cmath>
#include <iostream>

void Cvijet::draw(sf::Time vrijeme) {
	InicijalizirajKoordinate();
	InicijalizirajBoje();

	shape_latica1.setFillColor(boja_latica1);
	shape_latica2.setFillColor(boja_latica2);
	shape_latica3.setFillColor(boja_latica3);
	shape_latica4.setFillColor(boja_latica4);
	shape_stabljika.setFillColor(boja_stabljika);
	shape_listL.setFillColor(boja_listL);
	shape_listR.setFillColor(boja_listR);

	Cvijet::Animacija(vrijeme);
	window->clear(sf::Color(17, 91, 38));

	sf::RectangleShape nebo(sf::Vector2f(window->getSize().x, window->getSize().y / 2));
	nebo.setFillColor(sf::Color(153, 217, 234));
	nebo.setPosition(sf::Vector2f(0,0));
	window->draw(nebo);

	// redoslijed je namjeran (prvo crtamo objekte koji su dalje od nas)
	window->draw(shape_listL);
	window->draw(shape_stabljika);
	window->draw(shape_latica4);
	window->draw(shape_latica3);
	window->draw(shape_latica2);
	window->draw(shape_latica1);
	window->draw(shape_listR);
}

Tocka Cvijet::IzracunajAnimaciju(int x, int y, float swing_speed, float swing_step, int swing_cutoff, sf::Time vrijeme) {
	
	if (y > swing_cutoff) {
		return Tocka(x, y);
	}

	Tocka tocka(x, y);
	float vrijeme_sec = vrijeme.asSeconds();

	// translatiraj tocku tako da je centar rotacije u (0,0)
	tocka = Tocka(tocka.x - window->getSize().x / 2, tocka.y - swing_cutoff);

	// rotiraj tocku i primjeni efekt
	tocka.x =
		  tocka.x * std::cos(sin(swing_speed * vrijeme_sec) * tocka.y / 10000 * swing_step)
		- tocka.y * std::sin(sin(swing_speed * vrijeme_sec) * tocka.y / 10000 * swing_step);
	tocka.y =
		  tocka.y * std::cos(sin(swing_speed * vrijeme_sec) * tocka.y / 10000 * swing_step)
		+ tocka.x * std::sin(sin(swing_speed * vrijeme_sec) * tocka.y / 10000 * swing_step);

	// vrati tocku na prethodno mjesto
	tocka = Tocka(tocka.x + window->getSize().x / 2, tocka.y + swing_cutoff);

	return tocka;
}

void Cvijet::Animacija(sf::Time vrijeme) {

	// parametri - mogu se mijenjati
	float swing_speed = 1.3;		// kolika je brzina njihanja cvijeta i stabljike

	float swing_speed_list = -0.9;	// kolika je brzina njihanja listova
	
	float swing_step = 1;			// koliko se njihanje poveca po redu piksela
									// (u praksi jacina njihanja)
	
	int swing_cutoff = 400;			// najnizi red koji ce se njihati, ujedno i
									// red u kojem je srediste njihanja

	int offset_x = 160;				// za koliko piksela pomaknuti cvijet po X koordinati




	// Ne svidja mi se ovaj kod ispod...
	Tocka tocka;

	shape_latica1.setPointCount(tocka_latica1.size());
	for (int i = 0; i < tocka_latica1.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_latica1[i].x, tocka_latica1[i].y, swing_speed, swing_step, swing_cutoff, vrijeme);
		shape_latica1.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}

	shape_latica2.setPointCount(tocka_latica2.size());
	for (int i = 0; i < tocka_latica2.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_latica2[i].x, tocka_latica2[i].y, swing_speed, swing_step, swing_cutoff, vrijeme);
		shape_latica2.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}

	shape_latica3.setPointCount(tocka_latica3.size());
	for (int i = 0; i < tocka_latica3.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_latica3[i].x, tocka_latica3[i].y, swing_speed, swing_step, swing_cutoff, vrijeme);
		shape_latica3.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}
	
	shape_latica4.setPointCount(tocka_latica4.size());
	for (int i = 0; i < tocka_latica4.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_latica4[i].x, tocka_latica4[i].y, swing_speed, swing_step, swing_cutoff, vrijeme);
		shape_latica4.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}

	shape_stabljika.setPointCount(tocka_stabljika.size());
	for (int i = 0; i < tocka_stabljika.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_stabljika[i].x, tocka_stabljika[i].y, swing_speed, swing_step, swing_cutoff, vrijeme);
		shape_stabljika.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}
	
	shape_listL.setPointCount(tocka_listL.size());
	for (int i = 0; i < tocka_listL.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_listL[i].x, tocka_listL[i].y, swing_speed_list, swing_step, swing_cutoff, vrijeme);
		shape_listL.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}

	shape_listR.setPointCount(tocka_listR.size());
	for (int i = 0; i < tocka_listR.size(); i++) {
		tocka = IzracunajAnimaciju(tocka_listR[i].x, tocka_listR[i].y, swing_speed_list, swing_step, swing_cutoff, vrijeme);
		shape_listR.setPoint(i, sf::Vector2f(tocka.x + offset_x, tocka.y));
	}
}

void Cvijet::InicijalizirajBoje() {
	boja_latica1	= sf::Color(171, 0, 195);
	boja_latica2	= sf::Color(239, 137, 253);
	boja_latica3	= sf::Color(243, 197, 249);
	boja_latica4	= sf::Color(198, 114, 210);
	boja_stabljika	= sf::Color(21, 145, 47);
	boja_listL		= sf::Color(9, 49, 17);
	boja_listR		= sf::Color(9, 49, 17);
}

void Cvijet::InicijalizirajKoordinate() {
	// Mogao sam to rijesiti na bolji nacin (na primjer citati ih iz datoteke), ali i ovo ce posluziti.
	// Barem sam imao priliku iskoristiti Python za automatizaciju :D

	// Takodjer, zelio bih zahvaliti svojem prijatelju za crtez tulipana po kojem je napravljen ovaj cvijet.

	tocka_latica1 = {
		Tocka(215,259),
		Tocka(217,255),
		Tocka(218,252),
		Tocka(218,248),
		Tocka(218,244),
		Tocka(217,241),
		Tocka(216,236),
		Tocka(215,230),
		Tocka(212,222),
		Tocka(207,211),
		Tocka(200,197),
		Tocka(189,181),
		Tocka(176,168),
		Tocka(166,156),
		Tocka(153,146),
		Tocka(145,140),
		Tocka(133,134),
		Tocka(120,129),
		Tocka(111,126),
		Tocka(106,126),
		Tocka(99,126),
		Tocka(98,146),
		Tocka(99,158),
		Tocka(100,171),
		Tocka(101,181),
		Tocka(105,193),
		Tocka(109,202),
		Tocka(112,211),
		Tocka(116,219),
		Tocka(120,228),
		Tocka(125,235),
		Tocka(129,240),
		Tocka(134,246),
		Tocka(139,251),
		Tocka(143,255),
		Tocka(147,258),
		Tocka(153,263),
		Tocka(159,267),
		Tocka(165,270),
		Tocka(170,273),
		Tocka(174,275),
		Tocka(179,277),
		Tocka(184,278),
		Tocka(188,279),
		Tocka(193,279),
		Tocka(198,279),
		Tocka(203,278),
		Tocka(208,276),
		Tocka(211,274)
	};

	tocka_latica2 = {
		Tocka(126,129),
		Tocka(128,116),
		Tocka(129,107),
		Tocka(131,101),
		Tocka(133,95),
		Tocka(136,90),
		Tocka(136,92),
		Tocka(138,94),
		Tocka(141,97),
		Tocka(145,100),
		Tocka(150,104),
		Tocka(157,107),
		Tocka(163,111),
		Tocka(169,114),
		Tocka(180,123),
		Tocka(190,132),
		Tocka(199,142),
		Tocka(206,152),
		Tocka(213,164),
		Tocka(221,178),
		Tocka(227,191),
		Tocka(232,204),
		Tocka(235,215),
		Tocka(236,226),
		Tocka(236,239),
		Tocka(234,249),
		Tocka(230,259),
		Tocka(228,263),
		Tocka(211,274)
	};

	tocka_latica3 = {
		Tocka(111,118),
		Tocka(101,113),
		Tocka(97,113),
		Tocka(88,113),
		Tocka(82,114),
		Tocka(78,115),
		Tocka(79,134),
		Tocka(80,142),
		Tocka(82,153),
		Tocka(88,165),
		Tocka(95,179),
		Tocka(102,191),
		Tocka(106,197),
		Tocka(144,142)
	};

	tocka_latica4 = {
		Tocka(102,119),
		Tocka(105,128),
		Tocka(111,135),
		Tocka(120,138),
		Tocka(129,137),
		Tocka(137,128),
		Tocka(136,118),
		Tocka(133,104),
		Tocka(130,98),
		Tocka(125,96),
		Tocka(117,94),
		Tocka(107,92),
		Tocka(104,97),
		Tocka(102,104),
		Tocka(101,112)
	};

	tocka_stabljika = {
		Tocka(228,263),
		Tocka(232,267),
		Tocka(237,276),
		Tocka(243,288),
		Tocka(251,305),
		Tocka(255,315),
		Tocka(258,328),
		Tocka(260,338),
		Tocka(261,344),
		Tocka(262,358),
		Tocka(242,450),
		Tocka(237,454),
		Tocka(226,456),
		Tocka(214,455),
		Tocka(210,453),
		Tocka(210,447),
		Tocka(212,433),
		Tocka(214,425),
		Tocka(217,414),
		Tocka(220,401),
		Tocka(222,386),
		Tocka(223,364),
		Tocka(222,350),
		Tocka(221,335),
		Tocka(219,320),
		Tocka(218,308),
		Tocka(217,303),
		Tocka(212,293),
		Tocka(207,286),
		Tocka(200,278)
	};

	tocka_listR = {
		Tocka(259,462),
		Tocka(266,462),
		Tocka(277,460),
		Tocka(292,457),
		Tocka(311,449),
		Tocka(327,438),
		Tocka(337,430),
		Tocka(345,419),
		Tocka(356,399),
		Tocka(364,376),
		Tocka(368,357),
		Tocka(368,338),
		Tocka(367,326),
		Tocka(365,310),
		Tocka(361,294),
		Tocka(356,282),
		Tocka(347,268),
		Tocka(332,248),
		Tocka(318,233),
		Tocka(301,221),
		Tocka(283,211),
		Tocka(269,207),
		Tocka(254,204),
		Tocka(261,209),
		Tocka(271,218),
		Tocka(280,227),
		Tocka(285,236),
		Tocka(288,245),
		Tocka(291,259),
		Tocka(292,276),
		Tocka(292,292),
		Tocka(291,305),
		Tocka(289,312),
		Tocka(287,320),
		Tocka(282,329),
		Tocka(277,338),
		Tocka(269,347),
		Tocka(261,356),
		Tocka(254,366),
		Tocka(246,381),
		Tocka(242,397),
		Tocka(239,414),
		Tocka(236,431),
		Tocka(237,447),
		Tocka(238,452),
		Tocka(241,458),
		Tocka(244,460),
		Tocka(248,461)
	};

	tocka_listL = {
		Tocka(221,381),
		Tocka(217,375),
		Tocka(212,366),
		Tocka(204,359),
		Tocka(196,352),
		Tocka(180,341),
		Tocka(168,333),
		Tocka(157,324),
		Tocka(147,314),
		Tocka(139,303),
		Tocka(135,294),
		Tocka(134,286),
		Tocka(133,275),
		Tocka(131,286),
		Tocka(131,302),
		Tocka(132,322),
		Tocka(134,339),
		Tocka(137,363),
		Tocka(144,390),
		Tocka(149,403),
		Tocka(158,419),
		Tocka(165,429),
		Tocka(172,437),
		Tocka(181,443),
		Tocka(189,448),
		Tocka(193,450),
		Tocka(199,451),
		Tocka(204,452),
		Tocka(208,452),
		Tocka(211,451)
	};
}
