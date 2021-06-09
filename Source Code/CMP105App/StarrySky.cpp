#include "StarrySky.h"
//initializes sky depending on the size of a window
void StarrySky::StarrySkyInitialize(sf::RenderWindow* window) {
	star1px.loadFromFile("gfx/sprites/star1px.png");
	star2px.loadFromFile("gfx/sprites/star2px.png");
	skyfront.setTexture(&star2px);
	skyback.setTexture(&star1px);
	skyfront.setSize(sf::Vector2f(window->getSize().x * 2, window->getSize().y));
	skyback.setSize(sf::Vector2f(window->getSize().x * 2, window->getSize().y));
	skyfront.setPosition(0, 0);
	skyback.setPosition(0, 0);
}

void StarrySky::starUpdate(sf::RenderWindow* window, float dt) {
	int scrsize = window->getSize().x;
	if (skyfront.getPosition().x > -scrsize) {
		skyfront.move(-420 * dt, 0);
	}
	else { skyfront.setPosition(0, 0); }
	if (skyback.getPosition().x > -scrsize) {
		skyback.move(-222 * dt, 0);
	}
	else { skyback.setPosition(0, 0); }
}
void StarrySky::starRender(sf::RenderWindow* window) {
	window->draw(skyback);
	window->draw(skyfront);
}