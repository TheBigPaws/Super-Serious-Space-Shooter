#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	srand(time(NULL));
	// initialise game objects
	window->setMouseCursorVisible(false);
	gamestate.setCurrentState(State::MENU);
	StarrySky.StarrySkyInitialize(window);
	Player.setInput(input);
	ScreenMMenu.setInput(input);
	pixelfont.loadFromFile("font/slkscr.ttf");
	ScreenUpgrade.setFont(pixelfont);
	ScreenMMenu.setFont(pixelfont);
	ScreenGameOver.setFont(pixelfont);
	//sets up pause filter
	pausefilter.setSize(sf::Vector2f(window->getSize().x + 10, window->getSize().y + 10));
	pausefilter.setPosition(-5, -5);
	pausefilter.setFillColor(sf::Color(127, 127, 127, 100));
	text.setCharacterSize(100);
	text.setFont(pixelfont);
	text.setString("PAUSE");
	text.setPosition(window->getSize().x / 2 - text.getLocalBounds().width / 2, window->getSize().y / 2);
	text2.setCharacterSize(40);
	text2.setFont(pixelfont);
	text2.setString("press M to exit to main menu");
	text2.setOrigin(text2.getLocalBounds().width / 2, text2.getLocalBounds().height);
	text2.setPosition(window->getSize().x / 2, window->getSize().y -40);
	text2.setFillColor(sf::Color(255, 255, 255, 100));
	//load in all audio
	audio.addSound("sfx/click.ogg", "click");
	audio.addSound("sfx/click_back.ogg", "click_back");
	audio.addSound("sfx/explosion.flac", "explosion");
	audio.addSound("sfx/laser_enemy.ogg", "laser_enemy");
	audio.addSound("sfx/laser_player.ogg", "laser_player");
	audio.addSound("sfx/upgrade.ogg", "upgrade");
	audio.addSound("sfx/losing.ogg", "losing");
	audio.addMusic("sfx/GameTrack.ogg", "GameTrack");
	audio.addMusic("sfx/BossTrack.ogg", "BossTrack");
	audio.playMusicbyName("GameTrack");
}

Level::~Level()
{

}

void Level::drawEverything(sf::RenderWindow* window) {
	StarrySky.starRender(window);
	if (Player.isAlive()) {
		window->draw(Player);
	}
	entitymanager.renderAllEntities(window);
	Bulletmanager.bulletsRender(window);
	collman.renderExplosions(window);
}

//sets up the game, resets everything
void Level::gameSetup() {
	if (audio.getMusic()->getStatus() != sf::SoundSource::Playing) {
		audio.getMusic()->play();
	}
	Player.restart();
	Bulletmanager.get_playerbullet_example()->setOrigin(-Bulletmanager.get_playerbullet_example()->getSize().x / 2, -Bulletmanager.get_playerbullet_example()->getSize().y / 2);
	Bulletmanager.get_playerbullet_example()->setSize(sf::Vector2f(30, 14));
	Bulletmanager.get_playerbullet_example()->setOrigin(15, 7);
	Bulletmanager.get_playerbullet_example()->setCollisionBox(-15, -7, 30, 14);
	gamestate.setCurrentState(State::LEVEL);
	waveLvl = 1;
	gamestate.setCurrentState(State::LEVEL);
	Player.setPosition(50, window->getSize().y / 2 - Player.getSize().y / 2);
	entitymanager.delete_EVERYTHING();
	Bulletmanager.delete_EVERYTHING();
	entitymanager.scoreSetup(window);
	entitymanager.spawnWave(window, waveLvl);
	waveLvl++;
	entitymanager.playerHpBarSetup(&Player);
	statesetup = false;
	gameclock.restart();
	for (int i = 0; i < ScreenMMenu.getCheats().size(); i++) {
		std::cout << i <<std::endl;
		if (ScreenMMenu.getCheats()[i] == "godmode") {
			Player.setCollisionBox(0, 0, 0, 0);
		}
		else if (ScreenMMenu.getCheats()[i] == "gtgfast") {
			Player.setcheatspeed();
		}
		else if (ScreenMMenu.getCheats()[i] == "starman" && Player.getDamage() == 50) {
			for (int k = 0; k < 3; k++) {
				Player.addDamage(25);
				//enlarges the bullets
				Bulletmanager.get_playerbullet_example()->setOrigin(-Bulletmanager.get_playerbullet_example()->getSize().x / 2, -Bulletmanager.get_playerbullet_example()->getSize().y / 2);
				Bulletmanager.get_playerbullet_example()->setSize(sf::Vector2f(Bulletmanager.get_playerbullet_example()->getSize().x + 15, Bulletmanager.get_playerbullet_example()->getSize().y + 7));
				Bulletmanager.get_playerbullet_example()->setOrigin(Bulletmanager.get_playerbullet_example()->getSize().x / 2, Bulletmanager.get_playerbullet_example()->getSize().y / 2);
				Bulletmanager.get_playerbullet_example()->setCollisionBox(-Bulletmanager.get_playerbullet_example()->getSize().x / 2, -Bulletmanager.get_playerbullet_example()->getSize().y / 2, Bulletmanager.get_playerbullet_example()->getSize().x, Bulletmanager.get_playerbullet_example()->getSize().y);
				Player.addMultshot();
				Player.attackspeedupgrade();
				Player.maxhealthupgrade();
			}
		}
	}
}

// handle user input
void Level::handleInput(float dt)
{
	switch (gamestate.getCurrentState())
	{
	case (State::LEVEL) :
		Player.handleInput(dt, window);
		if (input->isKeyDown(sf::Keyboard::Escape) && !pausepressed) {
			gamestate.setCurrentState(State::PAUSE);
			pausepressed = true;
			audio.getMusic()->pause();
		}
		if (!input->isKeyDown(sf::Keyboard::Escape)) { pausepressed = false; }
	break;

	case(State::MENU) :
		if (input->isKeyDown(sf::Keyboard::Enter)&&ScreenMMenu.isOnStart()) {
			audio.playSoundbyName("click");
			gameSetup();
			scaledifficulty = ScreenMMenu.getDifficulty();
		}
		if (!ScreenMMenu.kpressed() && input->isKeyDown(sf::Keyboard::Escape) &&ScreenMMenu.isOnMain()) {
			window->close();
		}
		ScreenMMenu.handleInput(&audio);
		pausepressed = !ScreenMMenu.kpressed();
	break;

	case(State::PAUSE) :
		if (input->isKeyDown(sf::Keyboard::Escape) && !pausepressed) {
			gamestate.setCurrentState(State::LEVEL);
			pausepressed = true;
			audio.playSoundbyName("click");
			audio.getMusic()->play();
		}
		if (!input->isKeyDown(sf::Keyboard::Escape)) { pausepressed = false; }
		if (input->isKeyDown(sf::Keyboard::M) && !pausepressed) {
			pausepressed = true;
			audio.playSoundbyName("click_back");
			ScreenMMenu.clearCheats();
			audio.getMusic()->stop();
			audio.getMusic()->play();
			gamestate.setCurrentState(State::MENU);
		}
	break;

	case(State::GAMEOVER) :
		if (input->isKeyDown(sf::Keyboard::Escape)) {
			gamestate.setCurrentState(State::MENU);
			pausepressed = true;
			ScreenGameOver.reset();
			ScreenMMenu.clearCheats();
			audio.playSoundbyName("click_back");
			if (audio.getMusic()->getStatus() != sf::SoundSource::Playing) {
				audio.playMusicbyName("GameTrack");
				audio.getMusic()->play();
				audio.getMusic()->setVolume(ScreenMMenu.getMusicLevel() * 25);
			}
		}
		if (input->isKeyDown(sf::Keyboard::Enter)) {
			gameSetup();
			ScreenGameOver.reset();
			audio.playSoundbyName("click");
			audio.playMusicbyName("GameTrack");
			audio.getMusic()->setVolume(ScreenMMenu.getMusicLevel() * 25);
		}
	break;

	case(State::UPGRADE) :
		if (input->isKeyDown(sf::Keyboard::Num1)) {
			Player.maxhealthupgrade();
			gamestate.setCurrentState(State::LEVEL);
		}
		else if(input->isKeyDown(sf::Keyboard::Num2)) {
			Player.addDamage(25);
			//resets bullet origin, enlarges it and makes a new collision box
			Bulletmanager.get_playerbullet_example()->setOrigin(-Bulletmanager.get_playerbullet_example()->getSize().x / 2, -Bulletmanager.get_playerbullet_example()->getSize().y / 2);
			Bulletmanager.get_playerbullet_example()->setSize(sf::Vector2f(Bulletmanager.get_playerbullet_example()->getSize().x + 15, Bulletmanager.get_playerbullet_example()->getSize().y + 7));
			Bulletmanager.get_playerbullet_example()->setOrigin(Bulletmanager.get_playerbullet_example()->getSize().x / 2, Bulletmanager.get_playerbullet_example()->getSize().y / 2);
			Bulletmanager.get_playerbullet_example()->setCollisionBox(-Bulletmanager.get_playerbullet_example()->getSize().x / 2, -Bulletmanager.get_playerbullet_example()->getSize().y / 2, Bulletmanager.get_playerbullet_example()->getSize().x, Bulletmanager.get_playerbullet_example()->getSize().y);
			gamestate.setCurrentState(State::LEVEL);
		}
		else if (input->isKeyDown(sf::Keyboard::Num3)) {
			Player.attackspeedupgrade();
			gamestate.setCurrentState(State::LEVEL);
		}
		else if (input->isKeyDown(sf::Keyboard::Num4)) {
			Player.addMultshot();
			gamestate.setCurrentState(State::LEVEL);
		}
	}
}

// Update game objects
void Level::update(float dt)
{	
	switch (gamestate.getCurrentState())
	{
	case (State::LEVEL) :
		collman.checkcollisions(&entitymanager, &Bulletmanager, &Player,&gamestate,&audio);
		if (gameclock.getElapsedTime().asMilliseconds() > 5000 && entitymanager.isAllDead()) {
			gameclock.restart();
			if(waveLvl%3 != 0 && !entitymanager.get_Boss()->isAlive()){ entitymanager.spawnWave(window, pow(scaledifficulty,waveLvl)); waveLvl++;}
			else if (!entitymanager.get_Boss()->isAlive()) { audio.stopAllMusic(); audio.playMusicbyName("BossTrack"); audio.getMusic()->setVolume(ScreenMMenu.getMusicLevel() * 25); entitymanager.spawnMusk(window, waveLvl / 3); waveLvl++; }
		}
		Player.update(dt);
		StarrySky.starUpdate(window, dt);
		Bulletmanager.spawnBullets(&entitymanager,&Player,&audio);
		Bulletmanager.update(dt, window);
		entitymanager.updateAllEntities(dt, &Player,window);
		collman.updateExplosions(dt);
	break;

	case(State::MENU) :
		StarrySky.starUpdate(window, dt);
		ScreenMMenu.Screen_MMenu_Update(dt);
	break;

	case(State::GAMEOVER) :
		if (!statesetup) {
			audio.stopAllSounds();
			statesetup = true;
			audio.playSoundbyName("losing");
		}
		collman.updateExplosions(dt);
		ScreenGameOver.Screen_GameOver_Update(dt);
	break;

	case(State::UPGRADE) :
		ScreenUpgrade.Upgrade_Screen_Update(dt);
	break;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	switch (gamestate.getCurrentState())
	{
	case (State::LEVEL) :
		drawEverything(window);
	break;
	
	case (State::MENU) :
		StarrySky.starRender(window);
		ScreenMMenu.Screen_MMenu_Render(window);
	break;

	case (State::PAUSE) :
		drawEverything(window);
		
		window->draw(pausefilter);
		window->draw(text);
		window->draw(text2);
	break;

	case(State::GAMEOVER) :
		drawEverything(window);

		ScreenGameOver.Screen_GameOver_Render(window);
	break;

	case(State::UPGRADE) :
		drawEverything(window);
		
		window->draw(pausefilter);
		ScreenUpgrade.Upgrade_Screen_Render(window);
	break;
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}