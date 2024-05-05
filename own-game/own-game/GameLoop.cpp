#include "pch.hpp"
#include "GameLoop.hpp"
#include "SplashScreen.hpp"

namespace ownProject 
{
	gameLoop::gameLoop(int windowHeight, int windowWidth, std::string windowTitle) 
	{
		// Param sf::style::close and sf::style::titlebar is to tell sfml that 
		// i wan the window to have a close and title bar
		data->window.create(sf::VideoMode(windowWidth, windowHeight), 
			windowTitle, sf::Style::Close | sf::Style::Titlebar);
		data->stateManager.AddState(stateRef(new SplashScreen(this->data)));

		this->run();
	}

	void gameLoop::run()
	{
		float newTime{}, frameTime{}, interpolation{};

		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulatedTime = 0.f;

		/******************************************************************
		* MAIN LOOP
		*******************************************************************/
		while (this->data->window.isOpen())
		{
			// First thing, update GS (game states)
			this->data->stateManager.UpdateStates();

			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
		
			// Prevent frame time from going too high
			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulatedTime += frameTime;
			while (accumulatedTime >= deltaTime)
			{
				this->data->stateManager.GetActiveState()->HandleInput();
				this->data->stateManager.GetActiveState()->Update(deltaTime);

				accumulatedTime -= deltaTime;
			}
			/*
			* EXPLANATION FROM MR GPT
			* Interpolation Calculation:
				Interpolation is calculated as the ratio of accumulatedTime to deltaTime. This ratio represents how far along the current frame is between updates.
				Interpolation is commonly used in game rendering to smoothly animate objects or transitions between frames, especially when frame rates vary.
				By using interpolation, visual artifacts such as jittery motion or sudden changes in position can be reduced, resulting in smoother and more visually appealing graphics.
			* 
			* Drawing with Interpolation:
				Finally, the active game state's draw function is called, passing the interpolation value as a parameter. 
				This allows the rendering code to adjust the position, rotation,
				or other properties of game objects based on the current interpolation value, ensuring smooth rendering between frames.
			*/
			interpolation = accumulatedTime / deltaTime;
			this->data->stateManager.GetActiveState()->draw(interpolation);
		}

	}


}