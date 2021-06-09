#pragma once
#include "Bullet.h"
#include <vector>
#include "Player.h"
#include "EntityManager.h"
#include "Car.h"
#include "Granade.h"
#include "Framework/AudioManager.h"
class BulletManager
{
private:
	std::vector<Bullet> playerBullets;
	std::vector<Bullet> enemyBullets;
	std::vector<Granade> Granades;
	Granade granadeexample;
	Bullet allybulletexampl;
	Bullet enemybulletexampl;
	Car car;
	sf::Clock playershotclock;
	sf::Clock enemyshotclock;
	sf::Clock muskshotclock;
	sf::RectangleShape carHP;
	bool CarFlipper = false;
public:
	BulletManager();
	void update(float dt, sf::RenderWindow* window);
	void bulletsRender(sf::RenderWindow* window);

	//spawn functions
	void spawnUFObullets(Enemy_Ufo* ufo);
	void spawnBullets(EntityManager* enttmanag, Player* player, AudioManager* audio);
	void spawnGranadeOnGuard(Enemy_Elon_Guard* guard, Player* player);
	void spawnGuardbullets(Enemy_Elon_Guard* guard);

	//getters
	int getsize_enemyBullets() { return enemyBullets.size(); }
	int getsize_playerBullets() { return playerBullets.size(); }
	int getsize_granades() { return Granades.size(); }
	void setcarflip(bool a) { CarFlipper = a; }
	Bullet* get_playerbullet(int a) { return &playerBullets[a]; }
	Bullet* get_playerbullet_example() { return &allybulletexampl;; }
	Bullet* get_enemybullet(int a) { return &enemyBullets[a]; }
	Granade* get_granade(int a) { return &Granades[a]; }
	Car* get_car() { return &car; }
	sf::RectangleShape* get_carHP() { return &carHP; }

	//deletefunctions
	void delete_granade(int a) { Granades.erase(Granades.begin() + a); }
	void delete_playerbullet(int a) { playerBullets.erase(playerBullets.begin() + a); }
	void delete_enemyBullets(int a) { enemyBullets.erase(enemyBullets.begin() + a); }
	void delete_EVERYTHING() { playerBullets.clear(); enemyBullets.clear(); Granades.clear(); }
};

