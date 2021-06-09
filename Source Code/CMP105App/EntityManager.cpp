#include "EntityManager.h"

//hbarsetup for player.
void EntityManager::playerHpBarSetup(Entity* player) {
	player_Healthbar.setFillColor(sf::Color::Green);
	player_Healthbar.setSize(sf::Vector2f(player->getSize().x,10));
}

//sets up the score.
void EntityManager::scoreSetup(sf::RenderWindow* window) {
	score_int = 0;
	font.loadFromFile("font/slkscr.ttf");
	score.setFont(font);
	score.setPosition(window->getSize().x / 2 - 100, 80);
	score.setCharacterSize(50);
	score.setString("SCORE: " + std::to_string(score_int));
	score.setOutlineColor(sf::Color::Black);
	score.setOutlineThickness(2);
}

//moves all entities
void EntityManager::updateAllEntities(float dt, Entity* player, sf::RenderWindow* window) {
	//updates position of pulse shieldpckp
	if (Pulse_Shield.isAlive()) {
		Pulse_Shield.update(dt);
		Pulse_Shield.setPosition(player->getPosition().x + player->getSize().x / 2, player->getPosition().y + player->getSize().y / 2);
	}
	//updates all entities
	player_Healthbar.setPosition(player->getPosition().x, player->getPosition().y - 20);
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
	
	//musk states and animations control
	updateMusk(dt);
	if (Boss.isAlive()) {
		if (Boss.get_MuskState() != MuskState::DEFEATED) { Boss.comeThenHover(dt); Boss_HP.setPosition(Boss.getPosition().x, Boss.getPosition().y - 30); }
		else if (Boss.getPosition().y > -20 - Boss.getSize().y) { Boss.move(0, -150 * dt); }
		else { Boss.setAlive(false); }

		if (Boss.get_MuskState() == MuskState::FLY) {
			if (MuskStateClock.getElapsedTime().asMilliseconds() > 5000) {
				MuskStateClock.restart();
				if (enemylist_Guard.size() == 0) {
					if (rand() % 100 < 60) { Boss.set_MuskState(MuskState::CALLSUPPORT); for (int i = 0; i < Boss.getMaxHealth() / 1000; i++) { spawnGuard(window); } }
					else { Boss.set_MuskState(MuskState::SHOOTCAR); }
				}
			}
		}
	}
	//takes care of moving the pickups and setting them off if they're off screen
	if (heal.isAlive()) { heal.move(-200 * dt, 0); }
	if (shieldpckp.isAlive()) { shieldpckp.move(-200 * dt, 0); }
	if (upgrade.isAlive()) { upgrade.move(-200 * dt, 0); }
	if (heal.getPosition().x < -20 - heal.getSize().x) { heal.setAlive(false); }
	if (shieldpckp.getPosition().x < -20 - shieldpckp.getSize().x) { shieldpckp.setAlive(false); }
	if (upgrade.getPosition().x < -20 - upgrade.getSize().x) { upgrade.setAlive(false); }
}

//ufo spawner
void EntityManager::spawnUfo(sf::RenderWindow* window) {
	enemylist_UFO.push_back(Enemy_Ufo_example);
	enemylist_UFO[enemylist_UFO.size() - 1].spawnAndSet(window);

	UFO_healthbars.push_back(sf::RectangleShape());
	UFO_healthbars[UFO_healthbars.size() - 1].setFillColor(sf::Color::Green);
	UFO_healthbars[UFO_healthbars.size() - 1].setPosition(enemylist_UFO[enemylist_UFO.size() - 1].getPosition().x, enemylist_UFO[enemylist_UFO.size() - 1].getPosition().y - 20);
	UFO_healthbars[UFO_healthbars.size() - 1].setSize(sf::Vector2f(Enemy_Ufo_example.getSize().x, 10));
}

//tnt spawner
void EntityManager::spawnTNT(sf::RenderWindow* window) {
	
	enemylist_TNT.push_back(Enemy_TNT_example);
	enemylist_TNT[enemylist_TNT.size() - 1].setPosition(window->getSize().x + 20, rand() % window->getSize().y);
	TNT_healthbars.push_back(sf::RectangleShape());
	TNT_healthbars[TNT_healthbars.size() - 1].setFillColor(sf::Color::Green);
	TNT_healthbars[TNT_healthbars.size() - 1].setPosition(enemylist_TNT[enemylist_TNT.size() - 1].getPosition().x, enemylist_TNT[enemylist_TNT.size() - 1].getPosition().y - 20);
	TNT_healthbars[TNT_healthbars.size() - 1].setSize(sf::Vector2f(Enemy_TNT_example.getSize().x, 10));
}

//guard spawner
void EntityManager::spawnGuard(sf::RenderWindow* window) {
	enemylist_Guard.push_back(Enemy_Guard_example);
	enemylist_Guard[enemylist_Guard.size() - 1].spawnAndSet(window);
	Guard_healthbars.push_back(sf::RectangleShape());
	Guard_healthbars[Guard_healthbars.size() - 1].setFillColor(sf::Color::Green);
	Guard_healthbars[Guard_healthbars.size() - 1].setPosition(enemylist_Guard[enemylist_Guard.size() - 1].getPosition().x, enemylist_Guard[enemylist_Guard.size() - 1].getPosition().y - 20);
	Guard_healthbars[Guard_healthbars.size() - 1].setSize(sf::Vector2f(Enemy_Guard_example.getSize().x, 10));
}
//wave spawner based on difficulty
void EntityManager::spawnWave(sf::RenderWindow* window, float difficulty) {
	float ptsleft = difficulty;
	while (ptsleft > 0) {
		if (difficulty > 10 && ptsleft >= 3) {
			if (rand() % 5 == 0) { spawnGuard(window); ptsleft -= 3; }
		}

		if (ptsleft >= 2) {
			if (rand() % 2 == 0) { spawnUfo(window); ptsleft--; }
			else { spawnTNT(window); ptsleft -= 2; }
		}
		else{ spawnUfo(window); ptsleft--; }
	}
}

//renders all
void EntityManager::renderAllEntities(sf::RenderWindow* window) {
	window->draw(score);
	window->draw(player_Healthbar);
	if (Pulse_Shield.isAlive()) {window->draw(Pulse_Shield);}
	if (heal.isAlive()) { window->draw(heal); }
	if (upgrade.isAlive()) { window->draw(upgrade); }
	if (shieldpckp.isAlive()) { window->draw(shieldpckp); }
	renderMusk(window);
	for (int i = 0; i < enemylist_UFO.size(); i++) {
		window->draw(enemylist_UFO[i]);
		window->draw(UFO_healthbars[i]);
	}
	for (int i = 0; i < enemylist_TNT.size(); i++) {
		window->draw(enemylist_TNT[i]);
		window->draw(TNT_healthbars[i]);
	}
	for (int i = 0; i < enemylist_Guard.size(); i++) {
		window->draw(enemylist_Guard[i]);
		window->draw(Guard_healthbars[i]);
	}
}

//resets everything
void EntityManager::delete_EVERYTHING() {
	score_int = 0;
	enemylist_UFO.clear();
	enemylist_TNT.clear();
	enemylist_Guard.clear();

	UFO_healthbars.clear();
	TNT_healthbars.clear();
	Guard_healthbars.clear();
	Boss.setAlive(false);
	heal.setAlive(false);
	upgrade.setAlive(false);
}

//resetter for boss
void EntityManager::spawnMusk(sf::RenderWindow* window, int difficulty) {
	Boss.reset(difficulty);
	MuskStateClock.restart();
	Boss.set_MuskState(MuskState::FLY);
	Boss.setgoaldest(window->getSize().x-Boss.getSize().x-100, window->getSize().y / 2 - Boss.getSize().y / 2);
	Boss.setPosition(window->getSize().x + 100, window->getSize().y/2 - Boss.getSize().y / 2);
	Boss_HP.setFillColor(sf::Color::Green);
	Boss_HP.setPosition(Boss.getPosition().x, Boss.getPosition().y - 30);
	Boss_HP.setSize(sf::Vector2f(Boss.getSize().x, 15));
}