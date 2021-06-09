#include "EntityManager.h"

void EntityManager::scoreSetup(sf::RenderWindow* window) {
	font.loadFromFile("font/slkscr.ttf");
	score.setFont(font);
	score.setPosition(window->getSize().x / 2 - 100, 80);
	score.setCharacterSize(50);
	score.setString("SCORE: " + std::to_string(score_int));
	score.setOutlineColor(sf::Color::Black);
	score.setOutlineThickness(2);
}

void EntityManager::updateAllEntities(float dt, Entity* player) {
	for (int i = 0; i < enemylist_UFO.size(); i++) {
		enemylist_UFO[i].comeThenHover(dt);
		UFO_healthbars[i].setPosition(enemylist_UFO[i].getPosition().x, enemylist_UFO[i].getPosition().y - 20);
	}
	for (int i = 0; i < enemylist_TNT.size(); i++) {
		enemylist_TNT[i].flytoPlayer(player, dt);
		TNT_healthbars[i].setPosition(enemylist_TNT[i].getPosition().x, enemylist_TNT[i].getPosition().y - 20);;
	}
	for (int i = 0; i < enemylist_Guard.size(); i++) {
		enemylist_Guard[i].comeThenHover(dt);
		Guard_healthbars[i].setPosition(enemylist_Guard[i].getPosition().x, enemylist_Guard[i].getPosition().y - 20);
	}
}

void EntityManager::spawnUfo(sf::RenderWindow* window) {
	enemylist_UFO.push_back(Enemy_Ufo_example);
	enemylist_UFO[enemylist_UFO.size() - 1].spawnAndSet(window);

	UFO_healthbars.push_back(sf::RectangleShape());
	UFO_healthbars[UFO_healthbars.size() - 1].setFillColor(sf::Color::Green);
	UFO_healthbars[UFO_healthbars.size() - 1].setPosition(enemylist_UFO[enemylist_UFO.size() - 1].getPosition().x, enemylist_UFO[enemylist_UFO.size() - 1].getPosition().y - 20);
	UFO_healthbars[UFO_healthbars.size() - 1].setSize(sf::Vector2f(Enemy_Ufo_example.getSize().x, 15));
}

void EntityManager::spawnTNT(sf::RenderWindow* window) {
	
	enemylist_TNT.push_back(Enemy_TNT_example);
	enemylist_TNT[enemylist_TNT.size() - 1].setPosition(window->getSize().x + 20, rand() % window->getSize().y);
	TNT_healthbars.push_back(sf::RectangleShape());
	TNT_healthbars[TNT_healthbars.size() - 1].setFillColor(sf::Color::Green);
	TNT_healthbars[TNT_healthbars.size() - 1].setPosition(enemylist_TNT[enemylist_TNT.size() - 1].getPosition().x, enemylist_TNT[enemylist_TNT.size() - 1].getPosition().y - 20);
	TNT_healthbars[TNT_healthbars.size() - 1].setSize(sf::Vector2f(Enemy_TNT_example.getSize().x, 15));
}

void EntityManager::spawnGuard(sf::RenderWindow* window) {
	enemylist_Guard.push_back(Enemy_Guard_example);
	enemylist_Guard[enemylist_Guard.size() - 1].spawnAndSet(window);
	Guard_healthbars.push_back(sf::RectangleShape());
	Guard_healthbars[Guard_healthbars.size() - 1].setFillColor(sf::Color::Green);
	Guard_healthbars[Guard_healthbars.size() - 1].setPosition(enemylist_Guard[enemylist_Guard.size() - 1].getPosition().x, enemylist_Guard[enemylist_Guard.size() - 1].getPosition().y - 20);
	Guard_healthbars[Guard_healthbars.size() - 1].setSize(sf::Vector2f(Enemy_Guard_example.getSize().x, 15));
}

void EntityManager::spawnWave(sf::RenderWindow* window, int difficulty) {
	int ptsleft = difficulty;
	while (ptsleft != 0) {
		if (ptsleft >= 2) {
			if (rand() % 2 == 0) { spawnUfo(window); ptsleft--; }
			else { spawnTNT(window); ptsleft -= 2; }
		}
		else{ spawnUfo(window); ptsleft--; }
	}
}

void EntityManager::renderAllEntities(sf::RenderWindow* window) {
	window->draw(score);
	for (int i = 0; i < enemylist_UFO.size(); i++) {
		window->draw(enemylist_UFO[i]);
	}
	for (int i = 0; i < enemylist_TNT.size(); i++) {
		window->draw(enemylist_TNT[i]);
	}
	for (int i = 0; i < enemylist_Guard.size(); i++) {
		window->draw(enemylist_Guard[i]);
	}
	for (int i = 0; i < UFO_healthbars.size(); i++) {
		window->draw(UFO_healthbars[i]);
	}
	for (int i = 0; i < TNT_healthbars.size(); i++) {
		window->draw(TNT_healthbars[i]);
	}
	for (int i = 0; i < Guard_healthbars.size(); i++) {
		window->draw(Guard_healthbars[i]);
	}
}