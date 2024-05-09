#pragma once

#define SPLASHSCREEN
#ifdef SPLASHSCREEN

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"


namespace ownProject {
	class mainMenu : public state
	{
	public:
		mainMenu(gameDataRef paramData);

		// State functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataRef data;
		sf::Clock clock;

		// For rendering texture
		sf::Texture mainMenuTexture;
		sf::Sprite mainMenuSprite;

		// For button texture and sprite
		sf::Texture mainMenuBtnTexture;
		sf::Sprite mainMenuBtnSprite;
	};
}




#endif