#pragma once

#define FIREWORKS
#ifdef FIREWORKS

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"


namespace ownProject {
	class fireworks : public state
	{
	public:
		fireworks(gameDataRef paramData);

		// State functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

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