#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Explosion : public GameObject
{
private:
	sf::Texture sprite;
	Animation explosion;
public:
	Explosion();
	void update(float dt) override;
	//getter
	bool getplaying() { return explosion.getPlaying(); }
};

