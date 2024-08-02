#pragma once

#include "pch.hpp"
#include "GameStateManager.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

#ifndef GAMELOOP
#define GAMELOOP

namespace ownProject {
	
	// All manager main instance all go here!
	struct gameData 
	{
		stateManager stateManager;
		// To render the window
		sf::RenderWindow window;
		assetManager assetManager;
		inputManager inputManager;
	};

	// SOME NOTES OF UNIQUE PTR AND SHARED PTR: 
	/*
	- Use unique_ptr when you want a single pointer to an object that will be reclaimed when that single pointer is destroyed.
	- Use shared_ptr when you want multiple pointers to the same resource.
	*/

	typedef std::shared_ptr<gameData> gameDataRef;

	class gameLoop 
	{
	public:
		gameLoop(int windowHeight, int windowWidth, std::string windowTitle);


	private:
		const float deltaTime = 1.f / 60.f;
		// To handle dt
		sf::Clock clock;

		// Make shared is to create an shared ptr instance
		gameDataRef data = std::make_shared<gameData>();

		void run();
		void free();
	};

}

#endif // GAMELOOP
