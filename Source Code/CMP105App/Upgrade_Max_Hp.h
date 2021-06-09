#pragma once
#include "Framework/GameObject.h"
#include"Framework/Animation.h"
class Upgrade_Max_Hp : public GameObject
{
private:
	sf::Texture texture;
	Animation basic;
public:
	Upgrade_Max_Hp();
	void update(float dt) override;
};
