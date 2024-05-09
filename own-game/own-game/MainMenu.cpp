#include "pch.hpp"
#include "MainMenu.hpp"
#include "Defines.hpp"
#include "Utils.hpp"

namespace ownProject {

	std::unique_ptr<buttonPopUp> mainMenuBtns = std::make_unique<buttonPopUp>(); 

	mainMenu::mainMenu(gameDataRef paramData) : data{paramData} {}

	void mainMenu::Init()
	{
		// To load texture and set texture to the sprite using std::string
		data->assetManager.LoadTexture("mainMenu button texture", MAIN_MENU_BUTTON_TEXTURE);
		mainMenuBtnSprite.setTexture(this->data->assetManager.GetTexture("mainMenu button texture"));
		// To set image origin to center of sprite, SFML default is top left
		mainMenuBtnSprite.setOrigin(setSpriteOrigin(mainMenuBtnSprite.getLocalBounds()));


		// Init buttons
		sf::Vector2f startingButton{ 800.f,450.f };
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y, "FIREWORKS (WIP)");
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y + 100.f, "SAND (NOT STARTED)");
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y + 150.f, "WATER (NOT STARTED)");
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y + 200.f, "QUIT");
	}

	void mainMenu::HandleInput()
	{
		sf::Event event;

		// SFML Style, to handle input using sf::event

		while (data->window.pollEvent(event))
		{
			// To close window properly, without this if statement, window does not close properly
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
		}
	}

	void mainMenu::Update(float dt)
	{
		static_cast<void>(dt);

	}

	void mainMenu::Draw(float dt)
	{
		static_cast<void>(dt);
		mainMenuBtns->draw(data->window, mainMenuBtnSprite);
	}


}

