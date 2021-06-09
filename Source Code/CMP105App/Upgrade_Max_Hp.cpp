#include "Upgrade_Max_Hp.h"
Upgrade_Max_Hp::Upgrade_Max_Hp() {
	texture.loadFromFile("gfx/sprites/Upgrade_Max_Hp.png");
	setTexture(&texture);
	for (int i = 0; i < 4; i++) {
		basic.addFrame(sf::IntRect(i * 50, 0, 50, 50));
	}
	basic.setFrameSpeed(0.3);
	setSize(sf::Vector2f(300, 300));
	setOrigin(150, 150);
}

void Upgrade_Max_Hp::update(float dt) {
	basic.animate(dt);
	setTextureRect(basic.getCurrentFrame());
}