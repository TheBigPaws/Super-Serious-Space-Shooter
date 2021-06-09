#include "Explosion.h"


Explosion::Explosion() {
	sprite.loadFromFile("gfx/sprites/Explosion.png");
	setTexture(&sprite);
	for (int i = 0; i < 12; i++) {
		explosion.addFrame(sf::IntRect(i*50,0,50,50));
	}
	explosion.setLooping(false);
	explosion.setFrameSpeed(0.04);
	setSize(sf::Vector2f(300, 300));
	setOrigin(150, 150);
	setCollider(true);
	setCollisionBox(-100, -100, 200, 200);
}

void Explosion::update(float dt) {
	explosion.animate(dt);
	setTextureRect(explosion.getCurrentFrame());

}