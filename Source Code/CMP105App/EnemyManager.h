#pragma once
#include "Enemy_Ufo.h"
#include "Enemy_TNT.h"
#include "Enemy_Elon_Guard.h"
class EnemyManager 
{
private:
	int score_int = 0;
	sf::Text score;
	sf::Font font;
	std::vector <Enemy_Ufo> enemylist_UFO;
	std::vector <Enemy_TNT> enemylist_TNT;
	std::vector <Enemy_Elon_Guard> enemylist_Guard;

	std::vector <sf::RectangleShape> UFO_healthbars;
	std::vector <sf::RectangleShape> TNT_healthbars;
	std::vector <sf::RectangleShape> Guard_healthbars;

	sf::RectangleShape PlayerHealthBar;

	Enemy_Ufo Enemy_Ufo_example;
	Enemy_TNT Enemy_TNT_example;
	Enemy_Elon_Guard Enemy_Guard_example;

public:
	void spawnUfo(sf::RenderWindow* window);
	void spawnTNT(sf::RenderWindow* window);
	void spawnGuard(sf::RenderWindow* window);
	void updateAllEntities(float dt, Entity* player);
	void spawnWave(sf::RenderWindow* window, int difficulty);
	void renderAllEntities(sf::RenderWindow* window);
	void scoreSetup(sf::RenderWindow* window);
	void addscore(int add) { score_int += add; score.setString("SCORE: " + std::to_string(score_int));}

	//getters
	int getsize_enemylist_UFO(){ return enemylist_UFO.size(); }
	int getsize_enemylist_TNT(){ return enemylist_TNT.size(); }
	int getsize_enemylist_Guard(){ return enemylist_Guard.size(); }
	Enemy_Ufo* get_enemylist_UFO(int a) { return &enemylist_UFO[a]; }
	Enemy_TNT* get_enemylist_TNT(int a) { return &enemylist_TNT[a]; }
	Enemy_Elon_Guard* get_enemylist_Guard(int a) { return &enemylist_Guard[a]; }
	sf::RectangleShape* get_healthbar_UFO(int a) { return &UFO_healthbars[a]; }
	sf::RectangleShape* get_healthbar_TNT(int a) { return &TNT_healthbars[a]; }
	sf::RectangleShape* get_healthbar_Guard(int a) { return &Guard_healthbars[a]; }

	//deletefunctions
	void delete_enemylist_UFO(int a) { enemylist_UFO.erase(enemylist_UFO.begin() + a); }
	void delete_enemylist_TNT(int a) { enemylist_TNT.erase(enemylist_TNT.begin() + a); }
	void delete_enemylist_Guard(int a) { enemylist_Guard.erase(enemylist_Guard.begin() + a); }
	void delete_healthbars_UFO(int a) { UFO_healthbars.erase(UFO_healthbars.begin() + a); }
	void delete_healthbars_TNT(int a) { TNT_healthbars.erase(TNT_healthbars.begin() + a); }
	void delete_healthbars_Guard(int a) { Guard_healthbars.erase(Guard_healthbars.begin() + a); }
};

