#include "Screen_Upgrade.h"

void Screen_Upgrade::Upgrade_Screen_Render(sf::RenderWindow* window) {
	if (isset == false) {
		isset = true;
		hpup.setPosition(window->getSize().x /5, window->getSize().y / 2);
		attdmg.setPosition(window->getSize().x / 5 * 2, window->getSize().y / 2);
		attspd.setPosition(window->getSize().x / 5 * 3, window->getSize().y / 2);
		shotnr.setPosition(window->getSize().x / 5 * 4, window->getSize().y / 2);
		text.push_back(sf::Text());
		text[0].setFont(font);
		text[0].setCharacterSize(100);
		text[0].setString("It seems like Elon dropped\na piece of his technology...");
		text[0].setPosition(window->getSize().x / 2 - text[0].getLocalBounds().width / 2, window->getSize().y / 8- text[0].getLocalBounds().height / 2);
		text.push_back(sf::Text());
		text[1].setFont(font);
		text[1].setCharacterSize(60);
		text[1].setString("[1]");
		text[1].setPosition(hpup.getPosition().x - text[1].getLocalBounds().width / 2, hpup.getPosition().y + 150);
		text.push_back(sf::Text());
		text[2].setFont(font);
		text[2].setCharacterSize(60);
		text[2].setString("[2]");
		text[2].setPosition(attdmg.getPosition().x - text[2].getLocalBounds().width / 2, attdmg.getPosition().y + 150);
		text.push_back(sf::Text());
		text[3].setFont(font);
		text[3].setCharacterSize(60);
		text[3].setString("[3]");
		text[3].setPosition(attspd.getPosition().x - text[3].getLocalBounds().width / 2, attspd.getPosition().y + 150);
		text.push_back(sf::Text());
		text[4].setFont(font);
		text[4].setCharacterSize(60);
		text[4].setString("[4]");
		text[4].setPosition(shotnr.getPosition().x - text[4].getLocalBounds().width / 2, shotnr.getPosition().y + 150);

	}
	window->draw(attdmg);
	window->draw(hpup);
	window->draw(attspd);
	window->draw(shotnr);
	for (int i = 0; i < text.size(); i++) {
		window->draw(text[i]);
	}
}
void Screen_Upgrade::Upgrade_Screen_Update(float dt) {

	attdmg.update(dt);
	hpup.update(dt);
	attspd.update(dt);
	shotnr.update(dt);
}