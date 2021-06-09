#include "Screen_MMenu.h"

void Screen_MMenu::Screen_MMenu_Render(sf::RenderWindow* window) {
	//runs only once. sets up all the texts for the menu screen
	if (isset == false) {
		for (int i = 0; i < 3; i++) {
			goalcolors.push_back(rand() % 256);
		}
		isset = true;
		for (int i = 0; i < 21; i++) {
			text.push_back(sf::Text());
			text[i].setFont(font);
		}
		text[0].setCharacterSize(100);
		text[0].setString("SUPER SERIOUS \nSPACE SHOOTER");
		text[0].setPosition(window->getSize().x / 2 - text[0].getLocalBounds().width / 2, 50);
		text[0].setOutlineColor(sf::Color::White);
		text[0].setOutlineThickness(3);
		player.setScale(2, 2);
		player.setPosition(window->getSize().x / 2 - player.getSize().x, 150 + text[0].getLocalBounds().height);	
		text[1].setCharacterSize(75);
		text[1].setString("Play");
		text[1].setOrigin(text[1].getLocalBounds().width / 2, text[1].getLocalBounds().height / 2);
		text[1].setPosition(window->getSize().x / 2, player.getPosition().y+player.getSize().y*2+25);
		text[1].setOutlineThickness(5);
		text[1].setScale(1.2, 1.2);
		text[2].setCharacterSize(75);
		text[2].setString("settings");
		text[2].setOrigin(text[2].getLocalBounds().width / 2, text[2].getLocalBounds().height / 2);
		text[2].setPosition(window->getSize().x / 2, text[1].getPosition().y+100);
		text[3].setCharacterSize(75);
		text[3].setString("cheat codes");
		text[3].setOrigin(text[3].getLocalBounds().width / 2, text[3].getLocalBounds().height / 2);
		text[3].setPosition(window->getSize().x / 2, text[2].getPosition().y + 100);
		text[4].setCharacterSize(75);
		text[4].setString("credits");
		text[4].setOrigin(text[4].getLocalBounds().width / 2, text[4].getLocalBounds().height / 2);
		text[4].setPosition(window->getSize().x / 2, text[3].getPosition().y + 100);
		text[5].setCharacterSize(100);
		text[5].setString("settings");
		text[5].setOrigin(text[5].getLocalBounds().width / 2, text[5].getLocalBounds().height / 2);
		text[5].setPosition(window->getSize().x / 2, 100);
		text[5].setOutlineColor(sf::Color::White);
		text[5].setOutlineThickness(3);
		text[9].setString("music");
		text[10].setString("sound effects");
		text[11].setString("difficulty scaling");
		for (int j = 0; j < 6; j++) {
			rectangles.push_back(sf::RectangleShape());
			rectangles[j].setOutlineColor(sf::Color::White);
			rectangles[j].setOutlineThickness(3);
			if (j < 3) {
				rectangles[j].setSize(sf::Vector2f(600, 25));
				rectangles[j].setPosition(window->getSize().x / 2 - 300, 350 + j * 200);
				rectangles[j].setFillColor(sf::Color(153, 217, 234));
				text[6 + j].setCharacterSize(75);
				text[6 + j].setString("<                  >");
				text[6 + j].setOrigin(text[6 + j].getLocalBounds().width / 2, text[6 + j].getLocalBounds().height / 2);
				text[6 + j].setPosition(window->getSize().x / 2 - 5, 335 + j * 200);
			}
			else {
				rectangles[j].setSize(sf::Vector2f(30, 55));
				rectangles[j].setPosition(window->getSize().x / 2 - 15 - (2-SettingsNrs[j-3])*150, 335 + (j-3) * 200);
				rectangles[j].setFillColor(sf::Color::Blue);
				text[6 + j].setCharacterSize(60);
				text[6 + j].setOrigin(text[6 + j].getLocalBounds().width / 2, text[6 + j].getLocalBounds().height / 2);
				text[6 + j].setPosition(window->getSize().x / 2, 280 + (j-3) * 200);
			}
		}
		text[12].setCharacterSize(180);
		text[12].setString(cheatcode);
		text[12].setOrigin(text[12].getLocalBounds().width / 2, text[12].getLocalBounds().height / 2);
		text[12].setPosition(window->getSize().x / 2, window->getSize().y / 2);
		text[13].setCharacterSize(100);
		text[13].setString("credits");
		text[13].setOrigin(text[13].getLocalBounds().width / 2, text[13].getLocalBounds().height / 2);
		text[13].setPosition(window->getSize().x / 2, 100);
		text[13].setOutlineColor(sf::Color::White);
		text[13].setOutlineThickness(3);
		text[14].setString("Art and Code:");
		text[14].setCharacterSize(75);
		text[14].setStyle(sf::Text::Underlined | sf::Text::Bold);
		text[14].setOrigin(text[14].getLocalBounds().width / 2, text[14].getLocalBounds().height / 2);
		text[14].setPosition(window->getSize().x / 2, 300); 
		text[15].setString("TBP");
		text[16].setString("Music:");
		text[17].setString("Sleepy K");
		text[18].setString("Sounds:");
		text[19].setString("TBP,crazyduckgames,\ndklon, M. baradari");
		for (int h = 0; h < 5; h++) {
			if (h % 2 == 1) { text[15 + h].setStyle(sf::Text::Underlined | sf::Text::Bold); text[15 + h].setCharacterSize(75); }
			else { text[15 + h].setCharacterSize(60); }
			text[15+h].setOrigin(text[15 + h].getLocalBounds().width / 2, text[15 + h].getLocalBounds().height / 2);
			text[15+h].setPosition(window->getSize().x / 2, text[14+h].getPosition().y+text[14+h].getLocalBounds().height/2+ text[15 + h].getLocalBounds().height / 2 +50);
		}
		text[20].setCharacterSize(45);
		text[20].setStyle(sf::Text::Italic);
		text[20].setFillColor(sf::Color(255, 255, 255, 100));
		text[20].setString("W - up\nS - down\nA - left\nD - right\nEnter - select\nEscape - back/exit/pause");
		text[20].setPosition(10, window->getSize().y - 50 - text[20].getLocalBounds().height);
	}
	//depending on what screen the player is in, draws the appropriate text
	if (screen == 1) {
		window->draw(text[20]);
		for (int i = 0; i < 5; i++) {
			window->draw(text[i]);
		}
		window->draw(player);
	}
	else if (screen == 2) {
		for (int i = 5; i < 6; i++) {
			window->draw(text[i]);
		}
		for (int i = 0; i < 6; i++) {
			window->draw(rectangles[i]);
			window->draw(text[i+6]);
		}
	}
	else if (screen == 3) { window->draw(text[12]);}
	else if (screen == 4) {
		for (int i = 0; i < 7; i++) {
			window->draw(text[i+13]);
		}
	}
}
void Screen_MMenu::Screen_MMenu_Update(float dt) {
	player.update(dt);
	if (isset == true) {
		//RAINBOW EFFECT
		//every color gets closer to the goalcolor
		if (clrclock.getElapsedTime().asMilliseconds() > 5) {
			for (int i = 0; i < 3; i++) {
				if (colors[i] > goalcolors[i]) {
					colors[i]--;
				}
				else if (colors[i] < goalcolors[i]) { colors[i]++; }
			}
			clrclock.restart();
		}
		//if the color reaches the goal color, determine a new goalcolor
		if (colors[0] == goalcolors[0] && colors[1] == goalcolors[1] && colors[2] == goalcolors[2]) {
			goalcolors[0] = 56 + rand() % 200;
			goalcolors[1] = 56 + rand() % 200;
			goalcolors[2] = 56 + rand() % 200;
		}
		//highlight of the selected text
		text[ClickerOn].setOutlineColor(sf::Color(colors[0], colors[1], colors[2]));
		//colors the appropriate screen
		if (screen == 1) {
			text[0].setFillColor(sf::Color(colors[0], colors[1], colors[2]));
			if (text[ClickerOn].getScale().x > 1.3) { expand = -1; }
			else if (text[ClickerOn].getScale().x < 1.1) { expand = 1; }
			text[ClickerOn].setScale(text[ClickerOn].getScale().x + dt * expand / 3, text[ClickerOn].getScale().y + dt * expand / 3);
		}
		else if (screen == 2) {
			text[5].setFillColor(sf::Color(colors[0], colors[1], colors[2]));
		}
		else if(screen == 4) { text[13].setFillColor(sf::Color(colors[0], colors[1], colors[2])); }
	}
}

void Screen_MMenu::handleInput(AudioManager* audio) {
	if (keypressed == false) {
		//inputs and relevant actions
		if (screen != 3) {
			if (input->isKeyDown(sf::Keyboard::W) && ClickerOn != 1 && ClickerOn != 6) {
				audio->playSoundbyName("click");
				text[ClickerOn].setOutlineThickness(0);
				text[ClickerOn].setScale(1, 1);
				ClickerOn--;
				text[ClickerOn].setOutlineThickness(5);
				text[ClickerOn].setScale(1.2, 1.2);
			}
			if (input->isKeyDown(sf::Keyboard::S) && ClickerOn != 4 && ClickerOn != 8) {
				audio->playSoundbyName("click");
				text[ClickerOn].setOutlineThickness(0);
				text[ClickerOn].setScale(1, 1);
				ClickerOn++;
				text[ClickerOn].setScale(1.2, 1.2);
				text[ClickerOn].setOutlineThickness(5);
			}
		}
		if (input->isKeyDown(sf::Keyboard::Enter)) {
			if(screen == 1){ audio->playSoundbyName("click"); }
			text[ClickerOn].setOutlineThickness(0);
			text[ClickerOn].setScale(1, 1);
			screen = ClickerOn;
			if (screen == 2) {
				audio->playSoundbyName("click");
				ClickerOn = 6;
				text[ClickerOn].setOutlineThickness(5);
				text[ClickerOn].setScale(1.2, 1.2);
			}
			else if (screen == 3) {
				//checks for cheatcodes
				if (cheatcode == "S T A R M A N") { cheats.push_back("starman"); audio->playSoundbyName("upgrade");}
				else if (cheatcode == "G O D M O D E") { cheats.push_back("godmode");audio->playSoundbyName("upgrade");}
				else if (cheatcode == "G T G F A S T") { cheats.push_back("gtgfast");audio->playSoundbyName("upgrade");}
				else{ audio->playSoundbyName("click_back"); }
				cheatcode = "_ _ _ _ _ _ _";
				text[12].setString(cheatcode);
				for (int i = 0; i < cheats.size(); i++) {
				}
			}
		}
		if (input->isKeyDown(sf::Keyboard::Escape)&&screen!=1) {
			audio->playSoundbyName("click_back");
			//resets cheatcode
			cheatcode = "_ _ _ _ _ _ _";
			text[12].setString(cheatcode);
			text[ClickerOn].setOutlineThickness(0);
			text[ClickerOn].setScale(1, 1);
			ClickerOn = 1;
			text[ClickerOn].setScale(1.2, 1.2);
			text[ClickerOn].setOutlineThickness(5);
			screen = ClickerOn;
		}
		if (screen == 2) {
			if (input->isKeyDown(sf::Keyboard::A) && SettingsNrs[ClickerOn-6]!=0) {
				audio->playSoundbyName("click");
				rectangles[ClickerOn - 3].move(-150, 0);
				SettingsNrs[ClickerOn - 6]--;
				//modifies volume level
				if (ClickerOn == 6) {
					audio->getMusic()->setVolume(SettingsNrs[0] * 25);
				}
				else if (ClickerOn == 7) {
					for (int s = 0; s < audio->getSoundSize(); s++) {
						audio->getSound(audio->gettSound(s)->name)->setVolume(SettingsNrs[1]*25);
					}
					audio->getSound("laser_player")->setVolume(SettingsNrs[1] * 10);
					audio->getSound("laser_enemy")->setVolume(SettingsNrs[1] * 10);
				}
			}
			if (input->isKeyDown(sf::Keyboard::D) && SettingsNrs[ClickerOn - 6] != 4) {
				audio->playSoundbyName("click");
				rectangles[ClickerOn - 3].move(150, 0);
				SettingsNrs[ClickerOn - 6]++;
				//modifies volume level
				if (ClickerOn == 6) {
					audio->getMusic()->setVolume(SettingsNrs[0] * 25);
				}
				else if (ClickerOn == 7) {
					for (int s = 0; s < audio->getSoundSize(); s++) {
						audio->getSound(audio->gettSound(s)->name)->setVolume(SettingsNrs[1] * 25);
					}
					audio->getSound("laser_player")->setVolume(SettingsNrs[1] * 10);
					audio->getSound("laser_enemy")->setVolume(SettingsNrs[1] * 10);
				}
			}
		}
		//goes through the whole keyboard (allows player to write a cheatcode in)
		else if (screen == 3) {
			for (int i = 0; i < 26; i++) {
				if (input->isKeyDown(i)) { 
					for (int l = 0; l < 13; l++) {
						if(cheatcode[l] == '_'){
							audio->playSoundbyName("click");
							cheatcode[l] = char(65 + i);
							text[12].setString(cheatcode);
							break;
						}
					}
					break;
				}
			}
		}
	}
	keypressed = false;
	for (int i = 0; i < 26; i++) {
		if (input->isKeyDown(i)) { keypressed = true; break; }
	}
	if (input->isKeyDown(sf::Keyboard::Enter) ||input->isKeyDown(sf::Keyboard::Escape)) { keypressed = true; }
	if (isset2 == false) {
		isset2 = true;
		//modifies volume level, only runs once
		for (int s = 0; s < audio->getSoundSize(); s++) {
			audio->getSound(audio->gettSound(s)->name)->setVolume(SettingsNrs[1] * 25);
		}
		audio->getMusic()->setVolume(SettingsNrs[0] * 25);
		audio->getSound("laser_player")->setVolume(SettingsNrs[1] * 10);
		audio->getSound("laser_enemy")->setVolume(SettingsNrs[1] * 10);
	}
}