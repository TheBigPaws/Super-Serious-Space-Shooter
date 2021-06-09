#pragma once
#include "Entity.h"
#include "Framework/Animation.h"

enum class MuskState {FLY,CALLSUPPORT,SHOOTCAR,DEFEATED};
class Enemy_BOSS_Musk : public Entity
{
private:
	Animation fly;
	Animation callSupport;
	Animation shootCar;
	Animation defeated;
	Animation* currentAnimation;
	sf::Texture sprite;
	MuskState muskState = MuskState::FLY;
	int hoverswitch = 1;
public:
	Enemy_BOSS_Musk();
	void update(float dt) override;
	void reset(int difficulty);
	//movement
	void comeThenHover(float dt);
	//getter
	MuskState get_MuskState() { return muskState; }
	//setter
	void set_MuskState(MuskState s);
};

