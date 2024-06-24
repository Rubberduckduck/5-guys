#pragma once

#define SPLASHSCREEN
#ifdef SPLASHSCREEN

#include "pch.hpp"
#include "state.hpp"
#include "GameLoop.hpp"


namespace ownProject {
	class splashScreen : public state
	{
	public:
		splashScreen(gameDataRef paramData);

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

		// For rendering texture
		sf::Texture splashTexture;
		sf::Sprite splashSprite;
	};
}




#endif