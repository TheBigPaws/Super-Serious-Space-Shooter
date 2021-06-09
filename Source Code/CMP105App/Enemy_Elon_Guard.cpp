#include "Enemy_Elon_Guard.h"

Enemy_Elon_Guard::Enemy_Elon_Guard() {
	health = 300;
	maxhealth = health;
	alive = true;
	spritesheet.loadFromFile("gfx/sprites/Enemy_Elon_Guard.png");
	setTexture(&spritesheet);
	for (int i = 0; i < 4; i++) {
		basic.addFrame(sf::IntRect(i * 58, 0, 58, 58));
	}
	for (int i = 0; i < 7; i++) {
		throwGranade.addFrame(sf::IntRect((4+i) * 58, 0, 58, 58));
	}
	setSize(sf::Vector2f(58 * 3, 58 * 3));
	basic.setFrameSpeed(0.1);
	throwGranade.setFrameSpeed(0.05);
	throwGranade.setLooping(false);
	currentAnimation = basic;
	setCollider(true);
	setCollisionBox(50, 0, 58 * 3-50, 58 * 3);
}
//spawns and chooses a destination
void Enemy_Elon_Guard::spawnAndSet(sf::RenderWindow* window) {
	goaldestination[0] = window->getSize().x -100 -getSize().x - 4*170;
	goaldestination[1] = abs((rand() % window->getSize().y) - getSize().y);
	setPosition(window->getSize().x + 100, window->getSize().y + 20);
	direction.x = goaldestination[0] - getPosition().x;
	direction.y = goaldestination[1] - getPosition().y;
	direction = Vector::normalise(direction);
	std::cout << goaldestination[1];
	shootat = rand() % 1000;
}

//movement
void Enemy_Elon_Guard::comeThenHover(float dt) {
	currentAnimation.animate(dt);
	setTextureRect(currentAnimation.getCurrentFrame());
	if (currentAnimation.getPlaying() == false) { currentAnimation = basic; }
	if (isSet == true) {
		if (getPosition().y >= goaldestination[1] + 10) { hoverswitch = -1; }
		else if (getPosition().y < goaldestination[1]) { hoverswitch = 1; }
		move(0, hoverswitch * 20 * dt);
	}
	else {
		move(direction.x*dt*500,direction.y*dt * 500);
		if (getPosition().x <= goaldestination[0]) { isSet = true; }
	}
}
