#pragma once
#include "Framework/GameObject.h"
#include"Framework/Animation.h"
class Upgrade_Shot_Nr : public GameObject
{
private:
	sf::Texture texture;
	Animation basic;
public:
	Upgrade_Shot_Nr();
	void update(float dt) override;
};
