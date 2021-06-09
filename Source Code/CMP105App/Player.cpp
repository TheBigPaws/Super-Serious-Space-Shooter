#include "Player.h"

Player::Player() {
	alive = true;
	shipfly.loadFromFile("gfx/sprites/Player_Spaceship.png");
	setTexture(&shipfly);
	setSize(sf::Vector2f(32 * 4, 26 * 4));
	for (int i = 0; i < 4; i++) {
		fly.addFrame(sf::IntRect(i * 32, 0, 32, 26));
	}
	fly.setFrameSpeed(0.1);
	speed = 500;
	attackSpeed = 1000;
	maxhealth = 300;
	health = 300;
	damage = 50;
	setCollider(false);
	setCollisionBox(0, 0, 32 * 4, 26 * 4);
}

void Player::update(float dt) {
	fly.animate(dt);
	setTextureRect(fly.getCurrentFrame());
}

void Player::handleInput(float dt, sf::RenderWindow* window) {
	if (input->isKeyDown(sf::Keyboard::S)&&getPosition().y<window->getSize().y-getSize().y) {
		move(0,dt*speed);
	}
	else if (input->isKeyDown(sf::Keyboard::W) && getPosition().y > 0) {
		move(0, -1*dt*speed);
	}
	if (input->isKeyDown(sf::Keyboard::A) && getPosition().x > 0) {
		move(-1 * dt * speed,0);
	}
	else if (input->isKeyDown(sf::Keyboard::D) && getPosition().x < window->getSize().x - getSize().x) {
		move(dt * speed,0);
	}
}