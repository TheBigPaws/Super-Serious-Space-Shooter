#include "Bullet.h"
//setter for attributes
void Bullet::isally(bool isally) {
	textr.loadFromFile("gfx/sprites/Bullets.png");
	setTexture(&textr);
	if (isally == true) {
		normalState.addFrame(sf::IntRect(0, 0, 15, 7));
		normalState.addFrame(sf::IntRect(15, 0, 15, 7));
	}
	else {
		normalState.addFrame(sf::IntRect(30, 0, 15, 7));
		normalState.addFrame(sf::IntRect(45, 0, 15, 7));
	}
	setOrigin(15, 7);
	setSize(sf::Vector2f(15 * 2, 7 * 2));
	normalState.setFrameSpeed(0.1);
	setCollider(true);
}

//used for aimed shots
void Bullet::setDirection(float xdir, float ydir) {
	direction.x = xdir;
	direction.y = ydir;
	direction = Vector::normalise(direction);
	if (ydir != 0) {
		setRotation(57.2957795*atan(ydir/xdir));
	}
}
//used for shots where angle matters
void Bullet::setDirection(float angle) {
	
	if (angle == 0) { direction.x = 1; direction.y = 0; }
	else{ direction.x = cos(angle* 0.0174532925); direction.y = sin(angle* 0.0174532925); }
	setRotation(angle);
}

void Bullet::update(float dt) {
	normalState.animate(dt);
	setTextureRect(normalState.getCurrentFrame());
	move(direction.x*dt*800,direction.y*dt*800);
}