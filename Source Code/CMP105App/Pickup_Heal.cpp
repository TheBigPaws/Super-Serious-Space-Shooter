#include "Pickup_Heal.h"

Pickup_Heal::Pickup_Heal() {
	texture.loadFromFile("gfx/sprites/Pickup_Heal.png");
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollider(true);
	setCollisionBox(0, 0, 100, 100);
	alive = false;
}