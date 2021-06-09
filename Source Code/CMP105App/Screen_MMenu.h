#pragma once
#include "Framework/GameObject.h"
#include "Player.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"
class Screen_MMenu :public GameObject
{
private:
	Player player;
	sf::Font font;
	sf::Clock clrclock;
	std::vector <sf::Text> text;
	std::vector<int>colors{ rand()%256,rand() % 256,rand() % 256 };
	std::vector<int>goalcolors;
	std::vector<std::string>cheats;
	std::vector<sf::RectangleShape> rectangles;
	std::vector<int>SettingsNrs{ 2,2,1 };
	std::string cheatcode = "_ _ _ _ _ _ _"; //cheat codes. starman, godmode, gtgfast
	bool keypressed = true;
	int expand = 1;
	int ClickerOn = 1;
	bool isset = false;
	bool isset2 = false;
	int screen = 1;
public:
	void clearCheats() { cheats.clear(); }
	std::vector<std::string> getCheats() { return cheats; }
	bool kpressed() { return keypressed; }
	//getters
	float getDifficulty() { return (1.1 + float(SettingsNrs[2]) * 0.1); }
	int getMusicLevel() { return SettingsNrs[0]; }
	//functions useed in level handleinput
	bool isOnMain() { if (screen == 1) { return true; } else { return false; } }
	bool isOnStart() { if (ClickerOn == 1) { return true; } else { return false; } }
	//font setter
	void setFont(sf::Font fontsetter) { font = fontsetter; }
	void Screen_MMenu_Render(sf::RenderWindow* window);
	void Screen_MMenu_Update(float dt);
	void handleInput(AudioManager* audio);
};