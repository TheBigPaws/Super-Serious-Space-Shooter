#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class StarrySky
{
private:
	sf::Texture star2px;
	sf::Texture star1px;
	GameObject skyfront;
	GameObject skyback;
public:
	//initializes sky depending on the size of a window
	void StarrySkyInitialize(sf::RenderWindow* window);
	void starUpdate(sf::RenderWindow* window,float dt);
	void starRender(sf::RenderWindow* window);
};

