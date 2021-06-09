#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Shield : public GameObject
{
private:
	sf::Texture texture;
	Animation basic;
public:
	void update(float dt) override;
	Shield();
};

