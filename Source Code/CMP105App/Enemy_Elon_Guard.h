#pragma once
#include "Entity.h"
#include <vector>
#include"Framework/Animation.h"
class Enemy_Elon_Guard : public Entity
{
private:
	sf::Texture spritesheet;
	sf::Vector2f direction;
	Animation basic;
	Animation throwGranade;
	Animation currentAnimation;
	bool isSet = false;
	int hoverswitch = 1;
	int shootat;
	bool hasshot = false;
public:
	Enemy_Elon_Guard();
	//getters
	int get_shootat() { return shootat; }
	bool get_hasshot() { return hasshot; }
	//setters
	void set_hasshot(bool a) { hasshot = a; }
	//spawns, chooses a destination and a shoottime;
	void spawnAndSet(sf::RenderWindow* window);
	//movement
	void comeThenHover(float dt);
	//resets granade anim and sets it
	void setGranadeAnim() { throwGranade.setPlaying(true); throwGranade.reset(); currentAnimation = throwGranade; }
};

