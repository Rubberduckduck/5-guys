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
		data->stateManager.AddState(stateRef(new splashScreen(this->data)));

		this->run();
	}

	void gameLoop::run()
	{
		float newTime{}, frameRate{}, interpolation{};

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
			frameRate = newTime - currentTime;

			// Prevent frame rate from going too high
			if (frameRate > 0.60f)
			{
				frameRate = 0.60f;
			}

			currentTime = newTime;
			accumulatedTime += frameRate;
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
			this->data->stateManager.GetActiveState()->Draw(interpolation);
		}

		// When sf::event::closed, unique and shared ptrs are not cleared properly, hence the 
		// free function call to clear and reset the smart ptrs
		free();
	}

	void gameLoop::free()
	{
		data->stateManager.FreeStates();
	}


}