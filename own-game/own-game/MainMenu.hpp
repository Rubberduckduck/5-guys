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
		void Load();
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void Free();
		void Unload();

	private:
		gameDataRef data;
		sf::Clock clock;
		sf::Mouse mouse;

		// For rendering texture
		sf::Texture mainMenuTexture;
		sf::Sprite mainMenuSprite;

		// For button texture and sprite
		sf::Texture mainMenuBtnTexture;
		sf::Sprite mainMenuBtnSprite;

		// For rendering text
		sf::Text mainMenuBtnText;
	};
}




#endif