#pragma once
#include "Framework/GameObject.h"
#include "Upgrade_Att_Speed.h"
#include "Upgrade_Max_Hp.h"
#include "Upgrade_Att_Dmg.h"
#include "Upgrade_Shot_Nr.h"
#include "EntityManager.h"
class Screen_Upgrade : public GameObject
{
private:
	Upgrade_Att_Dmg attdmg;
	Upgrade_Max_Hp hpup;
	Upgrade_Att_Speed attspd;
	Upgrade_Shot_Nr shotnr;
	std::vector <sf::Text> text;
	sf::Font font;
	bool isset = false;
public:
	//font setter
	void setFont(sf::Font fontsetter) { font = fontsetter; }
	void Upgrade_Screen_Render(sf::RenderWindow* window);
	void Upgrade_Screen_Update(float dt);
};

