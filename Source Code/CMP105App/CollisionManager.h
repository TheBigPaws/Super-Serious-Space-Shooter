#pragma once
#include "Framework/Collision.h"
#include "EntityManager.h"
#include "BulletManager.h"
#include "Player.h"
#include "Explosion.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"
class CollisionManager
{
private:
	Explosion explosionExample;
	std::vector<Explosion> explosions;
public:
	void addExlosion(GameObject* entity, AudioManager* audio);
	void checkcollisions(EntityManager* entitymanager, BulletManager* bulletmanager,Player* player, GameState* gamestate, AudioManager* audio);
	void updateExplosions(float dt);
	void renderExplosions(sf::RenderWindow* window);
};

