#include "Screen_GameOver.h"

void Screen_GameOver::Screen_GameOver_Render(sf::RenderWindow* window) {
	if (isset == false) {
		isset = true;
		clrfilter.setFillColor(sf::Color(200, 0, 0, 0));
		clrfilter.setPosition(-5, -5);
		clrfilter.setSize(sf::Vector2f(window->getSize().x + 10, window->getSize().y + 10));
		text.push_back(sf::Text());
		text[0].setCharacterSize(125);
		text[0].setFont(font);
		text[0].setString("GAME OVER!");
		text[0].setPosition(window->getSize().x / 2 - text[0].getLocalBounds().width / 2, 100);
		text.push_back(sf::Text());
		text[1].setCharacterSize(60);
		text[1].setFont(font);
		text[1].setString("Press Esc to go back to main menu\n     Press Enter to try again!");
		text[1].setPosition(window->getSize().x / 2 - text[1].getLocalBounds().width / 2, window->getSize().y - 200);
	}
	window->draw(clrfilter);
	if (clrfilter.getFillColor().a >= 200) {
		for (int i = 0; i < text.size(); i++) {
			window->draw(text[i]);
		}
	}
}

void Screen_GameOver::Screen_GameOver_Update(float dt) {
	timepassed += dt;
	if (clrfilter.getFillColor().a < 200) {
		if (timepassed > 0.005) {
			clrfilter.setFillColor(sf::Color(200, 0, 0, clrfilter.getFillColor().a + 1));
		}
	}
}