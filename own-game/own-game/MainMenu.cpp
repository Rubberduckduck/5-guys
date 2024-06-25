#include "pch.hpp"
#include "MainMenu.hpp"
#include "Defines.hpp"
#include "Utils.hpp"

namespace ownProject {

	std::unique_ptr<buttonPopUp> mainMenuBtns = std::make_unique<buttonPopUp>(); 

	mainMenu::mainMenu(gameDataRef paramData) : data{paramData} {}

	void mainMenu::Load()
	{
	}

	void mainMenu::Init()
	{
		// To load texture and set texture to the sprite using std::string
		data->assetManager.LoadTexture("mainMenu button texture", MAIN_MENU_BUTTON_TEXTURE);
		mainMenuBtnSprite.setTexture(this->data->assetManager.GetTexture("mainMenu button texture"));
		// To set image origin to center of sprite, SFML default is top left
		mainMenuBtnSprite.setOrigin(setSpriteOrigin(mainMenuBtnSprite.getGlobalBounds()));

		// Set font
		mainMenuBtnText.setFont(this->data->assetManager.GetFont("UI font"));
		// Set text origin
		mainMenuBtnText.setOrigin(setSpriteOrigin(mainMenuBtnSprite.getGlobalBounds()));


		// Init buttons
		sf::Vector2f startingButton{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 5 };
		float buttonMargin = WINDOW_HEIGHT / 6;
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y, "FIREWORKS (WIP)", TYPE_FIREWORKS, mainMenuBtnSprite);
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y + buttonMargin , "SAND (NOT STARTED)", TYPE_SAND, mainMenuBtnSprite);
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y + buttonMargin * 2, "WATER (NOT STARTED)", TYPE_WATER, mainMenuBtnSprite);
		mainMenuBtns->addButton(BUTTON_SCALE, startingButton.x, startingButton.y + buttonMargin * 3, "QUIT", TYPE_QUIT, mainMenuBtnSprite);
	}

	void mainMenu::HandleInput()
	{

		sf::Event event;
		sf::Keyboard keyboard;

		// SFML Style, to handle input using sf::event

		while (data->window.pollEvent(event))
		{
			// To close window properly, without this if statement, window does not close properly
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
			if (keyboard.isKeyPressed(sf::Keyboard::Escape))
			{
				data->window.close();
			}
		}
	}

	void mainMenu::Update(float dt)
	{

		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);

		mainMenuBtns->buttonUpdate(mouse, data);

	}

	void mainMenu::Draw(float dt)
	{

		// This is same as UNREFERENCED_PARAMETER
		static_cast<void>(dt);
		mainMenuBtns->draw(data->window, mainMenuBtnText);
	}

	void mainMenu::Free()
	{
	}

	void mainMenu::Unload()
	{
	}
}

