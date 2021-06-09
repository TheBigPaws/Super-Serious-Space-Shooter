#pragma once
#include "Framework/GameObject.h"
class Car : public GameObject
{
private:
	sf::Texture car;
	int health = 500;
	int maxhealth = 500;
	sf::Vector2f direction;
public:
	Car();
	//resets values
	void reset();
	void dealDamage(int dmg) { health -= dmg; if (health <= 0) { alive = false; } }
	//setters
	void setDirection(sf::Vector2f set) { direction = set; }
	//getters
	sf::Vector2f getDirection() { return direction; }
	int getHealth() { return health; }
	int getMaxHealth() { return maxhealth; }
};

