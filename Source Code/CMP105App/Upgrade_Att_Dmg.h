#pragma once
#include "Framework/GameObject.h"
#include"Framework/Animation.h"
class Upgrade_Att_Dmg : public GameObject
{
private:
	sf::Texture texture;
	Animation basic;
public:
	Upgrade_Att_Dmg();
	void update(float dt) override;
};