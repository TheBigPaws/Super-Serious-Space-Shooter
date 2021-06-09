#include "Enemy_BOSS_Musk.h"

Enemy_BOSS_Musk::Enemy_BOSS_Musk() {
	alive = false;
	sprite.loadFromFile("gfx/sprites/Enemy_Boss_Musk.png");
	setTexture(&sprite);
	for(int i = 0; i < 26; i++) {
		if (i < 6) { fly.addFrame(sf::IntRect(i*170,0,170,194)); }
		else if(i < 10) { shootCar.addFrame(sf::IntRect(i * 170, 0, 170, 194)); }
		else if(i < 24) {callSupport.addFrame(sf::IntRect(i * 170, 0, 170, 194));}
		else{defeated.addFrame(sf::IntRect(i * 170, 0, 170, 194));}
	}
	fly.setFrameSpeed(0.1);
	shootCar.setFrameSpeed(0.1);
	callSupport.setFrameSpeed(0.1);
	defeated.setFrameSpeed(0.1);
	currentAnimation = &fly;
	callSupport.setLooping(false);
	shootCar.setLooping(false);
	setSize(sf::Vector2f(4*170, 4*194));
	setCollider(true);
	setCollisionBox(340, 0, 2 * 170, 4* 194);
}

void Enemy_BOSS_Musk::update(float dt) {
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	if (currentAnimation->getPlaying() == false) { currentAnimation = &fly; muskState = MuskState::FLY; }
}

void Enemy_BOSS_Musk::set_MuskState(MuskState s) {
	muskState = s;
	switch (get_MuskState()) {
	case(MuskState::CALLSUPPORT) :
		callSupport.setPlaying(true);
		callSupport.reset();
		currentAnimation = &callSupport;
	break;

	case(MuskState::SHOOTCAR):
		shootCar.setPlaying(true);
		shootCar.reset();
		currentAnimation = &shootCar;
	break;

	case(MuskState::DEFEATED):
		currentAnimation = &defeated;
		setCollider(false);
	break;
	}
}

void Enemy_BOSS_Musk::reset(int difficulty) {
	setCollider(true);
	isSet = false;
	health = 1000 * difficulty;
	maxhealth = health;
	if (difficulty < 8) {
		attackSpeed = (11 - difficulty) * 100;
	}
	else { attackSpeed = 300; }
	currentAnimation = &fly;
	alive = true;
}

//movement
void Enemy_BOSS_Musk::comeThenHover(float dt) {
	if (getPosition().y >= goaldestination[1] + 10) { hoverswitch = -1; }
	else if (getPosition().y < goaldestination[1]) { hoverswitch = 1; }
	move(0, hoverswitch * 20 * dt);
	if (isSet == false) {
		move(-250 * dt,0);
		if (getPosition().x <= goaldestination[0]) { isSet = true; }
	}
}
