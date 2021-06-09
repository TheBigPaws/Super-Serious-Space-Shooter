#include "Enemy_TNT.h"

Enemy_TNT::Enemy_TNT() {
	health = 150;
	maxhealth = health;
	alive = true;
	spritesheet.loadFromFile("gfx/sprites/Enemy_TNT_Alien.png");
	setTexture(&spritesheet);
	for (int i = 0; i < 6; i++) {
		fly.addFrame(sf::IntRect(i * 59, 0, 59, 50));
	}
	setSize(sf::Vector2f(59 * 2, 50 * 2));
	fly.setFrameSpeed(0.1);
	speed = 500;
	setCollider(true);
	setCollisionBox(0, 0, 118, 100);
}
//movement
void Enemy_TNT::flytoPlayer(Entity* player, float dt) {
	fly.animate(dt);
	setTextureRect(fly.getCurrentFrame());
	direction = Vector::normalise(sf::Vector2f(player->getPosition().x - getPosition().x, player->getPosition().y - getPosition().y));
	if (direction.x > 0 && fly.getFlipped() == false) { fly.setFlipped(true);}
	if (direction.x < 0 && fly.getFlipped() == true) { fly.setFlipped(false); }
	move(direction.x*dt*250,direction.y*dt*250);
}
