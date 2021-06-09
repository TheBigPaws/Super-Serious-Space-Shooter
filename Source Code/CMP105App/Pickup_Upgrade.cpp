#include "Pickup_Upgrade.h"

Pickup_Upgrade::Pickup_Upgrade() {
	texture.loadFromFile("gfx/sprites/Pickup_Upgrade.png");
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollider(true);
	setCollisionBox(0, 0, 100, 100);
	alive = false;
}