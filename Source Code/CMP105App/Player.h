#pragma once
#include "Entity.h"
#include"Framework/Animation.h"
class Player :public Entity
{
private:
	sf::Texture shipfly;
	Animation fly;
	int speed;
	int nrOfMultShot = 1;
	int damage;
public:
	Player();
	void update(float dt) override;
	void handleInput(float dt, sf::RenderWindow* window);
	//getters
	int getMultShotNr() { return nrOfMultShot; }
	int getDamage() { return damage; }
	//sets player basic attributes
	void restart(){
		alive = true;
		speed = 500;
		attackSpeed = 900;
		maxhealth = 300;
		health = 300;
		damage = 50;
		nrOfMultShot = 1;
	}
	//uprade functions
	void addDamage(int dmgadd) { damage += dmgadd; }
	void addMultshot() { nrOfMultShot++; }
	void maxhealthupgrade() { maxhealth += 50; health += 50; }
	void attackspeedupgrade() { attackSpeed = attackSpeed * 0.75; }
	void setcheatspeed() { speed = 3000; }
};

