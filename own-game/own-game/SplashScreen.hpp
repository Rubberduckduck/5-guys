#pragma once

#define SPLASHSCREEN
#ifdef SPLASHSCREEN

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"


namespace ownProject {
	class SplashScreen : public state
	{
	public:
		SplashScreen(gameDataRef paramData);

		// State functions
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataRef data;
		sf::Clock clock;

		// For rendering texture
		sf::Texture splashTexture;
		sf::Sprite splashSprite;
	};
}




#endif