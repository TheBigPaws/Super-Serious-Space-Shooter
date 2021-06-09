#pragma once
#include "Framework/GameObject.h"
class Screen_GameOver : public GameObject
{
private:
	std::vector <sf::Text> text;
	sf::Font font;
	sf::RectangleShape clrfilter;
	bool isset = false;
	float timepassed;
public:
	//font setter
	void setFont(sf::Font fontsetter) { font = fontsetter; }
	void Screen_GameOver_Render(sf::RenderWindow* window);
	void Screen_GameOver_Update(float dt);
	//resets colour for the animation to be able to perform correctly
	void reset(){ clrfilter.setFillColor(sf::Color(200, 0, 0, 0)); }
};

