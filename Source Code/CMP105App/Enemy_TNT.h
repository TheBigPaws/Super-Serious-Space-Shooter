#pragma once
#include "Entity.h"
#include"Framework/Animation.h"
#include "Framework/Vector.h"
class Enemy_TNT : public Entity
{
public:
	Enemy_TNT();
	//movement
	void flytoPlayer(Entity* player,float dt);
private:
	sf::Texture spritesheet;
	sf::Vector2f direction;
	Animation fly;
	int speed;
};

