#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "StarrySky.h"
#include "CollisionManager.h"
#include "Screen_Upgrade.h"
#include "Screen_MMenu.h"
#include "Screen_GameOver.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	void gameSetup();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	AudioManager audio;
	//objects
	Player Player;
	StarrySky StarrySky;
	sf::Clock gameclock;
	BulletManager Bulletmanager;
	EntityManager entitymanager;
	CollisionManager collman;
	int waveLvl = 1;
	GameState gamestate;
	sf::Font pixelfont;
	sf::Text text;
	sf::Text text2;
	int statesetup = false;
	sf::RectangleShape pausefilter;
	bool pausepressed = false;
	Screen_Upgrade ScreenUpgrade;
	Screen_MMenu ScreenMMenu;
	Screen_GameOver ScreenGameOver;
	void drawEverything(sf::RenderWindow* window);
	float scaledifficulty;
};