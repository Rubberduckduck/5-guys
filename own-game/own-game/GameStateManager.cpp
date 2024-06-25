#include "pch.hpp"
#include "GameStateManager.hpp"

namespace ownProject {

	gameStateType current = GS_SplashScreen;
	gameStateType next = GS_SplashScreen;
	gameStateType previous = GS_SplashScreen;

	stateManager::stateManager()
	{
		current = previous = next = GS_SplashScreen;
	}

	void stateManager::AddState(stateRef newState, bool isReplacing)
	{
		this->isAdded = true;
		this->isReplaced = isReplacing;


		// Std::move transfer ownership of param newState to the game manager stack 
		this->state = std::move(newState);
	}
	void stateManager::RemoveState()
	{
		this->isRemoved = true;
		// Handle changes under updateStates
	}
	void stateManager::UpdateStates()
	{

		// Handling removing of state
		if (this->isRemoved && !this->GameStates.empty()) {
			// Remove state
			this->GetActiveState()->Free();
			if (next != GS_Restart)
			{
				this->GetActiveState()->Unload();
			}
			this->GameStates.pop();
			// Check if there are any states left
			if (!this->GameStates.empty())
			{
				this->GameStates.top()->Resume();
			}
			// Rmb set back to false after removing
			this->isReplaced = false;
		}

		// Hanlding of adding state
		if (this->isAdded)
		{
			if (!this->GameStates.empty())
			{
				// Replace current state
				if (this->isReplaced) {
					// Remove current state
					this->GetActiveState()->Free();
					if (next != GS_Restart)
					{
						this->GetActiveState()->Unload();
					}
					this->GameStates.pop();
				}
				// Dont do anyth
				else {
					this->GameStates.top()->Pause();
				}
			}
			// Add state to GameStates
			this->GameStates.push(std::move(this->state));
			if (current == GS_Restart)
			{
				current = previous;
				next = previous;
			}
			else {
				// First thing, update GS (game states)
				this->GetActiveState()->Load();
			}
			// Call Init here
			this->GetActiveState()->Init();
			this->isAdded = false;
		}
	}

	void stateManager::FreeStates()
	{
		while (!GameStates.empty()) {
			this->GetActiveState()->Free();
			this->GetActiveState()->Unload();
			GameStates.pop(); 
		}
	}
	stateRef& stateManager::GetActiveState()
	{
		return this->GameStates.top();
	}


}

