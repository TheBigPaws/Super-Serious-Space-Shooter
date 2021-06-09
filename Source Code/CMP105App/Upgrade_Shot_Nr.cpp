#include "Upgrade_Shot_Nr.h"
Upgrade_Shot_Nr::Upgrade_Shot_Nr() {
	texture.loadFromFile("gfx/sprites/Upgrade_Shot_Nr.png");
	setTexture(&texture);
	for (int i = 0; i < 4; i++) {
		basic.addFrame(sf::IntRect(i * 50, 0, 50, 50));
	}
	basic.setFrameSpeed(0.3);
	setSize(sf::Vector2f(300, 300));
	setOrigin(150, 150);
}

void Upgrade_Shot_Nr::update(float dt) {
	basic.animate(dt);
	setTextureRect(basic.getCurrentFrame());
}