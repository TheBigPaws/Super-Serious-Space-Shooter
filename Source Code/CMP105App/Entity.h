#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <iostream>
//base class for both player and enemies, has only a few basic attributes and functions

class Entity : public GameObject
{
protected:
	int maxhealth;
	int health;
	int attackSpeed;
	int goaldestination[2];
	bool isSet = false;
public:
	//getters
	int getAttackSpeed() { return attackSpeed;}
	int getHealth() { return health; }
	int getMaxHealth() { return maxhealth; }
	//setters
	void setHealth(int a) { health = a; }
	void setAttackSpeed(float attSpdToSet) { attackSpeed = attSpdToSet;}
	void setgoaldest(int a, int b) { goaldestination[0] = a, goaldestination[1] = b; }
	void dealDamage(int dmg) { health -= dmg; if (health <= 0) { alive = false; } }
};

