#include "Enemy_Ufo.h"

Enemy_Ufo::Enemy_Ufo() {
	health = 200;
	maxhealth = health;
	alive = true;
	sprite.loadFromFile("gfx/sprites/Enemy_Ufo.png");
	setTexture(&sprite);
	setSize(sf::Vector2f(124, 28 * 4));
	setCollider(true);
	setCollisionBox(0, 0, 124, 112);
}

//spawns and chooses a destination
void Enemy_Ufo::spawnAndSet(sf::RenderWindow* window) {
	goaldestination[0] = window->getSize().x -getSize().x -(rand() % (window->getSize().x/3));
	goaldestination[1] = abs((rand()%window->getSize().y) - getSize().y);
	setPosition(window->getSize().x + 20, rand()% window->getSize().y);
	direction.x = goaldestination[0] - getPosition().x;
	direction.y = goaldestination[1] - getPosition().y;
	direction = Vector::normalise(direction);
	shootat = rand() % 1000;
}

//movement
void Enemy_Ufo::comeThenHover(float dt) {
	if (isSet == true) {
		if (getPosition().y >= goaldestination[1] + 10) { hoverswitch = -1; }
		else if (getPosition().y < goaldestination[1]) { hoverswitch = 1; }
		move(0, hoverswitch * 20 * dt);
	}
	else {
		move(direction.x*dt * 500,direction.y*dt * 500);
		if (getPosition().x <= goaldestination[0]) { isSet = true; }
	}
}
