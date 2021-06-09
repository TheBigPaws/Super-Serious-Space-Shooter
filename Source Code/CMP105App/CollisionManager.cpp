#include "CollisionManager.h"

//function to add an explosion to the centre of an argument's entity's sprite
void CollisionManager::addExlosion(GameObject* entity, AudioManager* audio) {
	explosions.push_back(explosionExample);
	explosions[explosions.size() - 1].setPosition(entity->getPosition().x + entity->getSize().x / 2, entity->getPosition().y + entity->getSize().y / 2);
	audio->playSoundbyName("explosion");
}

//checks all collisions and deals with concequences
void CollisionManager::checkcollisions(EntityManager* entitymanager, BulletManager* bulletmanager, Player* player, GameState* gamestate, AudioManager* audio) {
	bool breakbigloop = false;
	//tnt collision and hpbar update
	for (int i = 0; i < bulletmanager->getsize_playerBullets(); i++) {
		for (int j = 0; j < entitymanager->getsize_enemylist_TNT(); j++) {
			if (Collision::checkBoundingBox(bulletmanager->get_playerbullet(i), entitymanager->get_enemylist_TNT(j)) == true) {
				entitymanager->get_enemylist_TNT(j)->dealDamage(player->getDamage());
				if (!entitymanager->get_enemylist_TNT(j)->isAlive()) {
					if (!entitymanager->get_heal()->isAlive() && rand() % 10 < 2) {
						entitymanager->get_heal()->setAlive(true);
						entitymanager->get_heal()->setPosition(entitymanager->get_enemylist_TNT(j)->getPosition());
					}
					else if (!entitymanager->get_shield()->isAlive() && rand() % 15 == 0) {
						entitymanager->get_shield()->setAlive(true);
						entitymanager->get_shield()->setPosition(entitymanager->get_enemylist_TNT(j)->getPosition());
					}
					entitymanager->delete_healthbars_TNT(j);
					entitymanager->addscore(20);
					addExlosion(entitymanager->get_enemylist_TNT(j),audio);
					entitymanager->delete_enemylist_TNT(j);
				}
				else { entitymanager->get_healthbar_TNT(j)->setSize(sf::Vector2f(float(entitymanager->get_enemylist_TNT(j)->getHealth()) / float(entitymanager->get_enemylist_TNT(j)->getMaxHealth()) * entitymanager->get_enemylist_TNT(j)->getSize().x,10)); }
				bulletmanager->delete_playerbullet(i);
				breakbigloop = true;
				break;
			}
		}
		if (breakbigloop == true) { break; }
		//guard collision and hpbar update
		for (int j = 0; j < entitymanager->getsize_enemylist_Guard(); j++) {
			if (Collision::checkBoundingBox(bulletmanager->get_playerbullet(i), entitymanager->get_enemylist_Guard(j)) == true) {
				entitymanager->get_enemylist_Guard(j)->dealDamage(player->getDamage());
				if (!entitymanager->get_enemylist_Guard(j)->isAlive()) {
					if (!entitymanager->get_heal()->isAlive() && rand() % 10 <4) {
						entitymanager->get_heal()->setAlive(true);
						entitymanager->get_heal()->setPosition(entitymanager->get_enemylist_Guard(j)->getPosition());
					}
					else if (!entitymanager->get_shield()->isAlive() && rand() % 10 == 0) {
						entitymanager->get_shield()->setAlive(true);
						entitymanager->get_shield()->setPosition(entitymanager->get_enemylist_Guard(j)->getPosition());
					}
					else if (!entitymanager->get_upgrade()->isAlive() && rand() % 50 == 0) {
						entitymanager->get_upgrade()->setAlive(true);
						entitymanager->get_upgrade()->setPosition(entitymanager->get_enemylist_Guard(j)->getPosition());
					}
					entitymanager->delete_healthbars_Guard(j);
					entitymanager->addscore(50);
					addExlosion(entitymanager->get_enemylist_Guard(j), audio);
					entitymanager->delete_enemylist_Guard(j);
				}
				else { entitymanager->get_healthbar_Guard(j)->setSize(sf::Vector2f(float(entitymanager->get_enemylist_Guard(j)->getHealth()) / float(entitymanager->get_enemylist_Guard(j)->getMaxHealth()) * entitymanager->get_enemylist_Guard(j)->getSize().x, 10)); }
				bulletmanager->delete_playerbullet(i);
				breakbigloop = true;
				break;	
			}
		}
		if (breakbigloop == true) { break; }
		//ufo collision and hpbar update
		for (int j = 0; j < entitymanager->getsize_enemylist_UFO(); j++) {
			if (Collision::checkBoundingBox(bulletmanager->get_playerbullet(i), entitymanager->get_enemylist_UFO(j)) == true) {
				entitymanager->get_enemylist_UFO(j)->dealDamage(player->getDamage());
				if (!entitymanager->get_enemylist_UFO(j)->isAlive()) {
					if (!entitymanager->get_heal()->isAlive() && rand() % 10 < 2) {
						entitymanager->get_heal()->setAlive(true);
						entitymanager->get_heal()->setPosition(entitymanager->get_enemylist_UFO(j)->getPosition());
					}
					else if (!entitymanager->get_shield()->isAlive() &&rand() % 15 == 0) {
						entitymanager->get_shield()->setAlive(true);
						entitymanager->get_shield()->setPosition(entitymanager->get_enemylist_UFO(j)->getPosition());
					}
					entitymanager->delete_healthbars_UFO(j);
					entitymanager->addscore(10);
					addExlosion(entitymanager->get_enemylist_UFO(j), audio);
					entitymanager->delete_enemylist_UFO(j);
				}
				else { entitymanager->get_healthbar_UFO(j)->setSize(sf::Vector2f(float(entitymanager->get_enemylist_UFO(j)->getHealth()) / float(entitymanager->get_enemylist_UFO(j)->getMaxHealth()) * entitymanager->get_enemylist_UFO(j)->getSize().x, 10)); }
				bulletmanager->delete_playerbullet(i);
				breakbigloop = true;
				break;				
			}
		}
		if (breakbigloop == true) { break; }
		if (bulletmanager->get_car()->isAlive()) {
			//car - bullet collison
			if (Collision::checkBoundingBox(bulletmanager->get_playerbullet(i), bulletmanager->get_car()) == true) {
				bulletmanager->get_car()->dealDamage(player->getDamage());
				if (bulletmanager->get_car()->isAlive()==true) { bulletmanager->get_carHP()->setSize(sf::Vector2f(float(bulletmanager->get_car()->getHealth())/float(bulletmanager->get_car()->getMaxHealth())* bulletmanager->get_car()->getSize().x,10)); }
				else { bulletmanager->setcarflip(false);
				addExlosion(bulletmanager->get_car(), audio);
				bulletmanager->get_car()->setAlive(false);
				entitymanager->addscore(-250);
				}
				bulletmanager->delete_playerbullet(i);
				break;
			}
			//car - player collison
			if (Collision::checkBoundingBox(player, bulletmanager->get_car()) == true) {
				if (entitymanager->get_Pulse_Shield()->isAlive()) {
					entitymanager->get_Pulse_Shield()->setAlive(false);
				}
				else {
					player->dealDamage(100);
					entitymanager->get_healthbar_Player()->setSize(sf::Vector2f(float(player->getHealth()) / float(player->getMaxHealth()) * player->getSize().x, 10));
				}
				addExlosion(bulletmanager->get_car(), audio);
				bulletmanager->get_car()->setAlive(false);
				bulletmanager->setcarflip(false);
				entitymanager->addscore(-250);
			}
		}
		//boss collision check
		if (entitymanager->get_Boss()->isAlive()) {
			if (entitymanager->get_Boss()->get_MuskState() != MuskState::DEFEATED) {
				if (Collision::checkBoundingBox(bulletmanager->get_playerbullet(i), entitymanager->get_Boss()) == true) {
					entitymanager->get_Boss()->dealDamage(player->getDamage());
					if (entitymanager->get_Boss()->isAlive() == true) { entitymanager->get_healthbar_Musk()->setSize(sf::Vector2f(float(entitymanager->get_Boss()->getHealth()) / float(entitymanager->get_Boss()->getMaxHealth()) * entitymanager->get_Boss()->getSize().x, 15)); }
					else {//boss is dead, sets it to defeated state and drops upgrade
						entitymanager->get_Boss()->set_MuskState(MuskState::DEFEATED);
						audio->stopAllMusic();
						audio->playMusicbyName("GameTrack");
						entitymanager->get_upgrade()->setAlive(true);
						entitymanager->get_upgrade()->setPosition(entitymanager->get_Boss()->getPosition().x + entitymanager->get_Boss()->getSize().x / 2, entitymanager->get_Boss()->getPosition().y + entitymanager->get_Boss()->getSize().y / 2);
						entitymanager->addscore(500); entitymanager->get_Boss()->setAlive(true);
						//adds multiple explosions to the defeated boss
						explosions.push_back(explosionExample);
						explosions[explosions.size() - 1].setPosition(entitymanager->get_Boss()->getPosition().x + 50, entitymanager->get_Boss()->getPosition().y + 50);
						explosions.push_back(explosionExample);
						explosions[explosions.size() - 1].setPosition(entitymanager->get_Boss()->getPosition().x + entitymanager->get_Boss()->getSize().x / 2, entitymanager->get_Boss()->getPosition().y + entitymanager->get_Boss()->getSize().y - 100);
						explosions.push_back(explosionExample);
						explosions[explosions.size() - 1].setPosition(entitymanager->get_Boss()->getPosition().x + entitymanager->get_Boss()->getSize().x / 2 + 100, entitymanager->get_Boss()->getPosition().y + entitymanager->get_Boss()->getSize().y / 2);
						audio->playSoundbyName("explosion"); audio->playSoundbyName("explosion");
					}
					bulletmanager->delete_playerbullet(i);
					break;
				}
			}
		}
	}
	//player - enemy bullet collision
	for (int i = 0; i < bulletmanager->getsize_enemyBullets(); i++) {
		if (Collision::checkBoundingBox(player, bulletmanager->get_enemybullet(i))) {
			if (entitymanager->get_Pulse_Shield()->isAlive()) {
				entitymanager->get_Pulse_Shield()->setAlive(false);
			}
			else {
				player->dealDamage(50);
				entitymanager->get_healthbar_Player()->setSize(sf::Vector2f(float(player->getHealth()) / float(player->getMaxHealth()) * player->getSize().x, 10));
			}
			bulletmanager->delete_enemyBullets(i);
			break;
		}
	}
	//if TNT alien blows itself up on the player
	for (int i = 0; i < entitymanager->getsize_enemylist_TNT(); i++) {
		if (Collision::checkBoundingBox(player, entitymanager->get_enemylist_TNT(i))) {
			if (entitymanager->get_Pulse_Shield()->isAlive()) {
				entitymanager->get_Pulse_Shield()->setAlive(false);
			}
			else {
				player->dealDamage(150);
				entitymanager->get_healthbar_Player()->setSize(sf::Vector2f(float(player->getHealth()) / float(player->getMaxHealth()) * player->getSize().x, 10));
			}
			addExlosion(entitymanager->get_enemylist_TNT(i), audio);
			entitymanager->delete_enemylist_TNT(i);
			entitymanager->delete_healthbars_TNT(i);
			entitymanager->addscore(20);
			break;
		}
	}
	//granade checker
	for (int i = 0; i < bulletmanager->getsize_granades(); i++) {
		//if player hits the granade
		if (Collision::checkBoundingBox(player, bulletmanager->get_granade(i))) {
			player->dealDamage(75);
			entitymanager->get_healthbar_Player()->setSize(sf::Vector2f(float(player->getHealth()) / float(player->getMaxHealth()) * player->getSize().x, 10));
			addExlosion(bulletmanager->get_granade(i), audio);
			bulletmanager->delete_granade(i);
			break;
		}
		//if player is near the granade when it explodes
		if (abs(bulletmanager->get_granade(i)->get_explodeX()- bulletmanager->get_granade(i)->getPosition().x)<1) {
			addExlosion(bulletmanager->get_granade(i), audio);
			bulletmanager->delete_granade(i);
			if (Collision::checkBoundingBox(player, &explosions[explosions.size() - 1])) { player->dealDamage(75); entitymanager->get_healthbar_Player()->setSize(sf::Vector2f(float(player->getHealth()) / float(player->getMaxHealth()) * player->getSize().x, 10));}
			break;
		}
	}
	
	//game over check
	if (player->getHealth() <= 0) {
		audio->stopAllMusic();
		gamestate->setCurrentState(State::GAMEOVER); addExlosion(player, audio);
	}
	
	//health pickup check. if hp is full, add points instead
	if (entitymanager->get_heal()->isAlive() &&Collision::checkBoundingBox(player, entitymanager->get_heal())) {
		if (player->getMaxHealth() == player->getHealth()) { entitymanager->addscore(50); }
		else if (player->getMaxHealth() - player->getHealth() > 50) { player->setHealth(player->getHealth() + 100); }
		else{ player->setHealth(player->getHealth() + player->getMaxHealth() - player->getHealth()); }
		entitymanager->get_healthbar_Player()->setSize(sf::Vector2f(float(player->getHealth()) / float(player->getMaxHealth()) * player->getSize().x, 10));
		entitymanager->get_heal()->setAlive(false);
		audio->playSoundbyName("upgrade");
	}
	//shield pickup check. if hp is full, add points instead
	if (entitymanager->get_shield()->isAlive() && Collision::checkBoundingBox(player, entitymanager->get_shield())) {
		if(entitymanager->get_Pulse_Shield()->isAlive()){entitymanager->addscore(60);}
		entitymanager->get_Pulse_Shield()->setAlive(true);
		entitymanager->get_shield()->setAlive(false);
		audio->playSoundbyName("upgrade");
	}
	//upgrade pickup check
	if (entitymanager->get_upgrade()->isAlive() && Collision::checkBoundingBox(player, entitymanager->get_upgrade())) {
		entitymanager->get_upgrade()->setAlive(false);
		gamestate->setCurrentState(State::UPGRADE);
		audio->playSoundbyName("upgrade");
	}
}

//animation updater for explosions
void CollisionManager::updateExplosions(float dt) {
	for (int i = 0; i < explosions.size(); i++) {
		if (explosions[i].getplaying() == false) { explosions.erase(explosions.begin() + i); break; }
		explosions[i].update(dt);
	}
}

//renders all explosions
void CollisionManager::renderExplosions(sf::RenderWindow* window) {
	for (int i = 0; i < explosions.size(); i++) {
		window->draw(explosions[i]);
	}
}