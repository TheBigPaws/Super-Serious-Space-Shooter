#include "BulletManager.h"

BulletManager::BulletManager() {
	allybulletexampl.isally(true);
	enemybulletexampl.isally(false);
	carHP.setFillColor(sf::Color::Green);
}

void BulletManager::spawnUFObullets(Enemy_Ufo* ufo) {
	enemyBullets.push_back(enemybulletexampl);
	enemyBullets[enemyBullets.size() - 1].setDirection(-1, 0);
	enemyBullets[enemyBullets.size() - 1].setPosition(ufo->getPosition().x + ufo->getSize().x / 2, ufo->getPosition().y + ufo->getSize().y);
}

void BulletManager::spawnGranadeOnGuard(Enemy_Elon_Guard* guard, Player* player) {
	guard->setGranadeAnim();
	Granades.push_back(granadeexample);
	Granades[Granades.size() - 1].setPosition(guard->getPosition().x + guard->getSize().x, guard->getPosition().y + guard->getSize().y/4);
	Granades[Granades.size() - 1].set_direction(player);
	std::cout << Granades.size() << std::endl;
}

void BulletManager::spawnGuardbullets(Enemy_Elon_Guard* guard) {
	enemyBullets.push_back(enemybulletexampl);
	enemyBullets[enemyBullets.size() - 1].setDirection(-1, 0);
	enemyBullets[enemyBullets.size() - 1].setPosition(guard->getPosition().x, guard->getPosition().y + guard->getSize().y/5.0*2.0);
}

void BulletManager::spawnBullets(EntityManager* enttmanag,Player* player, AudioManager* audio) {
	//spawns player bullets
	if (playershotclock.getElapsedTime().asMilliseconds() > player->getAttackSpeed()) {
		playershotclock.restart();
		for (int i = 0; i < player->getMultShotNr(); i++) {
			playerBullets.push_back(allybulletexampl);
			playerBullets[playerBullets.size() - 1].setDirection(20.0 - (40.0 / (float(player->getMultShotNr() + 1)) * float((i + 1))));
			playerBullets[playerBullets.size() - 1].setPosition(player->getPosition().x + player->getSize().x - 20, player->getPosition().y + player->getSize().y / 2);
		}
		audio->playSoundbyName("laser_player");
	}
	//if it's enemy's turn to shoot, shoots. All enemies shoot once per second but at a different time in the second
	for (int i = 0; i < enttmanag->getsize_enemylist_UFO(); i++) {
		if (!enttmanag->get_enemylist_UFO(i)->get_hasshot() && enttmanag->get_enemylist_UFO(i)->get_shootat() <= enemyshotclock.getElapsedTime().asMilliseconds()) {
			spawnUFObullets(enttmanag->get_enemylist_UFO(i));
			enttmanag->get_enemylist_UFO(i)->set_hasshot(true);
			audio->playSoundbyName("laser_enemy");
		}
	}
	for (int i = 0; i < enttmanag->getsize_enemylist_Guard(); i++) {
		if (!enttmanag->get_enemylist_Guard(i)->get_hasshot() && enttmanag->get_enemylist_Guard(i)->get_shootat() <= enemyshotclock.getElapsedTime().asMilliseconds()) {
			if (rand() % 10 > 1) { 
				spawnGuardbullets(enttmanag->get_enemylist_Guard(i));
				audio->playSoundbyName("laser_enemy");
				enttmanag->get_enemylist_Guard(i)->set_hasshot(true);
			}
			else{ spawnGranadeOnGuard(enttmanag->get_enemylist_Guard(i), player); }
		}
	}
	//resets clock and enemy shot state
	if (enemyshotclock.getElapsedTime().asMilliseconds() > 1000) {
		enemyshotclock.restart();
		for (int i = 0; i < enttmanag->getsize_enemylist_UFO(); i++) {
			enttmanag->get_enemylist_UFO(i)->set_hasshot(false);
		}
		for (int i = 0; i < enttmanag->getsize_enemylist_Guard(); i++) {
			enttmanag->get_enemylist_Guard(i)->set_hasshot(false);
		}
	}
	//Spawns  Boss' bullets if he's alive
	if (enttmanag->get_Boss()->isAlive()) {
		if (enttmanag->get_Boss()->get_MuskState() == MuskState::FLY) {
			if (muskshotclock.getElapsedTime().asMilliseconds() > enttmanag->get_Boss()->getAttackSpeed()) {
				muskshotclock.restart();
				enemyBullets.push_back(enemybulletexampl);
				enemyBullets[enemyBullets.size() - 1].setDirection((player->getPosition().x + player->getSize().x) - enttmanag->get_Boss()->getPosition().x, (player->getPosition().y + player->getSize().y / 2) - (enttmanag->get_Boss()->getPosition().y + 150));
				enemyBullets[enemyBullets.size() - 1].setPosition(enttmanag->get_Boss()->getPosition().x, enttmanag->get_Boss()->getPosition().y + 150);
				audio->playSoundbyName("laser_enemy");
			}
		}
		else if (enttmanag->get_Boss()->get_MuskState() == MuskState::SHOOTCAR && CarFlipper == false) { muskshotclock.restart(); CarFlipper = true; car.reset(); car.setPosition(enttmanag->get_Boss()->getPosition().x + 450, enttmanag->get_Boss()->getPosition().y + 450); }
	}
}

void BulletManager::update(float dt,sf::RenderWindow* window) {
	for (int i = 0; i < Granades.size(); i++) {
		Granades[i].flynrotate(dt);
	}
	if (car.isAlive()) {
		if (car.getScale().x < 1) {
			car.setScale(sf::Vector2f(car.getScale().x + dt*2, car.getScale().y + dt*2));
		}
		car.move(-400 * dt, 0);
		carHP.setPosition(car.getPosition().x- car.getSize().x / 2, car.getPosition().y - 20 - car.getSize().y / 2);
		if (car.getPosition().x + car.getSize().x + 50 < 0) { car.setAlive(false); CarFlipper = false; }
	}
	for (int i = 0; i < playerBullets.size(); i++) {
		playerBullets[i].update(dt);
		if (playerBullets[i].getPosition().x > window->getSize().x + 50 || playerBullets[i].getPosition().y < -50 || playerBullets[i].getPosition().y>window->getSize().y + 50) {
			playerBullets.erase(playerBullets.begin() + i);
			break;
		}
	}

	for (int i = 0; i < enemyBullets.size(); i++) {
		enemyBullets[i].update(dt);
		if (enemyBullets[i].getPosition().x < -50 || enemyBullets[i].getPosition().y < -50 || enemyBullets[i].getPosition().y>window->getSize().y + 50) {
			enemyBullets.erase(enemyBullets.begin() + i);
			break;
		}
	}
}

void BulletManager::bulletsRender(sf::RenderWindow* window) {
	for (int i = 0; i < playerBullets.size();i++) {
		window->draw(playerBullets[i]);
	}
	for (int i = 0; i < enemyBullets.size(); i++) {
		window->draw(enemyBullets[i]);
	}
	if(car.isAlive()){ 
		window->draw(car); if (car.getHealth() != car.getMaxHealth()) { window->draw(carHP); }
	}
	for (int i = 0; i < Granades.size(); i++) {
		window->draw(Granades[i]);
	}
}
