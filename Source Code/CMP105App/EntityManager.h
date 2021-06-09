#pragma once
#include "Enemy_Ufo.h"
#include "Enemy_TNT.h"
#include "Enemy_Elon_Guard.h"
#include "Enemy_BOSS_Musk.h"
#include "Pickup_Heal.h"
#include "Pickup_Upgrade.h"
#include "Pickup_Shield.h"
#include "Shield.h"
class EntityManager
{
private:
	//score vars
	int score_int;
	sf::Text score;
	sf::Font font;

	//enemy vars
	std::vector <Enemy_Ufo> enemylist_UFO;
	std::vector <Enemy_TNT> enemylist_TNT;
	std::vector <Enemy_Elon_Guard> enemylist_Guard;
	std::vector <sf::RectangleShape> UFO_healthbars;
	std::vector <sf::RectangleShape> TNT_healthbars;
	std::vector <sf::RectangleShape> Guard_healthbars;
	Enemy_BOSS_Musk Boss;
	sf::RectangleShape Boss_HP;
	sf::Clock MuskStateClock;

	//player healthbar here for simplicity's sake
	sf::RectangleShape player_Healthbar;

	//pushback examples
	Enemy_Ufo Enemy_Ufo_example;
	Enemy_TNT Enemy_TNT_example;
	Enemy_Elon_Guard Enemy_Guard_example;

	//pickups
	Pickup_Heal heal;
	Pickup_Upgrade upgrade;
	Pickup_Shield shieldpckp;
	
	//shield itself
	Shield Pulse_Shield;
public:
	//Spawners
	void spawnUfo(sf::RenderWindow* window);
	void spawnTNT(sf::RenderWindow* window);
	void spawnGuard(sf::RenderWindow* window);
	void spawnWave(sf::RenderWindow* window, float difficulty);

	//Entity functions
	void updateAllEntities(float dt, Entity* player, sf::RenderWindow* window);
	void renderAllEntities(sf::RenderWindow* window);

	//Misc functions
	void playerHpBarSetup(Entity* player);
	void scoreSetup(sf::RenderWindow* window);
	void addscore(int add) { score_int += add; score.setString("SCORE: " + std::to_string(score_int));}

	//Boss Functions
	void spawnMusk(sf::RenderWindow* window, int difficulty);
	void updateMusk(float dt) { if (Boss.isAlive()) { Boss.update(dt); Boss_HP.setPosition(Boss.getPosition().x,Boss.getPosition().y-20); } }
	void renderMusk(sf::RenderWindow* window) { if (Boss.isAlive()) { window, window->draw(Boss); window->draw(Boss_HP); } }

	//getters
	bool isAllDead() { if (getsize_enemylist_Guard() + getsize_enemylist_TNT() + getsize_enemylist_UFO() > 0) { return false; } else { return true; } }
	int getsize_enemylist_UFO(){ return enemylist_UFO.size(); }
	int getsize_enemylist_TNT(){ return enemylist_TNT.size(); }
	int getsize_enemylist_Guard(){ return enemylist_Guard.size(); }
	Enemy_Ufo* get_enemylist_UFO(int a) { return &enemylist_UFO[a]; }
	Enemy_TNT* get_enemylist_TNT(int a) { return &enemylist_TNT[a]; }
	Enemy_Elon_Guard* get_enemylist_Guard(int a) { return &enemylist_Guard[a]; }
	Enemy_BOSS_Musk* get_Boss() { return &Boss; }
	sf::RectangleShape* get_healthbar_UFO(int a) { return &UFO_healthbars[a]; }
	sf::RectangleShape* get_healthbar_TNT(int a) { return &TNT_healthbars[a]; }
	sf::RectangleShape* get_healthbar_Guard(int a) { return &Guard_healthbars[a]; }
	sf::RectangleShape* get_healthbar_Player() { return &player_Healthbar; }
	sf::RectangleShape* get_healthbar_Musk() { return &Boss_HP; }
	Pickup_Heal* get_heal() { return &heal; }
	Pickup_Upgrade* get_upgrade() { return &upgrade; }
	Pickup_Shield* get_shield() {return &shieldpckp; }
	Shield* get_Pulse_Shield() { return &Pulse_Shield; }

	//deletefunctions
	void delete_enemylist_UFO(int a) { enemylist_UFO.erase(enemylist_UFO.begin() + a); }
	void delete_enemylist_TNT(int a) { enemylist_TNT.erase(enemylist_TNT.begin() + a); }
	void delete_enemylist_Guard(int a) { enemylist_Guard.erase(enemylist_Guard.begin() + a); }
	void delete_healthbars_UFO(int a) { UFO_healthbars.erase(UFO_healthbars.begin() + a); }
	void delete_healthbars_TNT(int a) { TNT_healthbars.erase(TNT_healthbars.begin() + a); }
	void delete_healthbars_Guard(int a) { Guard_healthbars.erase(Guard_healthbars.begin() + a); }
	void delete_EVERYTHING();
};

