#pragma once
#include "Framework/GameObject.h"
#include"Framework/Animation.h"
#include "Framework/Vector.h"
class Granade : public GameObject
{
private:
	sf::Vector2f direction;
	sf::Texture textr;
	Animation blink;
	int explodeX;
	int explodeY;
public:
	Granade();
	void set_direction(GameObject* player);
	void flynrotate(float dt);
	int get_explodeX() { return explodeX; }
};

