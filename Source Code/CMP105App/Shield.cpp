#include "Shield.h"

Shield::Shield() {
	texture.loadFromFile("gfx/sprites/Pulse_Shield.png");
	setTexture(&texture);
	for (int i = 0; i < 3; i++) {
		basic.addFrame(sf::IntRect(i * 50, 0, 50, 50));
	}
	basic.setFrameSpeed(0.2);
	setSize(sf::Vector2f(150, 150));
	setOrigin(75, 75);
}

void Shield::update(float dt) {
	basic.animate(dt);
	setTextureRect(basic.getCurrentFrame());
}