#include "Car.h"

#include "Car.h"
Car::Car() {
	car.loadFromFile("gfx/sprites/spaceman.png");
	setTexture(&car);
	setSize(sf::Vector2f(350, 140));
	setCollider(true);
	setOrigin(sf::Vector2f(175,70));
	setCollisionBox(-175, -70, 350, 140);
}

void Car::reset() {
	health = 500;
	maxhealth = 500;
	alive = true;
	setScale(sf::Vector2f(0.1, 0.1));
}