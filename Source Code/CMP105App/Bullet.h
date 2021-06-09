#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

//BULLET CLASS

class Bullet : public GameObject
{
public:
	//setter for attributes
	void isally(bool isally);
	//used for  aimed shots
	void setDirection(float xdir, float ydir);
	//used for shots where angle matters
	void setDirection(float angle);
	void update(float dt) override;
private:
	sf::Vector2f direction;
	sf::Texture textr;
	Animation normalState;
};

