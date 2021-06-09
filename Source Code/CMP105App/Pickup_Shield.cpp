#include "Pickup_Shield.h"

Pickup_Shield::Pickup_Shield() {
	texture.loadFromFile("gfx/sprites/Pickup_Shield.png");
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollider(true);
	setCollisionBox(0, 0, 100, 100);
	alive = false;
}