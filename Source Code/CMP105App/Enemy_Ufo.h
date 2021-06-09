#pragma once
#include "Entity.h"
class Enemy_Ufo : public Entity
{
private:
	sf::Texture sprite;
	sf::Vector2f direction;
	bool isSet = false;
	int hoverswitch = 1;
	int shootat;
	bool hasshot = false;
public:
	//getters
	int get_shootat() { return shootat; }
	bool get_hasshot() { return hasshot; }
	//setters
	void set_hasshot(bool a) { hasshot = a; }
	Enemy_Ufo();
	//spawns, chooses a destination and a shoottime;
	void spawnAndSet(sf::RenderWindow* window);
	//movement
	void comeThenHover(float dt);
};

