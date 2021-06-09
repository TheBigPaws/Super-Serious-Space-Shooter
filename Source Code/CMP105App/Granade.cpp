#include "Granade.h"

Granade::Granade() {
	textr.loadFromFile("gfx/sprites/Guard_Granade.png");
	setTexture(&textr);
	blink.addFrame(sf::IntRect(0, 0, 3, 6));
	blink.addFrame(sf::IntRect(0, 6, 3, 6));
	setSize(sf::Vector2f(18, 36));
	setOrigin(sf::Vector2f(9, 18));
	blink.setFrameSpeed(0.1);
	setTextureRect(blink.getCurrentFrame());
}

void Granade::set_direction(GameObject* player) {
	direction = player->getPosition() - getPosition();
	direction = Vector::normalise(direction);
	explodeX = player->getPosition().x;
	explodeY = player->getPosition().y;
}

void Granade::flynrotate(float dt) {
	if (pow(getPosition().x - explodeX, 2) + pow(getPosition().y - explodeY, 2) < 40000) {
		blink.animate(dt);
		setTextureRect(blink.getCurrentFrame());
	}
	move(direction.x*176*dt, direction.y * 176 * dt);
	rotate(100 * dt);
}
